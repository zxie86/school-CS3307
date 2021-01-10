/**
 * @author Aliza Rizvi
 * @brief creates an object containing a location, x and y coordinates
 *
 */
#include "Location.h"

/**
 * @brief constructor
 * @param newX
 * @param newY
 */
Location::Location(int newX, int newY){
    x = newX;
    y = newY;
}

/**
 * @brief getter for x coordinate
 * @return x coordinate
 */
int Location::getX(){
    return x;
}

/**
 * @brief getter for y coordinate
 * @return y coordinate
 */
int Location::getY(){
    return y;
}

/**
 * @brief setter for x coordinate
 * @param newX
 */
void Location::setX(int newX){
    x = newX;
}

/**
 * @brief setter for y coordinate
 * @param newY
 */
void Location::setY(int newY){
    y = newY;
}

/**
 * @brief destructor
 */
Location::~Location(){

}
