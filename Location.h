/**
 * @author Aliza Rizvi
 * @brief header for location class
 *
 */
#ifndef LOCATION_H
#define LOCATION_H

class Location{
private:
    int x{}, y{};

public:
    Location() = default;
    Location(int newX, int newY);
    int getX();
    int getY();
    void setX(int newX);
    void setY(int newY);
    ~Location();
};
#endif
