#pragma once

#include <iostream>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point location;
        int hitPoints;
        string name;
        bool team;
        int type;
    public:
    
        Character();
        Character(string, const Point, int);
        bool isAlive();
        double distance(Character*);
        void hit(int);
        virtual string print();

        virtual ~Character() = default;

        string getName();
        Point getLocation();
        int getHitPoints();
        bool getTeam();
        int getType();

        void setLocation(Point &);
        void setTeam(bool);
        void setType(int);


    };
    
}