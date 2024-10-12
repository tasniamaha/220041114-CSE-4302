#include "coordinate.h"
#include<iostream>
#include<cmath>
using namespace std;
void coordinate::display()
{
    cout<<"The coordinates : ("<<abscissa<<","<<ordinate<<")"<<endl;
}
double coordinate::operator-(const coordinate &c) const
{

    return sqrt(((c.abscissa-abscissa)*(c.abscissa-abscissa))+((c.ordinate-ordinate)*(c.ordinate-ordinate)));
}

double coordinate::getDistance()const
{
    return sqrt((abscissa*abscissa)+(ordinate*ordinate));
}

void coordinate::move_x(double x)
{
    abscissa+=x;
}

void coordinate::move_y(double y)
{
    ordinate+=y;
}

void coordinate::move(double x, double y)
{
    abscissa+=x;
    ordinate+=y;
}

bool coordinate::operator<(const coordinate &other) const
{
    return this->getDistance() <other.getDistance();
}

bool coordinate::operator>(const coordinate &other) const
{
    return this->getDistance()>other.getDistance();
}

bool coordinate::operator<=(const coordinate &other) const
{
    return this->getDistance() <=other.getDistance();
}

bool coordinate::operator>=(const coordinate &other) const
{
    return this->getDistance()>=other.getDistance();
}

bool coordinate::operator==(const coordinate &other) const
{
    return this->getDistance() ==other.getDistance();
}

bool coordinate::operator!=(const coordinate &other) const
{
    return this->getDistance() !=other.getDistance();
}
