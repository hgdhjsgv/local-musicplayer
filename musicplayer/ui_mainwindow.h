/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *musicList;
    QPushButton *lyricsbtn;
    QListWidget *lyricslist;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *prebtn;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *playbtn;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *nextbtn;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *modelbtn;
    QSpacerItem *horizontalSpacer;
    QPushButton *listbtn;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *volumebtn;
    QSlider *volumeBar;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *currentTime;
    QSlider *progressBar;
    QLabel *totalTime;
    QPushButton *bkgbtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1020, 720);
        MainWindow->setMinimumSize(QSize(1020, 720));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        musicList = new QListWidget(centralwidget);
        musicList->setObjectName("musicList");
        musicList->setGeometry(QRect(380, 10, 251, 271));
        lyricsbtn = new QPushButton(centralwidget);
        lyricsbtn->setObjectName("lyricsbtn");
        lyricsbtn->setGeometry(QRect(510, 590, 61, 21));
        lyricslist = new QListWidget(centralwidget);
        lyricslist->setObjectName("lyricslist");
        lyricslist->setGeometry(QRect(180, 250, 661, 161));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(100, 620, 541, 56));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        prebtn = new QPushButton(layoutWidget);
        prebtn->setObjectName("prebtn");
        prebtn->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(prebtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        playbtn = new QPushButton(layoutWidget);
        playbtn->setObjectName("playbtn");
        playbtn->setMinimumSize(QSize(20, 30));

        horizontalLayout->addWidget(playbtn);

        horizontalSpacer_3 = new QSpacerItem(38, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        nextbtn = new QPushButton(layoutWidget);
        nextbtn->setObjectName("nextbtn");
        nextbtn->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(nextbtn);

        horizontalSpacer_2 = new QSpacerItem(28, 52, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        modelbtn = new QPushButton(layoutWidget);
        modelbtn->setObjectName("modelbtn");
        modelbtn->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(modelbtn);

        horizontalSpacer = new QSpacerItem(38, 51, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        listbtn = new QPushButton(layoutWidget);
        listbtn->setObjectName("listbtn");
        listbtn->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(listbtn);

        horizontalSpacer_5 = new QSpacerItem(48, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        volumebtn = new QPushButton(layoutWidget);
        volumebtn->setObjectName("volumebtn");
        volumebtn->setMinimumSize(QSize(0, 0));

        horizontalLayout_5->addWidget(volumebtn);

        volumeBar = new QSlider(layoutWidget);
        volumeBar->setObjectName("volumeBar");
        volumeBar->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_5->addWidget(volumeBar);


        horizontalLayout->addLayout(horizontalLayout_5);

        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(110, 590, 391, 21));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        currentTime = new QLabel(layoutWidget1);
        currentTime->setObjectName("currentTime");

        horizontalLayout_2->addWidget(currentTime);

        progressBar = new QSlider(layoutWidget1);
        progressBar->setObjectName("progressBar");
        progressBar->setAutoFillBackground(true);
        progressBar->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(progressBar);

        totalTime = new QLabel(layoutWidget1);
        totalTime->setObjectName("totalTime");

        horizontalLayout_2->addWidget(totalTime);

        bkgbtn = new QPushButton(centralwidget);
        bkgbtn->setObjectName("bkgbtn");
        bkgbtn->setGeometry(QRect(580, 590, 31, 21));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1020, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        lyricsbtn->setText(QCoreApplication::translate("MainWindow", "\346\255\214\350\257\215", nullptr));
        prebtn->setText(QString());
        playbtn->setText(QString());
        nextbtn->setText(QString());
        modelbtn->setText(QString());
        listbtn->setText(QString());
        volumebtn->setText(QString());
        currentTime->setText(QCoreApplication::translate("MainWindow", "00::00", nullptr));
        totalTime->setText(QCoreApplication::translate("MainWindow", "00::00", nullptr));
        bkgbtn->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
