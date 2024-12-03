#include "chicken.h"
#include<iostream>
using namespace std;
chicken::chicken(string n, string habit,int w, int h, int d_egg):animal(n,habit,"buck buck",w,h),dailyEggCount(d_egg)
{
    setsound("buck buck");
}

void chicken::makesound()
{
    cout<<"The chicken says ";
    animal::make_sound();
}

int chicken::getEggCount()
{
    return dailyEggCount;
}

void chicken::display()
{
    animal::displayInformation();
}
