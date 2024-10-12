#include "celsius.h"
#include"fahrenheit.h"
#include "kelvin.h"
#include <iostream>
using namespace std;
celsius::celsius(float temp)
{
    if(temp>-273.15){
        celsius_temp=temp;
    }
    else{
        celsius_temp=-273.14;
    }
}

void celsius::assign(float temp)
{
    if(temp>0){
        celsius_temp=temp;
    }
    else{
        cout<<"Invalid input"<<endl;
    }
}


void celsius::display()
{
    cout<<"the temperature is in "<<celsius_temp<<" Celsius"<<endl;
}

celsius::operator kelvin() const
{
    float t=celsius_temp;
    t=t+273.15;
    return kelvin(t);
}

celsius::operator fahrenheit() const
{
    float val=celsius_temp;
    val=((9.0/5.0)*celsius_temp)+32.0;
    return fahrenheit(val);
}
