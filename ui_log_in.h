/********************************************************************************
** Form generated from reading UI file 'log_in.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_IN_H
#define UI_LOG_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Log_IN
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Log_IN)
    {
        if (Log_IN->objectName().isEmpty())
            Log_IN->setObjectName(QStringLiteral("Log_IN"));
        Log_IN->resize(830, 598);
        centralwidget = new QWidget(Log_IN);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 290, 181, 71));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(220, 290, 191, 71));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(150, 150, 261, 101));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(430, 150, 261, 101));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(290, 410, 261, 101));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(430, 290, 181, 71));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(630, 290, 181, 71));
        Log_IN->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Log_IN);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 830, 21));
        Log_IN->setMenuBar(menubar);
        statusbar = new QStatusBar(Log_IN);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Log_IN->setStatusBar(statusbar);

        retranslateUi(Log_IN);

        QMetaObject::connectSlotsByName(Log_IN);
    } // setupUi

    void retranslateUi(QMainWindow *Log_IN)
    {
        Log_IN->setWindowTitle(QApplication::translate("Log_IN", "MainWindow", nullptr));
        pushButton->setText(QApplication::translate("Log_IN", "Change Reciever Position", nullptr));
        pushButton_2->setText(QApplication::translate("Log_IN", "Change pwwd", nullptr));
        pushButton_3->setText(QApplication::translate("Log_IN", "Display Map", nullptr));
        pushButton_4->setText(QApplication::translate("Log_IN", "Check current Reciever position", nullptr));
        pushButton_6->setText(QApplication::translate("Log_IN", "EXIT", nullptr));
        pushButton_5->setText(QApplication::translate("Log_IN", "Change Email", nullptr));
        pushButton_7->setText(QApplication::translate("Log_IN", "Add Restricted area", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Log_IN: public Ui_Log_IN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_IN_H
