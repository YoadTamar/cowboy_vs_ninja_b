#include <iostream>

using namespace std;

#include "SmartTeam.hpp"

namespace ariel
{
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}
    void SmartTeam::attack(Team *enemies) {}
    void SmartTeam::print() {}
}