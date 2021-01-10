/**
 * @author Ates Avci
 * @brief Receivers can receive and contribute data to the location calculator.
 * They are used to calculate the location of the beacon.
 */

#include "Receiver.h"
/**
 * @brief constructor
 * @param location_p -> location of receiver
 * @param beacon_p -> beacon
 */
Receiver::Receiver(Location location_p, Beacon beacon_p){   //constructor
    location= location_p;
    beacon = beacon_p;
}

/**
 * @brief getter
 * @return signal from beacon
 */
double Receiver::getSignal(){
    return beacon.sendSignal(location);
}
/**
 * @brief setter
 * @param x coordinate
 * @param y coordinate
 */
void Receiver::setLocation(int x, int y){
    location = Location(x,y);
}
/**
 * @brief getter
 * @return location of itself
 */
Location Receiver::getLocation(){
    return this->location;
}
/**
 * @brief destructor
 */
Receiver::~Receiver(){  //destructor

}

