#ifndef ANIMAL_H
#define ANIMAL_H
using namespace std;
#include<string>

class animal
{
private:
   string nameOfAnimal;
   string habitat_area;
   string sound;
   int weight;
   int height;
public:
    animal(string n,string habit,string s,int w,int h) ;
    void displayInformation();
    void change_weight(int _weight);
    void make_sound();
protected:
    void setsound(const string s);
};
#endif


