#include<iostream>
using namespace std;
class counter{
    private:
    int count;
    int inc;
    public:
    counter(){
        count=0;
        inc=0;
    }
    void setIncrementStep(int s){
        inc=s;
    }
    int getCount(){
        return count;
    }
    int increment(){
        return count+=inc;  
    }
    void resetCount(){
        count=0;
    }
};
int main(){
    counter count;
    count.setIncrementStep(5);
    cout<<"Count after incrementing: "<<count.increment()<<endl;
    cout<<"Count after incrementing: "<<count.increment()<<endl;
    count.resetCount();
    cout<<"After resetting: "<<count.getCount()<<endl;
}
    
