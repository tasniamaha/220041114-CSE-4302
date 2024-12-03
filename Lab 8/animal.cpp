#include "animal.h"
#include<iostream>
using namespace std;

animal::animal(string n, string habit, string s, int w, int h)
{
    nameOfAnimal=n;
    habitat_area=habit;
    sound=s;
    weight=w;
    height=h;
}

void animal::displayInformation()
{
    cout<<"Name:"<<nameOfAnimal<<endl;
    cout<<"Habitat:"<<habitat_area<<endl;
    cout<<"Sound:"<<sound<<endl;
    cout<<"weight:"<<weight<<endl;
    cout<<"Height:"<<height<<endl;
}

void animal::change_weight(int _weight)
{
    weight=_weight;

}

void animal::make_sound()
{
    cout<<sound<<endl;
}

void animal::setsound(const string s)
{
    sound=s;
}
