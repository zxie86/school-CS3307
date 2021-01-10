/* 
 * 
 * generate map
 */
#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>

#include <Location.h>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
   
    Location beaconLoc;
    Location receiver1;
    Location receiver2;
    Location receiver3;
    void setBeacon(Location);
    void setReceiver1(Location);
    void setReceiver2(Location);
    void setReceiver3(Location);
private:
    Ui::Dialog *ui;
    
protected:
    void paintEvent(QPaintEvent *e);
};

#endif // DIALOG_H
