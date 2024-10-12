#include<iostream>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include "coordinate.h"
using namespace std;
void randomassignment(coordinate c[],int size){
    srand(static_cast<unsigned int>(time(0)));
    for(int i=0;i<size;i++){
        double x=static_cast<double>(rand());
        double y=static_cast<double>(rand());
        c[i]=coordinate(x,y);
    }
}
void sortpoint(coordinate c[], int size){
    sort(c,c+size);
}
int main(){
    coordinate c1[10];
    randomassignment(c1,10);
    sortpoint(c1,10);
    for(int i=0;i<10;i++){
        c1[i].display();
    }
}