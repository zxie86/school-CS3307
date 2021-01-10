#ifndef MAP_H
#define MAP_H

#include <QWidget>
#include <QDialog>
#include <QtGui>
#include <QtCore>

#include "Location.h"
#include "Receiver.h"
#include "Beacon.h"
#include "LocationCalculator.h"
#include "log_in.h"
/**
 * @brief Map class header file
 *
 * @author Zhiqi Xie
 *
 */
namespace Ui {
class Map;
}

class Map : public QWidget
{
    Q_OBJECT

public:
    explicit Map(QWidget *parent = nullptr);
    ~Map();

    Location beaconLoc;
    Location receiver1;
    Location receiver2;
    Location receiver3;
    Location Edge;
    Location Restriction_1;
    Location Restriction_2;



public slots:

    void progress2();

    void setBeacon(Location);
    void setReceiver1(Location);
    void setReceiver2(Location);
    void setReceiver3(Location);
    void setRestriction1(Location);
    void setRestriction2(Location);
    void setEdge(Location);
    bool outOfBound();

    int getBeaconX();
    int getBeaconY();

private:
    Ui::Map *ui;


protected:
    void paintEvent(QPaintEvent *e);

private slots:
    void on_pushButton_clicked();
};

#endif // MAP_H
