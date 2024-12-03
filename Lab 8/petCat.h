#ifndef PETCAT_H
#define PETCAT_H
#include "cat.h"
using namespace std;
class petCat:public cat{
    private:
    //cat ct;
    string pet_name;
    public:
    petCat(string n,string habit,string s,int w,int h,string petn);
    void setname(const string pet_n);
    const string getname();
    void make_sound() ;
    void displayInformation() ;
};
#endif