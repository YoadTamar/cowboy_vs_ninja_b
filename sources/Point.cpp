#include <iostream>
#include <cmath>

using namespace std;

#include "Point.hpp"

namespace ariel
{
    Point::Point() : x(0), y(0) {};

    Point::Point(double x, double y) : x(x), y(y) {};

    void Point::Print()
    {
        cout << "(" << this->x << "," << this->y << ")" << endl;    
    }

    double Point::getX()
    {
        return this->x;
    }

    double Point::getY()
    {
        return this->y;
    }

    Point Point::moveTowards(const Point &current, const Point &other, double dist) {
        
        if(dist < 0)
            throw std::invalid_argument("negative distance");

        double distance = current.distance(other);
        if (distance <= dist) 
        {
            return other;
        }

        double newx = other.x - current.x;
        double newy = other.y - current.y;
        double factor = dist / distance;
        double new_X = current.x + newx * factor;
        double new_Y = current.y + newy * factor;

        return Point(new_X, new_Y);
    }

    double Point::distance(const Point &p) const{
        return sqrt(pow(this->x - p.x, 2) + pow(this->y - p.y, 2));
    }








}