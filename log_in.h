#ifndef LOG_IN_H
#define LOG_IN_H

#include <QMainWindow>
#include "Location.h"
#include "map.h"
/**
 *@brief log_in header file
 *
 * 
 *@author Oleksiy Kovtonyuk
 */
namespace Ui {
class Log_IN;
}

class Log_IN : public QMainWindow
{
    Q_OBJECT

public:
    explicit Log_IN(QWidget *parent = nullptr);
    ~Log_IN();

    Location R_1;

    Location R_2;

    Location R_3;

    Location E;

    Location Restrict_1;

    Location Restrict_2;

    QString Email;

public slots:

    //Initialize local variables
    void progress(QString[]);

    //Check if pwd is correct
    bool Pwd_Checker(QString, QString, QString);

private slots:

    //Change Reciever Position Button
    void on_pushButton_clicked();

    //Change pwd button
    void on_pushButton_2_clicked();

    //Check current position button
    void on_pushButton_3_clicked();

    //Check current Rec. position button
    void on_pushButton_4_clicked();

    //Setters
    void set_Log(QString);

    void set_Pwd(QString);

    void set_R1(int, int);

    void set_R2(int, int);

    void set_R3(int, int);

    void set_E(int, int);

    void set_Email(QString);

    void set_Restrict_1(int, int);

    void set_Restrict_2(int, int);

    QString get_Email();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void replacer(QString, QString);

    QString* converter(QString, std::string, QString[], int);

    void on_pushButton_7_clicked();


    QString EmailNotification(int[]);

private:

    Ui::Log_IN *ui;

    //Local user data
    QString User_Log;

    QString User_Pwd;

};

#endif // LOG_IN_H
