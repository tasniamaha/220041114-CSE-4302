#include "kelvin.h"
#include "celsius.h"
#include "fahrenheit.h"
#include<iostream>
using namespace std;
kelvin::kelvin(float temp)
{
    if(temp>0){
        kelvin_temp=temp;
    }
    else{
        kelvin_temp=1;
    }
}

void kelvin::assign(float temp)
{
    if(temp>0){
        kelvin_temp=temp;
    }
    else{
        cout<<"Invalid input"<<endl;
    }
}

void kelvin::display()
{
    cout<<"the temperature is in "<<kelvin_temp<<" Kelvin"<<endl;
}

kelvin:: operator celsius() const
{
    float t=kelvin_temp;
    t=t-273.15;
    return celsius(t);
}

kelvin::operator fahrenheit() const
{
    float val=kelvin_temp;
    val=(val-273.15)*(9.0/5.0)+32.0;
    return fahrenheit(val);
}
