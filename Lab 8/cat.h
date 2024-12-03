#ifndef CAT_H
#define CAT_H
#include"animal.h"
class cat :private animal
{
private:
    
public:
    cat(string n,string habit,int w,int h);
    void make_sound();
    void displayInformation();
    
    void make_animal_sound();
   
    
};
#endif

