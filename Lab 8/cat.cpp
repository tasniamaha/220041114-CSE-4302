#include "cat.h"
#include<iostream>
using namespace std;
cat::cat(string n, string habit,int w, int h) :animal(n,habit,"meow.",w,h)
{
    setsound("meow");
}

void cat::make_sound()
{
    cout<<"The cat says ";
    animal::make_sound();
}

void cat::displayInformation()
{
    animal::displayInformation();
}

void cat::make_animal_sound()
{
    animal::make_sound();
}
