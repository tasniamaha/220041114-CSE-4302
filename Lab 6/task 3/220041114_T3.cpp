#include<iostream>
#include "celsius.h"
#include "fahrenheit.h"
#include "kelvin.h"
using namespace std;
int main(){
    celsius c1(100.0);
    c1.display();
    fahrenheit f=c1;
    f.display();
    kelvin k=c1;
    k.display();
}