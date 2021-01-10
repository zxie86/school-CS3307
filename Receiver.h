/* 
 * 
 * header for receiver class
 */
#ifndef Receiver_H
#define Receiver_H
#include "Beacon.h"
#include "Location.h"


class Receiver{
private:
    Location location;
    Beacon beacon;

public:
    Receiver() = default;
    Receiver(Location location_p, Beacon beacon_p);
    ~Receiver();
    double getSignal();
    void setLocation(int x, int y);
    Location getLocation();

};
#endif
