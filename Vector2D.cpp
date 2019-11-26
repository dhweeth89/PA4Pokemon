#include <iostream>
#include "Vector2D.h"

using namespace std;

Vector2D::Vector2D()
{
    x = 0;
    y = 0;
}

Vector2D::Vector2D(double x_in, double y_in)
{
    x = x_in;
    y = y_in;
}

Vector2D operator * (Vector2D v1, double d)
{
    Vector2D v2 = Vector2D(v1.x * d, v1.y * d);
    return v2;
}

Vector2D operator / (Vector2D v1, double d)
{
    Vector2D v2 = Vector2D(v1.x / d, v1.y / d);
    return v2;
}

ostream & operator << (ostream &out, Vector2D v1)
{
    out << "<" << v1.x << ", " << v1.y << ">" << endl;
    return out;
}