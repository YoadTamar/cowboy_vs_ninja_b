#pragma once

using namespace std;

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
        public:
            SmartTeam(Character*);
            void attack(Team*);
            void print();
    };
}