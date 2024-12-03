#include "petCat.h"
#include "cat.h"
#include<iostream>

petCat::petCat(string n, string habit, string s, int w, int h, string petn) : cat(n,habit,w,h),pet_name(petn)
{
    
}

void petCat::setname(const string pet_n)
{
    pet_name=pet_n;
}

const string petCat::getname()
{
    return pet_name;
}

void petCat::make_sound()
{
    cout<<"The cat "<<getname()<<" says ";
    make_animal_sound();
}

void petCat::displayInformation()
{
    cat::displayInformation();
    cout<<"Pet Name:"<<getname()<<endl;
}

