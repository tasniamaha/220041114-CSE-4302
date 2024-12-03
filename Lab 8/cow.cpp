#include "cow.h"
#include<iostream>
using namespace std;

cow::cow(string name, string habit,int w, int h, double mp):animal(name,habit,"moo",w,h),milkProductionInLiters(mp)
{
    setsound("moo");
}

void cow::makesound()
{
    cout<<"The cow says ";
    animal::make_sound();
}

double cow::getMilkProduction()
{
    return milkProductionInLiters;
}
