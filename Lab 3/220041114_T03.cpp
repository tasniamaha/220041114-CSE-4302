#include<iostream>
using namespace std;
class Time{
    private :
    int hr,min,sec;
    public:
    Time(){
        hr=0;
        min=0;
        sec=0;
    }
    int hours(){
        return hr;
    }
    int minutes(){
        return min;
    }
    int seconds(){
        return sec;
    }
    void reset(int h,int m,int s){
        if(h>=0 && h<24){
            hr=h;
        }
        else hr=0;
        if(m>=0 && m<60){
            min=m;
        }
        else min=0;
        if(s>=0 && s<60){
            sec=s;
        }
        else sec=0;
    }
    void advance(int h,int m,int s){
        sec+=s;
        min+=sec/60;
        sec%=60;
        min+=m;
        hr+=min/60;
        min%=60;
        hr=(hr+h)%24;
    }
    void print(){
        cout<<((hr<10)?"0":"")<<hr<<":"<<((min<10)?"0":"")<<min<<":"<<((sec<10)?"0":"")<<sec<<endl;
    }
};
int main(){
    Time myTime ;
    myTime.reset(23,58,5);
    myTime.print();
    myTime.advance(1,5,15);
    myTime.print();
}
