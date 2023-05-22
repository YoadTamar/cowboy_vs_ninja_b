#pragma once

#include <iostream>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;
    public:

        Point();
        Point(double , double);
        void Print();
        static Point moveTowards(const Point &, const Point &, double);
        double distance(const Point &) const;
        double getX();
        double getY();

    };
    
}