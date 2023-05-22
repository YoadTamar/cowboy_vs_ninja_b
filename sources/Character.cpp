#include <iostream>

using namespace std;

#include "Character.hpp"

namespace ariel
{
        Character::Character() : name("name"), hitPoints(0), location(Point()), team(false) {};

        Character::Character(string name, Point p, int hitPoints) : name(name), hitPoints(hitPoints), location(p), team(false) {};
        
        bool Character::isAlive()
        {
            return this->hitPoints > 0;
        }

        double Character::distance(Character *other)
        {
            return this->getLocation().distance(other->getLocation());;
        }

        void Character::hit(int hitpoints)
        {
            if(hitPoints < 0)
                invalid_argument("negative hit");
                
            this->hitPoints = this->hitPoints - hitpoints;
        }

        string Character::getName()
        {
            return this->name;
        }

        Point Character::getLocation()
        {
            return this->location;
        }

        bool Character::getTeam()
        {
            return this->team;
        }

        int Character::getType()
        {
            return this->type;
        }


        int Character::getHitPoints()
        {
            return this->hitPoints;
        }

        void Character::setLocation(Point &newl)
        {
            this->location = newl;
        }

        void Character::setTeam(bool team)
        {
            this->team = team;
        }

        void Character::setType(int type)
        {
            this->type = type;
        }

        string Character::print()
        {
            return "";
        }
}
