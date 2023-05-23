#include <iostream>

using namespace std;

#include "Cowboy.hpp"

namespace ariel
{
    //string, const Point, int
    Cowboy::Cowboy(std::string name, Point location) : Character(name, location, 110) , bullets(6) {this->setType(1);};

    void Cowboy::shoot(Character* other)
    {
        if(this->bullets == 0)
            return;
        if(this->getHitPoints() <= 0)
            throw std::runtime_error("You are dead");
        if(other == this)
            throw std::runtime_error("cannot shoot yourself");
        if(!other->isAlive())
            throw std::runtime_error("dead target");
        other->hit(10);
        this->bullets -= 1;        
    }

    bool Cowboy::hasboolets()
    {
        return this->bullets > 0;
    }
    
    void Cowboy::reload()
    {
        if(!this->isAlive())
            throw runtime_error("dead");
        this->bullets = 6;
    }

    string Cowboy::print()
    {
        string res = "";
        res += "C name: " + this->getName();
        if(this->isAlive() == true)
            res += " " + to_string(this->getHitPoints());
        res += " (" + to_string(this->getLocation().getX()) + "," + to_string(this->getLocation().getY()) + ")";
        return res;
    }
}
