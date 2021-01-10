/*
 *
 * generate map
 */
#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent *e){

   QPainter painter(this);
   //create a black pen that has solid line and the width is 2.
   QPen beaconpen(Qt::black, 2, Qt::SolidLine);
   painter.setPen(beaconpen);
    painter.drawEllipse(beaconLoc.getX(), beaconLoc.getY(), 10, 10);

    //create a red pen that has solid line and the width is 2.
    QPen receiverpen(Qt::red, 2, Qt::SolidLine);
    painter.setPen(receiverpen);
    painter.drawRect(0,0,300,250);
    //fill color
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawRect(receiver1.getX(),receiver1.getX(),5,5);
    painter.drawRect(receiver2.getX(),receiver2.getX(),5,5);
    painter.drawRect(receiver3.getX(),receiver3.getX(),5,5);

}
void Dialog::setBeacon(Location beacon){
    beaconLoc = beacon;
}
void Dialog::setReceiver1(Location r1){
    receiver1=r1;
}
void Dialog::setReceiver2(Location r2){
    receiver2=r2;
}
void Dialog::setReceiver3(Location r3){
    receiver3=r3;
}


