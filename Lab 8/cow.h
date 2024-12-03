#ifndef COW_H
#define COW_H

#include"animal.h"
using namespace std;
class cow : public animal
{
private:
    double milkProductionInLiters;
public:
    cow(string name,string habit,int w,int h,double mp);
    void makesound();
    double getMilkProduction();
};
#endif


