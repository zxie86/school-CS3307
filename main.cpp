#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <iostream>
#include "Location.h"
#include "Beacon.h"
#include "Receiver.h"
#include "LocationCalculator.h"

using namespace std;
/**
 * @brief Main program, Show main window
 * 
 * 
 * @author Zhiqi Xie
 * @param int argc, char *argv[]
 * 
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Receiver r1, r2, r3;
    Beacon beacon;
    Location location1,location2,location3;
    MainWindow m;
    m.show();

    return a.exec();
}


