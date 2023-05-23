#pragma once

using namespace std;

#include "Team.hpp"

namespace ariel
{
    class SmartTeam : public Team
    {
        public:
            SmartTeam(Character*);
            void attack(Team*) override;
            void print() override;
            Character* ninja_victim(Ninja* , Team*);
            Character* cowboy_victim(Team*);
    };
}