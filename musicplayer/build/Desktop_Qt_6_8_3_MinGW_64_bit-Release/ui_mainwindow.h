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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *prebtn;
    QPushButton *playbtn;
    QPushButton *nextbtn;
    QPushButton *modelbtn;
    QPushButton *listbtn;
    QListWidget *musicList;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *currentTime;
    QSlider *progressBar;
    QLabel *totalTime;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(659, 541);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(10, 440, 311, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        prebtn = new QPushButton(layoutWidget);
        prebtn->setObjectName("prebtn");
        prebtn->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(prebtn);

        playbtn = new QPushButton(layoutWidget);
        playbtn->setObjectName("playbtn");
        playbtn->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(playbtn);

        nextbtn = new QPushButton(layoutWidget);
        nextbtn->setObjectName("nextbtn");
        nextbtn->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(nextbtn);

        modelbtn = new QPushButton(layoutWidget);
        modelbtn->setObjectName("modelbtn");
        modelbtn->setMinimumSize(QSize(30, 30));

        horizontalLayout->addWidget(modelbtn);

        listbtn = new QPushButton(layoutWidget);
        listbtn->setObjectName("listbtn");
        listbtn->setMinimumSize(QSize(20, 30));

        horizontalLayout->addWidget(listbtn);

        musicList = new QListWidget(centralwidget);
        musicList->setObjectName("musicList");
        musicList->setGeometry(QRect(390, 100, 251, 271));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName("layoutWidget1");
        layoutWidget1->setGeometry(QRect(10, 410, 311, 26));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        currentTime = new QLabel(layoutWidget1);
        currentTime->setObjectName("currentTime");

        horizontalLayout_2->addWidget(currentTime);

        progressBar = new QSlider(layoutWidget1);
        progressBar->setObjectName("progressBar");
        progressBar->setAutoFillBackground(true);
        progressBar->setOrientation(Qt::Orientation::Horizontal);

        horizontalLayout_2->addWidget(progressBar);


        horizontalLayout_3->addLayout(horizontalLayout_2);

        totalTime = new QLabel(layoutWidget1);
        totalTime->setObjectName("totalTime");

        horizontalLayout_3->addWidget(totalTime);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 659, 18));
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
        prebtn->setText(QString());
        playbtn->setText(QString());
        nextbtn->setText(QString());
        modelbtn->setText(QString());
        listbtn->setText(QString());
        currentTime->setText(QCoreApplication::translate("MainWindow", "00::21", nullptr));
        totalTime->setText(QCoreApplication::translate("MainWindow", "03::11", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
