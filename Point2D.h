#ifndef POINT2D_H
#define POINT2D_H


#include <iostream>

using namespace std;

class Point2D
{
    public:

    //Variables
    double x, y;

    //Constructors
    Point2D();
    Point2D(double, double);
};

double GetDistanceBetween(Point2D, Point2D);

ostream & operator << (ostream &, Point2D);
Point2D operator + (Point2D, Point2D);
Point2D operator - (Point2D, Point2D);

#endif