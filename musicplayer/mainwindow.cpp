#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QPixmap>
#include<QPalette>
#include<QAudioOutput>
#include<QFile>
#include<QDir>
#include<QFileInfo>
#include<QMessageBox>
#include<time.h>
#include<QDebug>
#include<QpropertyAnimation>
#include<QTimer>
#include<QMap>
#include<QRegularExpression>
#include<QTextStream>
#include<QFont>
#include<QScrollBar>
#include<QEvent>

using namespace std;


QString formatTime(qint64 milliseconds);
QMap<qint64,QString>parseLyrics(const QString& filepath);


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_mode(ORDER_MODE),
    m_isShowFlag(false)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->layoutWidget->addAction(LyricsWidget);
    setWindowTitle("音乐播放器");
    m_player = new QMediaPlayer(this);
    setFixedSize(1020,720);
    setbackgroud(":/images/bk0.jpg");
    initButtons();
    ui->lyricslist->installEventFilter(this);
    updateTimer = new QTimer(this);
    connect(updateTimer,&QTimer::timeout,this,&MainWindow::setCurrentTime);

    updateTimer->start(100);
    lastVolume=0.5;
    m_musicDir = "D:\\QTproject\\musicplayer\\musicSet\\";
    m_mly="D:\\QTproject\\musicplayer\\Lyrics\\";
    loadMusicDir(m_musicDir);
    audioOutput=new QAudioOutput(this);
    m_player->setAudioOutput(audioOutput);
    ui->volumeBar->setRange(0,100);
    ui->volumeBar->setValue(50);
    audioOutput->setVolume(0.5);
    musicLy = "D:\\QTproject\\musicplayer\\Lyrics\\jar of love-曲婉婷.lrc";
    m_player->setSource(QUrl::fromLocalFile("D:\\QTproject\\musicplayer\\musicSet\\jar of love-曲婉婷.mp3"));
    srand(time(NULL));
}

//  设置按钮样式
void MainWindow::setbtnStyle(QPushButton* button,const QString& filename)
{
    button->setFixedSize(50,50);     //大小
    button->setIcon(QIcon(filename));    //图标
    button->setStyleSheet("background-color:transparent"); //背景透明
    button->setIconSize(QSize(button->width(),button->height()));
}

//  打开动画
void MainWindow::showAnimation(QWidget* window){
    QPropertyAnimation animation(window,"pos");
    animation.setDuration(500);
    animation.setStartValue(QPoint(this->width(),0));
    animation.setEndValue(QPoint(this->width()-ui->musicList->width(),0));
    animation.start();
    QEventLoop loop;
    connect(&animation,&QPropertyAnimation::finished,&loop,&QEventLoop::quit);
    loop.exec();
}

//  隐藏动画
void MainWindow::hideAnimation(QWidget* window){
    QPropertyAnimation animation(window,"pos");
    animation.setDuration(500);
    animation.setStartValue(QPoint(this->width()-ui->musicList->width(),0));
    animation.setEndValue(QPoint(this->width(),0));
    animation.start();
    QEventLoop loop;
    connect(&animation,&QPropertyAnimation::finished,&loop,&QEventLoop::quit);
    loop.exec();
}

// 播放音乐
void  MainWindow::startPLayMusic(){
    QString musicName = ui->musicList->currentItem()->text();
    musicLy = m_mly+musicName+".lrc";
    QString musicAbsPath= m_musicDir +musicName+".mp3";
    m_player->setSource(QUrl::fromLocalFile(musicAbsPath));
    qDebug() << musicAbsPath;

    handlePlaySlot();
    initlyricsList();

}

//  上一首
void MainWindow::handlePrevSlot(){
    int currentRow = ui->musicList->currentRow();

    int PrevRow=0;
    if(m_mode==ORDER_MODE){
        PrevRow = (currentRow +ui->musicList->count()-1)%ui->musicList->count();
    }
    else if(m_mode==RANDOM_MODE){
        int cnt=0;
        do{
            PrevRow = rand() % ui->musicList->count();
            cnt++;
        }while(currentRow == PrevRow && cnt<=3);

    }
    else if(m_mode==CIRCLDE_MODE){
        PrevRow = currentRow;
    }
    ui->musicList->setCurrentRow(PrevRow);
    flag=1;
    startPLayMusic();
}

//  下一首
void MainWindow::handleNextSlot(){
    int currentRow = ui->musicList->currentRow();

    int nextRow=0;
    if(m_mode==ORDER_MODE){
        nextRow = (currentRow + 1)%ui->musicList->count();
    }
    else if(m_mode==RANDOM_MODE){
        int cnt=0;
        do{
            nextRow = rand() % ui->musicList->count();
            cnt++;
        }while(currentRow == nextRow && cnt<=3);

    }
    else if(m_mode==CIRCLDE_MODE){
        nextRow = currentRow;
    }
    ui->musicList->setCurrentRow(nextRow);
    flag=1;
    startPLayMusic();
}

//   初始化按钮
void MainWindow::initButtons()
{
    ui->bkgbtn->setIcon(QIcon(":/icon1/bkg.png"));
    //ui->bkgbtn->setStyleSheet("background-color:transparent");
    setbtnStyle(ui->prebtn,":/icon1/pre.png");
    setbtnStyle(ui->playbtn,":/icon1/play.png");
    setbtnStyle(ui->nextbtn,":/icon1/next.png");
    setbtnStyle(ui->modelbtn,":/icon1/order.png");
    setbtnStyle(ui->listbtn,":/icon1/list.png");
    setbtnStyle(ui->volumebtn,":/icon1/sound.png");
    ui->musicList->setStyleSheet("QListWidget {"
                                 "border: none;"
                                 "border-radius: 20px;"
                                 "background-color: rgba(255, 255, 0, 0);"
                                 "}"
                                 );
    ui->lyricslist->setStyleSheet("QListWidget {"
                                 "border: none;"
                                 "border-radius: 20px;"
                                 "background-color: rgba(255, 255, 0, 0);"
                                 "}"
                                 );
    ui->musicList->hide();
    QFont font = ui->lyricslist->font();
    font.setFamily("Arial");
    font.setPointSize(12);
    font.setBold(true);
    ui->lyricslist->setFont(font);
    ui->lyricslist->hide();
    connect(ui->playbtn,&QPushButton::clicked,this,&MainWindow::handlePlaySlot);
    connect(ui->modelbtn,&QPushButton::clicked,this,&MainWindow::handleModeSlot);
    connect(ui->nextbtn,&QPushButton::clicked,this,&MainWindow::handleNextSlot);
    connect(ui->prebtn,&QPushButton::clicked,this,&MainWindow::handlePrevSlot);
    connect(ui->listbtn,&QPushButton::clicked,this,&MainWindow::handleListSlot);
    connect(m_player,&QMediaPlayer::positionChanged,this,&MainWindow::handlePositionSlot);
    connect(m_player,&QMediaPlayer::durationChanged,this,&MainWindow::handleDurationSlot);
    connect(ui->progressBar, &QSlider::sliderPressed, this, &MainWindow::onSliderPressed);
    connect(ui->progressBar, &QSlider::sliderReleased, this, &MainWindow::onSliderReleased);
    connect(ui->progressBar, &QSlider::sliderMoved, this, &MainWindow::onSliderMoved);
    connect(ui->musicList, &QListWidget::itemClicked, this, &MainWindow::onItemClicked);
    connect(m_player,&QMediaPlayer::playbackStateChanged,this,&MainWindow::onStateChanged);
    connect(ui->volumeBar,&QSlider::valueChanged,this,&MainWindow::onVolumeChanged);
    connect(ui->volumebtn,&QPushButton::clicked,this,&MainWindow::setMuteVolume);
    connect(ui->lyricsbtn,&QPushButton::clicked,this,&MainWindow::handlelyricsSlot);
    connect(ui->lyricslist->verticalScrollBar(), &QScrollBar::rangeChanged, this, &MainWindow::onScrollRangeChanged);
    connect(ui->lyricslist->verticalScrollBar(), &QScrollBar::valueChanged, this, &MainWindow::onScrollValueChanged);
    connect(ui->lyricslist->verticalScrollBar(), &QScrollBar::actionTriggered, this, &MainWindow::onScrollfinished);
    scrollTimer = new QTimer(this);
    scrollTimer->setSingleShot(true);
    connect(scrollTimer, &QTimer::timeout, this, &MainWindow::onScrollfinished);
    connect(ui->lyricslist, &QListWidget::itemClicked, this, &MainWindow::onLyricsItemClicked);
    connect(ui->bkgbtn,&QPushButton::clicked,this,&MainWindow::bkgSlot);
}

//处理音乐的时间
void MainWindow::handleDurationSlot(qint64 duration){
    ui->progressBar->setRange(0,duration);
    ui->totalTime->setText(formatTime(duration));

}

//  处理音乐的进度
void MainWindow::handlePositionSlot(qint64 pos){
    ui->progressBar->setValue(pos);
    ui->currentTime->setText(formatTime(pos));
}

//  音乐列表
void MainWindow::handleListSlot(){
    if(m_isShowFlag){
        hideAnimation(ui->musicList);
        ui->musicList->hide();
        m_isShowFlag=false;
    }
    else{
        ui->musicList->show();
        showAnimation(ui->musicList);
        m_isShowFlag=true;
    }

}

//加载指定文件夹
void MainWindow::loadMusicDir(const QString& filepath){
    QDir dir(filepath);
    if(dir.exists() == false){
        QMessageBox::warning(this,"文件夹","文件夹打开失败");
        return ;
    }

    //dir.entryInfoList(QDir::Files);
    QFileInfoList fileList = dir.entryInfoList(QDir::Files);
    for(auto element : fileList){
        if(element.suffix() ==  "mp3"){
            ui->musicList->addItem(element.baseName());
        }
    }
    ui->musicList->setCurrentRow(0);
}

// 播放和暂停
void MainWindow::handlePlaySlot(){
    if(m_player->playbackState() == QMediaPlayer::PlayingState){
        m_player->pause();
        ui->playbtn->setIcon(QIcon(":/icon1/play.png"));
    }
    else{
        flag2=1;
        m_player->play();
        ui->playbtn->setIcon(QIcon(":/icon1/stop.png"));
    }
}

// 模式选择
void MainWindow::handleModeSlot(){
    if(m_mode== ORDER_MODE){
        m_mode=RANDOM_MODE;
        ui->modelbtn->setIcon(QIcon(":/icon1/ramdon.png"));
    }
    else if(m_mode== RANDOM_MODE){
        m_mode=CIRCLDE_MODE;
        ui->modelbtn->setIcon(QIcon(":/icon1/cyc.png"));
    }
    else if(m_mode== CIRCLDE_MODE){
        m_mode=ORDER_MODE;
        ui->modelbtn->setIcon(QIcon(":/icon1/order.png"));
    }

}

// 设置背景
void MainWindow::setbackgroud(const QString& filename)
{
    qDebug()<<filename;
    QPixmap pixmap(filename);
    QSize windowSize = this->size();
    QPixmap scalePixmap = pixmap.scaled(windowSize,Qt::IgnoreAspectRatio,Qt::SmoothTransformation);
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window,QBrush(scalePixmap));
    this->setPalette(palette);
}
MainWindow::~MainWindow()
{
    delete ui;
}

// 进度条点击
void MainWindow::onSliderPressed(){
    m_position=ui->progressBar->value();
    m_player->setPosition(m_position);
    m_player->pause();
}

// 进度条鼠标释放
void MainWindow::onSliderReleased()
{
    //m_player->setPosition(m_position);
    if(m_player->playbackState() == QMediaPlayer::PlayingState){
        ui->playbtn->setIcon(QIcon(":/icon1/play.png"));
    }
    else{
        ui->playbtn->setIcon(QIcon(":/icon1/stop.png"));
    }
    m_player->play();
    flag2=1;

}

// 进度条移动
void MainWindow::onSliderMoved(int position){
    m_position=position;
    m_player->setPosition(position);
}

// 列表播放
void MainWindow::onItemClicked(QListWidgetItem *item){
    ui->musicList->addItem(item);
    m_listWidget=item->text();
    QString musicAbsPath=m_musicDir+m_listWidget+".mp3";
    m_player->setSource(QUrl::fromLocalFile(musicAbsPath));
    ui->playbtn->setIcon(QIcon(":/icon1/stop.png"));
    flag=1;
    m_player->play();
    int currentRow = ui->musicList->currentRow();
    if(flag2==1)
    {
        ui->musicList->setCurrentRow(currentRow-1);
        m_listWidget=item->text();
        musicLy = m_mly+m_listWidget+".lrc";
    }
    else
    {
        ui->musicList->setCurrentRow(currentRow);
        m_listWidget=item->text();
        musicLy = m_mly+m_listWidget+".lrc";
    }
    initlyricsList();
    qDebug()<<m_musicDir;
    qDebug()<< musicLy;
}

// 音乐自动播放下一首
void MainWindow::onStateChanged(QMediaPlayer::PlaybackState state){
    if(state==QMediaPlayer::StoppedState&&flag==0){
        int currentRow = ui->musicList->currentRow();

        int nextRow=0;
        if(m_mode==ORDER_MODE){
            nextRow = (currentRow + 1)%ui->musicList->count();
        }
        else if(m_mode==RANDOM_MODE){
            int cnt=0;
            do{
                nextRow = rand() % ui->musicList->count();
                cnt++;
            }while(currentRow == nextRow && cnt<=3);
        }
        else if(m_mode==CIRCLDE_MODE){
            nextRow = currentRow;
        }
        ui->musicList->setCurrentRow(nextRow);
        startPLayMusic();
        qDebug()<<"q";
    }
    flag=0;
}

// 格式化音乐时间
QString formatTime(qint64 milliseconds){
    QTime time(0,0);
    time=time.addMSecs(milliseconds);
    return time.toString("mm:ss");
}

// 调节音量
void MainWindow::onVolumeChanged(int volume){
    float m=(float)volume/100;
    audioOutput->setVolume(m);
    lastVolume=m;
}

// 静音开关
void MainWindow::setMuteVolume(){

    if(audioOutput->volume()==0.0){
        audioOutput->setVolume(lastVolume);
        setbtnStyle(ui->volumebtn,":/icon1/sound.png");
    }

    else{
        audioOutput->setVolume(0.0);
        setbtnStyle(ui->volumebtn,":/icon1/mute.png");
    }
}

// 歌词按钮槽函数
void MainWindow::handlelyricsSlot(){
    initlyricsList();
    setCurrentTime();
    ui->lyricslist->setVisible(!ui->lyricslist->isVisible());
}

// 获取歌词并解析
QMap<qint64,QString> parseLyrics(const QString& filepath){
    QMap<qint64,QString> lyricsMap;
    QFile file(filepath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        qDebug() << "无法打开歌词文件";
         return lyricsMap;
    }
    QTextStream in(&file);
    //in.setCodec("UTF-8");
    QRegularExpression timeRegex(R"(^\[(\d+):(\d+)\.(\d+)\](.*))");
    while(!in.atEnd()){
        QString  line=in.readLine();
        //qDebug()<<line;
        QRegularExpressionMatch match=timeRegex.match(line);
        if(match.hasMatch()){
            int minutes=match.captured(1).toInt();
            int seconds=match.captured(2).toInt();
            int milliseconds=match.captured(3).toInt();
            qint64 timestamp=minutes*60000+seconds*1000+milliseconds;
            QString text=match.captured(4).trimmed();
            lyricsMap.insert(timestamp,text);
        }
    }
    file.close();
    return lyricsMap;
}

// 找到当前进度对应的歌词
void MainWindow::setCurrentTime() {
    currentTime=m_player->position();
    QMap lyMap=parseLyrics(musicLy);
    auto it = lyMap.upperBound(currentTime);
    if(!isUserscroll)
    {
            if (it != lyMap.begin()) {
                --it;
                int currentRow = lyMap.keys().indexOf(it.key());
                if (currentRow >= 0 && currentRow < ui->lyricslist->count()) {
                    for (int i = 0; i < ui->lyricslist->count(); ++i) {
                        QListWidgetItem *item = ui->lyricslist->item(i);
                        item->setForeground(i == currentRow ? Qt::red : Qt::black);
                        item->setFont(i == currentRow ? QFont("Arial", 16, QFont::Bold) : QFont("Arial", 12));
                    }

                    ui->lyricslist->scrollToItem(ui->lyricslist->item(currentRow), QAbstractItemView::PositionAtCenter);
                }
            }
    }
}

// 初始化音乐列表
void MainWindow::initlyricsList(){
    QMap lyMap=parseLyrics(musicLy);
    ui->lyricslist->clear();
    for(auto it=lyMap.begin();it!=lyMap.end();it++){
        ui->lyricslist->addItem(it.value());
    }
}

// 监听控件的范围变化
void MainWindow::onScrollRangeChanged(){
    isUserscroll=false;
}

// 监听用户鼠标滚动
void MainWindow::onScrollValueChanged(){
    if(!isUserscroll){
        isUserscroll=true;
    }
    scrollTimer->start(1000);
}

// 鼠标停止滚动开始自动滚动
void MainWindow::onScrollfinished(){
    isUserscroll=false;
}

// 点击歌词播放对应音乐
void MainWindow::onLyricsItemClicked(QListWidgetItem *item){
    QMap lyMap =parseLyrics(musicLy);
    int row = ui->lyricslist->row(item);
    if (row >= 0 && row < lyMap.size()) {
        auto it = lyMap.begin();
        advance(it, row);
        qint64 timestamp = it.key();
        int position = static_cast<int>(timestamp);
        m_player->setPosition(position);
        m_player->pause();
        handlePlaySlot();
    }
}

void MainWindow::bkgSlot(){
    count=(count+1)%4;
    QString ch=QString(char(count+'0'));
    QString bkgpath=":/images/bk"+ch+".jpg";
    //qDebug()<<bkgpath;
    setbackgroud(bkgpath);
}





