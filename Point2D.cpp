#include <iostream>
#include "Point2D.h"
#include "math.h"

using namespace std;

Point2D::Point2D()
{
    x = 0;
    y = 0;
}

Point2D::Point2D(double x_in, double y_in)
{
    x = x_in;
    y = y_in;
}

double GetDistanceBetween(Point2D p1, Point2D p2)
{
    double x_dist = p2.x - p1.x;
    double y_dist = p2.y - p1.y;
    return sqrt( pow(x_dist, 2) + pow(y_dist, 2) );
}

ostream & operator << (ostream &out, Point2D p)
{
    out << "(" << p.x << ", " << p.y << ")" << endl;
    return out;
}

Point2D operator + (Point2D p1, Point2D p2)
{
    Point2D p3 = Point2D(p1.x + p2.x, p1.y + p2.y);
    return p3;
}

Point2D operator - (Point2D p1, Point2D p2)
{
    Point2D p3 = Point2D(p1.x - p2.x, p1.y - p2.y);
    return p3;
}