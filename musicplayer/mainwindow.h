#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QPushButton>
#include <QListWidget>
#include<QTimer>
//#include<QMediaPlaylist>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // 按钮槽函数
    void handlePlaySlot();          // 播放/暂停
    void handlePrevSlot();          // 上一首
    void handleNextSlot();          // 下一首
    void handleModeSlot();          // 播放模式切换
    void handleListSlot();          // 显示/隐藏音乐列表
    void onSliderMoved(int position);  // 进度条拖动处理

    // 媒体信号处理
    void handleDurationSlot(qint64 duration);  // 更新进度条范围
    void handlePositionSlot(qint64 pos);       // 更新进度条当前值
    void onSliderPressed();     //点击进度条
    void onSliderReleased();    //鼠标释放
    void onItemClicked(QListWidgetItem *item);       //获取点击列表时的音乐名称
    void onStateChanged(QMediaPlayer::PlaybackState state);
    void onVolumeChanged(int volume);          // 调节音量
    void setMuteVolume();                      // 设置静音
    void handlelyricsSlot();                   //  歌词按钮
    void onScrollRangeChanged();               // 控件范围变化
    void onScrollValueChanged();               // 控件当前值的变化
    void onScrollfinished();                   // 人为与自动转化
    void onLyricsItemClicked(QListWidgetItem *item);    //列表歌词播放
    void bkgSlot();

private:
    // 枚举定义
    enum PlayMode {
        ORDER_MODE,    // 顺序播放
        RANDOM_MODE,   // 随机播放
        CIRCLDE_MODE   // 单曲循环
    };

    // 成员变量
    Ui::MainWindow *ui;
    QMediaPlayer *m_player;          // 媒体播放器
    QAudioOutput *audioOutput;       // 音频输出
    QString m_musicDir;              // 音乐目录路径
    PlayMode m_mode;                 // 当前播放模式
    bool m_isShowFlag;               // 列表显示状态标志
    int m_position;                  //记录进度条的点击位置
    QString m_listWidget;            //获取list列表中的音乐名称
    int flag=0;                      // 标记是否是人为中断播放
    int flag2=0;                     // 标记是否是最开始未播放的状态
    float lastVolume;
    //LyricsWidget lyricswidget;
    QTimer *updateTimer;             // 歌词更新计时器
    qint64 currentTime=0;
    QString musicLy;                  // 音乐歌词路径
    QString m_mly;                    // 音乐的绝对路径
    bool isUserscroll=false;                // 是否人为滚动
    QTimer *scrollTimer;              //  鼠标滚动停止计时
    int count=0;                      //  背景图标号
    //bool isMouseInList=false;

    // 初始化函数
    void initButtons();              // 初始化按钮样式和信号
    void initSliders();              // 初始化滑块控件（音量/进度）
    void loadMusicDir(const QString &filepath); // 加载音乐目录

    // 辅助功能
    void setbtnStyle(QPushButton *button, const QString &filename); // 设置按钮样式
    void setbackgroud(const QString &filename);                    // 设置背景图片
    void startPLayMusic();                                          // 开始播放当前选中音乐
    void showAnimation(QWidget *window);                            // 显示列表动画
    void hideAnimation(QWidget *window);                            // 隐藏列表动画
    void startUpdating(qint64 startTime = 0);
    void setCurrentTime();                                   // 每次更新歌词对应播放的行
    void initlyricsList();                                   //  初始化歌词列表内容
};


























#endif // MAINWINDOW_H
