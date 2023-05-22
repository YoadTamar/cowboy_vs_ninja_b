#include <iostream>

using namespace std;

#include "Ninja.hpp"

namespace ariel
{
    Ninja::Ninja() : Character() , speed(0){this->setType(2);};

    Ninja::Ninja(string name, Point p, int speed , int hitpoints) : Character(name, p, hitpoints), speed(speed) {this->setType(2);};

    void Ninja::move(Character *other)
    {
        // if (other == nullptr)
        //     throw invalid_argument("Other character is null!");

        // else if (other == this)
        //     throw invalid_argument("Cannot move to yourself!");

        // else if (!isAlive())
        //     throw runtime_error("Cannot move while dead!");

        Point newLocation = Point::moveTowards(getLocation(), other->getLocation(), speed);

        setLocation(newLocation);

    }

    void Ninja::slash(Character *other)
    {
        if(this->getHitPoints() <= 0)
            throw std::runtime_error("you dead");
        if(this == other)
            throw std::runtime_error("cannot slash yourself");
        if(!other->isAlive())
            throw std::runtime_error("dead target");
        if(this->getLocation().distance(other->getLocation()) <= 1)
        {
            other->hit(40);
        }
    }

}