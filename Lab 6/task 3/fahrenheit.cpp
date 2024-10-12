#include "kelvin.h"
#include "celsius.h"
#include "fahrenheit.h"
#include<iostream>
using namespace std;

fahrenheit::fahrenheit(float temp)
{
    if(temp>-459.67){
        fahrenheit_temp=temp;
    }
    else{
        fahrenheit_temp=-459.67;
    }
}

void fahrenheit::assign(float temp)
{
    if(temp>-459.67){
        fahrenheit_temp=temp;
    }
    else{
        cout<<"Invalid input"<<endl;
    }
}

void fahrenheit::display()
{
    cout<<"the temp is "<<fahrenheit_temp<<" Fahrenheit"<<endl;
}

fahrenheit::operator celsius() const
{
    float val=fahrenheit_temp;
    val=(val-32.0)*(5.0/9.0);
    return celsius(val);
}

fahrenheit::operator kelvin() const
{
    float val=fahrenheit_temp;
    val=(val-32.0)*(5.0/9.0)+273.15;
    return kelvin(val);
}
