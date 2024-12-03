#include<iostream>
#include "animal.h"
#include "cow.h"
#include "chicken.h"
#include "cat.h"
#include "petCat.h"
using namespace std;
int main(){
    cat cat1("cat","house",10,3);
    cat1.displayInformation();
    cat1.make_sound();
    cow cow1("cow","farm",100,15,15.5);
    
    cow1.displayInformation();
    cow1.makesound();
    cout<<"Milk produced :"<<cow1.getMilkProduction()<<"L"<<endl;
    
    petCat c1("Cat","house","meow",7,3,"Chintu");
    c1.displayInformation();
    c1.make_sound();
    chicken ch1("Chicken","farm",2,1,30);
    ch1.display();
    cout<<"Eggs produced:"<<ch1.getEggCount()<<endl;

}