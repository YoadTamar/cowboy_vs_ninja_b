#pragma once

#include <iostream>
#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    class OldNinja : public Ninja
    {
        public:
            OldNinja(string, Point);
    };
}
