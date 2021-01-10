#include "map.h"
#include "ui_map.h"
#include <QMessageBox>
/**
 * @brief Map class. Show receivers, beacon, restriction on map
 *
 * @author Zhiqi Xie
 *
 */
/**
 * @brief Map constructor
 *
 * @param QWidget *parent
 *
 */
Map::Map(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Map)
{
    ui->setupUi(this);
}
/**
 * @brief Map destructor
 *
 */
Map::~Map()
{
    delete ui;
}
/**
 * @brief Set beacon
 *
 * @param Location beacon
 *
 */
void Map::setBeacon(Location beacon){
    beaconLoc = beacon;
}
/**
 * @brief Set receiver1
 *
 * @param Location r1
 *
 */
void Map::setReceiver1(Location r1){
    receiver1=r1;
}
/**
 * @brief Set receiver2
 *
 * @param Location r2
 *
 */
void Map::setReceiver2(Location r2){
    receiver2=r2;
}
/**
 * @brief Set receiver3
 *
 * @param Location r3
 *
 */
void Map::setReceiver3(Location r3){
    receiver3=r3;
}
/**
 * @brief set restriction1
 *
 * @param Location 0
 *
 */
void Map::setRestriction1(Location O){
    Restriction_1=O;
}
/**
 * @brief set restriction2
 *
 * @param Location 02
 *
 */
void Map::setRestriction2(Location O2){
    Restriction_2=O2;
}
/**
 * @brief Set edge
 *
 * @param Location edge
 *
 */
void Map::setEdge(Location edge){
    Edge=edge;
}
/**
 * @brief calculate beacon location
 */
void Map::progress2(){

    Receiver r1, r2, r3;
    Beacon beacon;

    beacon = Beacon(Edge.getX(),Edge.getY());

    r1 = Receiver(receiver1, beacon);
    r2 = Receiver(receiver2, beacon);
    r3 = Receiver(receiver3, beacon);

    LocationCalculator calculate=LocationCalculator(r1,r2,r3,Edge.getX(),Edge.getY());
    beaconLoc = calculate.calculateLocation();

}
/**
 * @brief get beacon location
 * @author Oleksiy Kovtonyuk
 *
 */
int Map::getBeaconX(){
    return this->beaconLoc.getX();

}

int Map::getBeaconY(){
    return this->beaconLoc.getY();

}

/**
 * @brief paint event
 * draw receivers and beacon on map
 * @param QPaintEvent *e
 * @author Oleksiy Kovtonyuk, Zhiqi Xie
 */
void Map::paintEvent(QPaintEvent *e){

    QPainter painter(this);
    QPen beaconpen(Qt::black, 2, Qt::SolidLine);
    painter.setPen(beaconpen);
    //draw beacon
    painter.drawEllipse(beaconLoc.getX(), beaconLoc.getY(), 10, 10);

    //create a red pen that has solid line and the width is 2.
    QPen receiverpen(Qt::red, 2, Qt::SolidLine);
    painter.setPen(receiverpen);
    //draw edge
    painter.drawRect(0,0,Edge.getX(),Edge.getY());

    QPen new_pen(Qt::green, 2, Qt::SolidLine);
    painter.setPen(new_pen);
    //draw restriction
    painter.drawRect(Restriction_1.getX(),Restriction_1.getY(),Restriction_2.getX()-Restriction_1.getX(),Restriction_2.getY()-Restriction_1.getY());


    QPen old_pen(Qt::blue, 2, Qt::SolidLine);
    painter.setPen(old_pen);
    //fill color
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    //draw receivers
    painter.drawRect(receiver1.getX(),receiver1.getY(),5,5);
    painter.drawRect(receiver2.getX(),receiver2.getY(),5,5);
    painter.drawRect(receiver3.getX(),receiver3.getY(),5,5);

    if(!outOfBound()){

    painter.drawLine(receiver1.getX(),receiver1.getY(),beaconLoc.getX(), beaconLoc.getY());
    painter.drawLine(receiver2.getX(),receiver2.getY(),beaconLoc.getX(), beaconLoc.getY());
    painter.drawLine(receiver3.getX(),receiver3.getY(),beaconLoc.getX(), beaconLoc.getY());

    }

}
/**
 * @brief Check if Beacon is out of bounds
 * @author Oleksiy Kovtonyuk,  Ates Avci
 * @return true if out of bounds
 * @return false if not
 */
bool Map::outOfBound()
{
    //Base case,  Restriction_1 is smaller that Restriction_2 by both x and y value, so it (Restriction_1) represents the Left Upper (close to 0,0) corner and Restriction_2 the Right Bottom (close to x,y)
    if (Restriction_1.getX() < Restriction_2.getX() && Restriction_1.getY() < Restriction_2.getY()){

        if(beaconLoc.getX() >= Restriction_2.getX() || beaconLoc.getX() <= Restriction_1.getX() || beaconLoc.getY() >= Restriction_2.getY() || beaconLoc.getY() <= Restriction_1.getY())
            {
                return true;
            }
            else return false;

    }

    //2nd case,  Restriction_1 is grater that Restriction_2 by x value, but smaller in y value, so it (Restriction_1) represents the Right Upper (close to x,0) corner and Restriction_2 the Left Bottom (close to 0,y)
    if (Restriction_1.getX() > Restriction_2.getX() && Restriction_1.getY() < Restriction_2.getY()){

        if(beaconLoc.getX() <= Restriction_2.getX() || beaconLoc.getX() >= Restriction_1.getX() || beaconLoc.getY() >= Restriction_2.getY() || beaconLoc.getY() <= Restriction_1.getY())
            {
                return true;
            }
            else return false;

    }

    //3rd case,  Restriction_1 is grater that Restriction_2 by y value, but smaller in x value, so it (Restriction_1) represents the Left Bottom (close to 0,y) corner and Restriction_2 the Reft Upper (close to x,0)
    if (Restriction_1.getX() < Restriction_2.getX() && Restriction_1.getY() > Restriction_2.getY()){

        if(beaconLoc.getX() >= Restriction_2.getX() || beaconLoc.getX() <= Restriction_1.getX() || beaconLoc.getY() <= Restriction_2.getY() || beaconLoc.getY() >= Restriction_1.getY())
            {
                return true;
            }
            else return false;

    }

    //4th case,  Restriction_1 is smaller than Restriction_2 by both X and Y value, so it (Restriction_1) represents the Right Bottom (close to x,y) corner and Restriction_2 the Left Upper (close to 0,0)
    if (Restriction_1.getX() > Restriction_2.getX() && Restriction_1.getY() > Restriction_2.getY()){

        if(beaconLoc.getX() <= Restriction_2.getX() || beaconLoc.getX() >= Restriction_1.getX() || beaconLoc.getY() <= Restriction_2.getY() || beaconLoc.getY() >= Restriction_1.getY())
            {
                return true;
            }
            else return false;

    }


}
/**
 * @brief Set Button
 * @author Oleksiy Kovtonyuk
 *
 */

void Map::on_pushButton_clicked()
{
    close();
}
