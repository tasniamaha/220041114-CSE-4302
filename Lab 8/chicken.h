#ifndef CHICKEN_H
#define CHICKEN_H
#include "animal.h"
using namespace std;
class chicken : protected animal
{
private:
   int dailyEggCount;
public:
   chicken(string n,string habit,int w,int h,int d_egg);
   void makesound();
   int getEggCount();
   void display();
};
#endif

