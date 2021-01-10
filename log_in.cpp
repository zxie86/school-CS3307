#include "log_in.h"
#include "ui_log_in.h"
#include "smtp.h"
#include <iostream>
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
/**
 * @brief Log_in.cpp is used for all user choices, to Display Map, or change Reciever/Pwd/Email/Restricted Are
 *  Code is executed only when respected buttons are pushed
 * 
 *@author Oleksiy Kovtonyuk
 */
Log_IN::Log_IN(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Log_IN)
{
    ui->setupUi(this);

}

Log_IN::~Log_IN()
{
    delete ui;
}

/**
 * @brief setter for user Login
 * @param kek -> QString of user login
 */
void Log_IN::set_Log(QString kek){
    this->User_Log = kek;
}

/**
 * @brief setter for user Pwd
 * @param kek -> QString of user Pwd
 */
void Log_IN::set_Pwd(QString kek){
    this->User_Pwd = kek;
}

/**
 * @brief setter for user Reciever 1 coorditantes
 * @param x -> X coordinate of Reciever
 * @param y -> y coordinate of Reciever
 */
void Log_IN::set_R1(int x, int y){
    this->R_1.setX(x);
    this->R_1.setY(y);
}

/**
 * @brief setter for user Reciever 2 coorditantes
 * @param x -> X coordinate of Reciever
 * @param y -> y coordinate of Reciever
 */
void Log_IN::set_R2(int x, int y){
    this->R_2.setX(x);
    this->R_2.setY(y);
}

/**
 * @brief setter for user Reciever 3 coorditantes
 * @param x -> X coordinate of Reciever
 * @param y -> y coordinate of Reciever
 */
void Log_IN::set_R3(int x, int y){
    this->R_3.setX(x);
    this->R_3.setY(y);
}

/**
 * @brief setter for user room boundaries, Edge
 * @param x -> X coordinate of Edge
 * @param y -> y coordinate of Edge
 */
void Log_IN::set_E(int x, int y){
    this->E.setX(x);
    this->E.setY(y);
}

/**
 * @brief setter for user email adress, Email
 * @param data -> QString user email
 *
 */
void Log_IN::set_Email(QString data){

    this->Email = data;

}

/**
 * @brief Getter for user Email
 * @return User Email
 */
QString Log_IN::get_Email(){

    return Email;

}

/**
 * @brief setter for user restricted area Left Upper coordinate, Restrict_1
 * @param x -> X coordinate of Restrict_1
 * @param y -> y coordinate of Restrict_1
 */
void Log_IN::set_Restrict_1(int x, int y){
    this->Restrict_1.setX(x);
    this->Restrict_1.setY(y);
}

/**
 * @brief setter for user restricted area Left Upper coordinate, Restrict_2
 * @param x -> X coordinate of Restrict_2
 * @param y -> y coordinate of Restrict_2
 */
void Log_IN::set_Restrict_2(int x, int y){
    this->Restrict_2.setX(x);
    this->Restrict_2.setY(y);
}

/**
 * @brief Is called from main to initialize local variables (User_Log, User_Pwd, coordinates of Recievers, Edges of the room and Restricted area)
 * @param array passed from mainwindow stores all required data
 */
void Log_IN::progress(QString user_data[]){

    //Delimeter is used to define "," symbol which separates the string
    std::string delimiter = ",";
    int count = 0;
    //Two storeage arrays are used to store splited array of QString type
    QString* store;
    QString* store2;
    QString* store3;
    QString store_1 [6] ={""};
    QString store_2 [2] ={""};
    QString store_3 [4] ={""};

    QMessageBox msgBox;

    //Sets current user Pwd and Log data
    set_Log(user_data[0]);
    set_Pwd(user_data[1]);

    store = converter(user_data[2], delimiter,  store_1, count);

    store2 = converter(user_data[3], delimiter,  store_2, count);

    store3 = converter(user_data[5], delimiter,  store_3, count);

    //Setters methods that create local variables ot type Location
    set_E(store2[0].toInt(), store2[1].toInt());

    set_R1(store[0].toInt(), store[1].toInt());

    set_R2(store[2].toInt(), store[3].toInt());

    set_R3(store[4].toInt(), store[5].toInt());

    set_Email(user_data[4]);

    set_Restrict_1(store3[0].toInt(), store3[1].toInt());

    set_Restrict_2(store3[2].toInt(), store3[3].toInt());


}

/**
 * @brief Checks if PWD is correct for said user, returns true if corect pwd
 * @param LOG -> User Login
 * @param PWd -> User Pwd
 * @param text_file -> Txt file from which to read
 */
bool Log_IN::Pwd_Checker(QString LOG ,QString PWd, QString text_file){

    QFile file("info.txt");

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
            return false;
    QTextStream in(&file);
    QString line = in.readLine();
    while (!line.isNull()) {
        if (line == LOG){

            line = in.readLine();
            if(line == PWd){
                QMessageBox msgBox;
                msgBox.setText("Corect PWD");
                msgBox.exec();
                return true;
            }

        }
        line = in.readLine();
    }


}


/**
 * @brief Converts passed coma separated string into QString array
 * @param data_string -> Coma separated string
 * @param separator -> Represents separator of QString, "," in our case
 * @param result_data_string -> Array that will be return array of QString without commas
 * @param counter -> counts through every run of a while loop to know into which cell to store
 * @return returns pointer to array in which string in array form is stored
 */
QString* Log_IN::converter(QString data_string, std::string separator, QString result_data_string[],int counter){


    std::string E_data = data_string.toLocal8Bit().constData();

    size_t position = 0;
    std::string Tk;
    while ((position = E_data.find(separator)) != std::string::npos) {
        Tk = E_data.substr(0, position);
        result_data_string[counter] = QString::fromStdString(Tk);
        counter += 1;
        E_data.erase(0, position + separator.length());
    }

    return (result_data_string);


}

/**
 * @brief Replaces the old QString with New QString in info.txt file
 * @param Old -> Old string to be replaced
 * @param New -> New string to be replaced
 *
 */
void Log_IN::replacer(QString Old ,QString New){

    std::ostringstream Buffer;
    ifstream in_file("info.txt");
    Buffer << in_file.rdbuf();
    string str = Buffer.str();
    size_t pos = str.find(Old.toLocal8Bit().constData());
    str.replace(pos, string(Old.toLocal8Bit().constData()).length(), New.toLocal8Bit().constData());
    in_file.close();
    ofstream out_file("info.txt");
    out_file << str;


}

/**
 * @brief Button to change chosen reciever coordinates based on specified boundaries and valid input
 *
 */
void Log_IN::on_pushButton_clicked()
{
    //Creates a string that mimics current string in txt file with old coordinates
    int trig = 0;
    QString old = QString::number(R_1.getX())+"," + QString::number(R_1.getY())+"," + QString::number(R_2.getX())+"," + QString::number(R_2.getY())+"," + QString::number(R_3.getX())+"," + QString::number(R_3.getY())+",";
    QString NeW = "";
    QMessageBox msgBox2;
    msgBox2.setText("Current coordinates are: " + old);
    msgBox2.exec();
    bool ok;
    //Will run untill user exits or enter valied data
    while(trig != 1){

        msgBox2.setText("Current boundaries are X: " + QString::number(E.getX()) + " Y: " +QString::number(E.getY()));
        msgBox2.exec();

        //Checks for valid input
        int R_ID = QInputDialog :: getInt(this, "Hello user, plese enter Rec. ID", "Rec. ID (1,2,3)", 1, 1, 3, 1,&ok);

        if (!ok){
            msgBox2.setText("Nothing changed");
            msgBox2.exec();
            break;
        }

        //if user have entered valid data, and haven't chosen to exit, this section will be executed      
            int data_XY [2] = {0, 0};
            //Ask for new coordinates
            data_XY[0] = QInputDialog :: getInt(this, "New X coordinate", "X:->", 0, 0, E.getX(), 1,&ok);
            if (!ok){
                msgBox2.setText("No changes were made");
                msgBox2.exec();
                break;
            }
            data_XY[1] = QInputDialog :: getInt(this, "New Y coordinate", "Y:->", 0, 0, E.getY(), 1,&ok);
            if (!ok){
                msgBox2.setText("No changes were made");
                msgBox2.exec();
                break;
            }

            else{
                //If they are in boundaries set such ID new coordinates
                if (R_ID == 1)
                    set_R1(data_XY[0],data_XY[1]);
                if (R_ID == 2)
                    set_R2(data_XY[0],data_XY[1]);
                if (R_ID == 3)
                    set_R3(data_XY[0],data_XY[1]);

                //Create a new string to replace previous coordinates
                NeW = QString::number(R_1.getX())+"," + QString::number(R_1.getY())+"," + QString::number(R_2.getX())+"," + QString::number(R_2.getY())+"," + QString::number(R_3.getX())+"," + QString::number(R_3.getY())+",";
                trig = 1;
            }

    }
    //If user properly entered data, now we must store changes into txt file
    if (trig == 1){

        replacer(old, NeW);

        msgBox2.setText("Thank you, coordinates successfully changed");
        msgBox2.exec();

    }
}

/**
 * @brief Button to change current PWD, checks for valid current PWD and New Pwd
 *
 */
void Log_IN::on_pushButton_2_clicked()
{
    bool ok;
    QMessageBox msgBox1;
    //Ask user for his curent pwd
    QString old_p = QInputDialog :: getText(this, "Hello user, plese enter your curent PWD", "PWD:->",QLineEdit::Normal, "Old PW here", &ok);

    if (ok){

    //Check if it's valid
    bool check = Pwd_Checker(User_Log, old_p, "sdgsav");

    if (check == true){
        //If ok ask for a new one
        QString  new_p = QInputDialog :: getText(this, "Curent PWD -> OK", "New PWD:->",QLineEdit::Normal, "New PW here", &ok);

        if (!ok){
            msgBox1.setText("No changes were made");
            msgBox1.exec();
            return;
        }

        if (new_p == 0){
            msgBox1.setText("Please enter something valid");
            msgBox1.exec();
        }

        //Look for pwd in a txt file and replace it with new PWD
        else{
            replacer(old_p, new_p);

            msgBox1.setText("PWD changed successfully");
            msgBox1.exec();
        }
    }

    else{
        QString testing = "Curent PWD -> Fail, try again";
        msgBox1.setText(testing);
        msgBox1.exec();
    }

    }

}

/**
 * @brief Button to display current Reciever posittions
 *
 */
void Log_IN::on_pushButton_4_clicked()
{
    QMessageBox msgBox2;
    bool ok;
    bool trig = false;
    //Run untill valid data inserted
    while(!trig){

        int R_ID = QInputDialog :: getInt(this, tr("Recievers"), tr("Reciever ID (1,2,3):->"), 1, 1, 3, 1,&ok);

        if (!ok){
             msgBox2.setText("No data changed");
             msgBox2.exec();
        }

            if (R_ID == 1){
                msgBox2.setText("1st Reciever X: " + QString::number(R_1.getX()) + " Y: " + QString::number(R_1.getY()));
            }
            if (R_ID == 2){
                msgBox2.setText("2nd Reciever X: " + QString::number(R_2.getX()) + " Y: " + QString::number(R_2.getY()));
            }
            if (R_ID == 3){
                msgBox2.setText("3rd Reciever X: " + QString::number(R_3.getX()) + " Y: " + QString::number(R_3.getY()));
            }
            trig = true;

    }

    msgBox2.exec();
}


/**
 * @brief Button to display map
 *
 */
void Log_IN::on_pushButton_3_clicked()
{

    Map *Mapo = new Map();

    //Calls a function inside map.cpp to initialaize Location variables
    //fir Recievers, Boundaries and Restricted area
    Mapo->setReceiver1(R_1);
    Mapo->setReceiver2(R_2);
    Mapo->setReceiver3(R_3);
    Mapo->setEdge(E);
    Mapo->setRestriction1(Restrict_1);
    Mapo->setRestriction2(Restrict_2);
    Mapo->progress2();
    if(Mapo->outOfBound())
    {
        QMessageBox msgBox2;
        msgBox2.setText("Out of Bound");
        msgBox2.exec();
        //call send main utility
        int store[2]={0,0};
        store[0] = Mapo->getBeaconX();
        store[1] = Mapo->getBeaconY();
        EmailNotification(store);

    }

    //finally opens 3rd window
    Mapo->show();
    //}

}

QString Log_IN::EmailNotification(int data[]){

    QString msg="";

    time_t now = time(0);
    char* dt = ctime(&now);
    QMessageBox msgBox2;

    msg = "Hello " + User_Log + ", tracked beacon left specified boundaries at time " + dt + " at coordinates X:" + QString::number(data[0]) + " Y:" + QString::number(data[1]);
    msgBox2.setText(msg);
    msgBox2.exec();

    Smtp* smtp = new Smtp("trackfieldgroup8@gmail.com", "group8trackfield", "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));
    smtp->sendMail("trackfieldgroup8@gmail.com", Email , "Out of Bounds Alert", "The beacon is out of bounds");

    return "";
}

/**
 * @brief Button to close current window
 *
 */
void Log_IN::on_pushButton_6_clicked()
{
    QMessageBox msgBox2;
    msgBox2.setText("Logging out");
    msgBox2.exec();
    close();
}

/**
 * @brief Button to change users Email adress, checks for valid input
 *
 */
void Log_IN::on_pushButton_5_clicked()
{

    int trig = 0;
    QString Em_N = "", Em_O = "";
    QMessageBox msgBox;
    bool ok;
    //Run untill exit is sellected or valid input
    while (trig != 1 && trig != 2){

        Em_O = QInputDialog :: getText(this, "Hello user, plese enter your Email", "Previous Email:",QLineEdit::Normal, "Your Old Email", &ok);

        if (!ok){
            trig = 2;
            break;
        }

        QFile file("info.txt");

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                return;
        //OPen file, find user Login, check if inputed login is same as stored
        QTextStream in(&file);
        QString line = in.readLine();
        while (!line.isNull()) {
            if (line == User_Log){

                //If LOgin match, skip through rest of the data
                line = in.readLine();
                line = in.readLine();
                line = in.readLine();
                line = in.readLine();

                //If correct ask for new one
                if(line == Em_O){

                    msgBox.setText("Corect Email");
                    msgBox.exec();
                    Em_N = QInputDialog :: getText(this, "Hello user, plese enter your New Email", "New Email:",QLineEdit::Normal, "Your Email Here", &ok);

                    if (!ok){
                        trig = 2;
                        break;

                    }

                    //Wait for valid input
                    if (Em_N == 0){
                        msgBox.setText("Please enter something");
                        msgBox.exec();
                        trig = 2;
                    }
                    else{
                        trig = 1;
                        break;
                    }
                }

                //If incorect Eail exit
                else {

                    msgBox.setText("Incorrect Email, try again");
                    msgBox.exec();
                   // trig = 2;
                }

            }
            line = in.readLine();
        }

        //IF correct email was typed, replace old email with new one
        if (trig == 1){

            replacer(Em_O, Em_N);
            msgBox.setText("Email replced");
            msgBox.exec();
        }

        //Else declare that nothing changed
        if (trig == 2){
            msgBox.setText("Email not changed");
            msgBox.exec();
        }

    }

}

/**
 * @brief Button to change Restricted areas for user, checks for valid input
 *
 */
void Log_IN::on_pushButton_7_clicked()
{
    int trig = 0;
    //Create a representation of old QString line
    QString old = QString::number(Restrict_1.getX())+"," + QString::number(Restrict_1.getY())+"," + QString::number(Restrict_2.getX())+"," + QString::number(Restrict_2.getY())+",";
    QString New = "";
    QMessageBox msgBox2;
    msgBox2.setText("Current restriction area is: X1: " + QString::number(Restrict_1.getX()) + " Y1: " + QString::number(Restrict_1.getY()) + " X2: " + QString::number(Restrict_2.getX()) + " Y2: " + QString::number(Restrict_2.getY()));
    msgBox2.exec();
    bool ok;

    //Will run untill user exits or enter valied data
    while(trig != 1){
        bool validInput = true;
        //Checks for valid input
        int R_ID = QInputDialog :: getInt(this, "Hello user, plese enter Rec. ID", "Left Up - 1 Right bottom - 2 :->", 1, 1, 2, 1,&ok);
        if (!ok){
            msgBox2.setText("No changes were made");
            msgBox2.exec();
            break;
        }
        //if user have entered valid data, and haven't chosen to exit, this section will be executed
        if(validInput){
            int data_Restrict [2] = {0, 0};
            //Ask for new coordinates
            data_Restrict[0] = QInputDialog :: getInt(this, "New X coordinate", "X:->", 1, 0, E.getX(), 1,&ok);
            if (!ok){
                msgBox2.setText("No changes were made");
                msgBox2.exec();
                break;
            }
            data_Restrict[1] = QInputDialog :: getInt(this, "New Y coordinate", "Y:->", 1, 0, E.getY(), 1,&ok);
            if (!ok){
                msgBox2.setText("No changes were made");
                msgBox2.exec();
                break;
            }
            else{
                //If they are in boundaries set such ID new coordinates
                if (R_ID == 1)
                    set_Restrict_1(data_Restrict[0],data_Restrict[1]);
                if (R_ID == 2)
                    set_Restrict_2(data_Restrict[0],data_Restrict[1]);
                New = QString::number(Restrict_1.getX())+"," + QString::number(Restrict_1.getY())+"," + QString::number(Restrict_2.getX())+"," + QString::number(Restrict_2.getY())+",";
                trig = 1;
            }
        }
    }
    //If user properly entered data, now we must store changes into txt file
    if (trig == 1){

        replacer(old, New);

        msgBox2.setText("Thank you, restricted area successfully changed");
        msgBox2.exec();

    }
}
//Cake is lie
