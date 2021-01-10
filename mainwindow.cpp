#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QInputDialog>
#include <iostream>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <string>
/**
 *@brief Window where user has an option to LOgin or to create a new user
 *
 * 
 *@author Oleksiy Kovtonyuk
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


/**
 * @brief Button to Log in into an account
 *
 */
void MainWindow::on_pushButton_clicked()
{
    //Trigger if log_in corect
    int trig = 0;
    //String for login
    QString l;
    //String for PWD
    QString p;
    //Runs untill correct input
    QMessageBox msgBox;
    //Storages for user data
    bool ok;
    bool valid = true;
   QString data_2 ="", data_3 ="", mail = "", restriction = "";
    while (trig != 1) {

         l = QInputDialog :: getText(this, "Hello user, please enter your Log-in", "Log-in:",QLineEdit::Normal, "Log_In", &ok);
         if (!ok){
             msgBox.setText("Good luck next time");
             msgBox.exec();
             valid = false;
             break;

         }
         p = QInputDialog :: getText(this, "Hello user, please enter your Password", "Password:",QLineEdit::Normal, "Password", &ok);
         if (!ok){
             msgBox.setText("Good luck next time");
             msgBox.exec();
             valid = false;
             break;

         }

        if (l == 0 || p == 0 ){

            msgBox.setText("Please, enter valid information");
            msgBox.exec();
        }

        else {

            QFile file("info.txt");

            if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
                    return;

            //Check if user Login is inside TXT file, if yes
            QTextStream in(&file);
            QString line = in.readLine();
            while (!line.isNull()) {
                if (line == l){
                    //Then check for his PWD and
                    line = in.readLine();
                    if(line == p){                       
                        //if it's correct save all of the data into separate storadge QStrings
                        msgBox.setText("Hello user " + l);
                        msgBox.exec();

                        line = in.readLine();
                        data_2 = line;
                        line = in.readLine();
                        data_3 = line;
                        line = in.readLine();
                        mail = line;
                        line = in.readLine();
                        restriction = line;

                        trig = 1;
                    }

                }
                line = in.readLine();
            }

        }
    }
    if (valid){
    //With correct input data creates array storing all of user data
    QString data_1[6] = {l,p,data_2,data_3,mail,restriction};

    //Creates instance of a new window : log_in
    Login = new Log_IN(this);
    //calls a function inside log_in to initialaize user variables
    Login->progress(data_1);
    //finally opens 2nd window
    Login->show();
    }
}

/**
 * @brief EXIT button
 *
 */
void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Thank you for using our app");
    msgBox.exec();
    close();
}

/**
 * @brief Button to create a new user
 *
 */
void MainWindow::on_pushButton_3_clicked()
{

    int trig = 0;
    int x,y;
    bool ok;
    //trig = 1 - user exists
    QMessageBox msgBox;

    QString l,p,Email;

    while (trig != 1) {

        //Ask for all user information
        l = QInputDialog :: getText(this, "Hello user, please enter your Log-in", "New Log-in:",QLineEdit::Normal, "New Log_In", &ok);
        if(!ok){
             msgBox.setText("New user not created");
             msgBox.exec();
             break;
        }
        p = QInputDialog :: getText(this, "Hello user, please enter your Password", "New Password:",QLineEdit::Normal, "New Password", &ok);
        if(!ok){
             msgBox.setText("New user not created");
             msgBox.exec();
             break;
        }
        Email = QInputDialog :: getText(this, "Hello user, please enter your Email", "Email:",QLineEdit::Normal, "Your email", &ok);
        if(!ok){
             msgBox.setText("New user not created");
             msgBox.exec();
             break;
        }

        //Wait for valid input
        if ((l == 0 || p == 0 || Email == 0) || (l == p) || (l == Email) || (Email == p)){
            msgBox.setText("Please, enter valid information");
            msgBox.exec();
        }

        else {

            QFile file("info.txt");

            if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    return;

            //Open file and check if such user exists
            QTextStream in(&file);
            QString line = in.readLine();
            while (!line.isNull()) {
                if (line == l){


                    msgBox.setText("Such user exists, enter new data");
                    msgBox.exec();
                    trig = 1;
                    break;
                }
                line = in.readLine();
            }
            file.close();
            //If such user doesn't exist then we must write this user data into txt file
            if (trig != 1){

                QFile file2("info.txt");
                if (!file2.open(QIODevice::ReadWrite | QIODevice::Text| QIODevice:: Append))
                        return;
                QTextStream append(&file2);

                x = QInputDialog :: getInt(this, "Hello user, please enter Widht of area", "Width (m): ", 1, 1, 10, 1,&ok);
                if(!ok){
                     msgBox.setText("New user not created");
                     msgBox.exec();
                     break;
                }
                y = QInputDialog :: getInt(this, "Hello user, please enter Height of area", "Height (m):", 1, 1, 10, 1,&ok);
                if(!ok){
                     msgBox.setText("New user not created");
                     msgBox.exec();
                     break;
                }

                    //Write all if the information down into txt file in format :
                    //1st line - Login
                    append << l << '\n';
                    //2nd line - PWD
                    append << p << '\n';
                    //3rd line - reciever locations, by deafult are set to the room size
                    append << "0" << "," << "0" << "," << x*100 <<"," << "0" << "," << x*100 << "," << y*100 << "," << "\n";
                    //4th line - Boundaries of the required are
                    append << x*100 << "," << y*100 << "," << "\n";
                    //5th line - User Email
                    append << Email << '\n';
                    //6th line Restricted area, by deafuld set to room boundaries
                    append << "0" << "," << "0" << "," << x*100 << "," << y*100 << "," << "\n";
                    //7th line - Separator between each user
                    append << "----------------------------------------" << '\n';

                    file2.close();
                    trig = 1;

                    msgBox.setText("New user added, welcome " + l);
                    msgBox.exec();


            }
        }
    }
}


