#pragma once

#include <iostream>
#include "Character.hpp"

using namespace std;

namespace ariel
{
    class Cowboy : public Character
    {
        private:
            int bullets;
        public:
            Cowboy(string, Point);
            void shoot(Character*);
            bool hasboolets();
            void reload();

            string print() override;

    };
}