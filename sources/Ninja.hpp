#pragma once

#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel
{
    class Ninja : public Character
    {
        private:
            int speed;
        public:

            Ninja();
            Ninja(string, Point, int , int);
            void move(Character *);
            void slash(Character *);

            int getSpeed();
            void setSpeed(int);
            string print() override;
    };
}
