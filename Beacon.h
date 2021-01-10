/* Malcolm Shelley
 * Nov. 30
 * Calculates the distance from the beacon to the given receiver
 */

#ifndef INC_3307TRACKFIELD_BEACON_H
#define INC_3307TRACKFIELD_BEACON_H
#include "Location.h"

class Beacon {
private:
    Location location;
    int width, height;
    double errorRangeW, errorRangeH;

public:
    //default room size 250x300m
    Beacon(int = 250, int = 300);
    double sendSignal(Location reciepientLoc);
    Location newLocation();

    ~ Beacon();
};
#endif //INC_3307TRACKFIELD_BEACON_H
