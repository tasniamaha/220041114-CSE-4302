#include "counter.h"
#include<iostream>
counter::counter(int step_val)
{
    count=0;
    if(step_val>0){
        incstep=step_val;
    }
    else step_val=1;
}

void counter::setIncrementStep(int step_val)
{
    if(count==0){
        if(step_val>0){
            incstep=step_val;
        }
        else{
            cout<<"Invalid input"<<endl;
        }
    }
    else{
        cout<<"Not possible to set"<<endl;
        
    }
}

int counter::getCount()
{
    return count;
}

void counter::resetCount(int step)
{
    count=0;
    if(step>0){
        incstep=step;
    }
}

void counter::increment()
{
    count+=incstep;
}

counter counter::operator+(const counter &other) const
{   
    counter temp;
    if(incstep==other.incstep){
        
        temp.count=count+other.count;
        temp.incstep=incstep;
    }
    else{
        cout<<"the increment step is not the same"<<endl;
    }
    return temp;
}

counter counter::operator+=(const counter &other) const
{
    return counter(this->count+other.count);
}

counter counter::operator++()
{

    return counter(++count);
}

counter counter::operator++(int)
{
    return counter(count++);
}

bool counter::operator<(const counter &other) const
{
    return count<other.count;
}

bool counter::operator>(const counter &other) const
{
    return count>other.count;
}

bool counter::operator<=(const counter &other) const
{
    return count<=other.count;
}

bool counter::operator>=(const counter &other) const
{
    return count>=other.count;
}

bool counter::operator==(const counter &other) const
{
    return count==other.count;
}

bool counter::operator!=(const counter &other) const
{
    return count!=other.count;
}
