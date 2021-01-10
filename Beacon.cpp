/**
 * @author Malcolm Shelley
 * @date Dec. 2
 * @brief Calculates the distance from the beacon to the given receiver
 */

#include "Beacon.h"
#include <cstdlib>
#include <ctime>
#include <cmath>
#define ERROR_PERCENT 10

/**
 * @brief constructor assigns a randomly generated location to beacon, with a 10% error outside of room boundaries specified by the user
 * @param newWidth -> width of room
 * @param newHeight -> height of room
 */
Beacon::Beacon(int newWidth, int newHeight) {
    width = newWidth;
    height = newHeight;
    errorRangeW = width * (ERROR_PERCENT / 100);
    errorRangeH = height * (ERROR_PERCENT / 100);
    newLocation();
}

/**
 * @brief assigns a randomly generated location to beacon, with a 10% error outside of room boundaries
 *
 */
Location Beacon::newLocation() {
    int randomx, randomy;
    srand(time(0));

    randomx = rand() % width + errorRangeW;
    randomy = rand() % height + errorRangeH;

    location = Location(randomx, randomy);

    return location;
}


/**
 * @brief calculates the distance to the input receiver
 *
 * @param recipientLoc: location of the receiver
 * @return double: distance from beacon to receiver where 1 is on top, 0 is maximum distance away
 */
double Beacon::sendSignal(Location recipientLoc) {
    Location recipientLocation = recipientLoc;
    double distance;

    //distance from beacon to receiver where 1 is on top, 0 is maximum distance away
    // 1 - root((x1-x2)^2 + (y1-y2)^2) / max distance
    distance = 1 - (sqrt(pow(recipientLoc.getX() - location.getX(), 2) + pow(recipientLoc.getY() - location.getY(), 2)) / sqrt(pow(width + errorRangeW, 2) + pow(height + errorRangeH, 2)));

    return distance;
}

/**
 * @brief default deconstructor
 */
Beacon::~Beacon(){

}
