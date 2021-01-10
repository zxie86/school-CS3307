#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "log_in.h"
/**
 *@brief Main Window heade file
 *
 * 
 *@author Oleksiy Kovtonyuk
 */
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

    //Login
    void on_pushButton_clicked();

    //Exit
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Log_IN *Login;
};
#endif // MAINWINDOW_H
