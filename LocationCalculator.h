//header for location calculator
#ifndef LOCATIONCALC_H
#define LOCATIONCALC_H
#include "Receiver.h"
#include "Location.h"

class LocationCalculator{
private:
    Receiver receiver1, receiver2, receiver3;
    bool signalReceived;
    int width, height;
    double maxDistance;
    Location beaconLocation;

    Location findIntersection(Receiver r1, Receiver r2, Receiver r3);

public:
    LocationCalculator(Receiver, Receiver, Receiver, int, int);
    Location calculateLocation();
    ~LocationCalculator();

};
#endif