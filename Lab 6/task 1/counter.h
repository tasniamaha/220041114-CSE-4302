#ifndef COUNTER_H
#define COUNTER_H
using namespace std;
class counter{
    private:
    int count;
    int incstep;
    public:
    counter (int step_val=1);
    void setIncrementStep(int step_val=1);
    int getCount();
    void resetCount(int step = 1);
    void increment();
    counter operator+(const counter& other) const;
    counter operator+=(const counter& other) const;
    counter operator++();
    counter operator++(int);
    bool operator < (const counter& other)const;
    bool operator > (const counter& other)const;
    bool operator <= (const counter& other)const;
    bool operator >= (const counter& other)const;
    bool operator == (const counter& other)const;
    bool operator != (const counter& other)const;

};
#endif