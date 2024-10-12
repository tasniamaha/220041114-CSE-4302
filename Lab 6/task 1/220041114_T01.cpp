#include<iostream>
#include "counter.h"
using namespace std;
int main(){
    counter c1(2),c2(3),c3(4);
    c3=c1+c2;
    cout<<c3.getCount()<<endl;
    if(c3!=c1){
        cout<<"c3 is not equal to c1"<<endl;
    }
    else{
        cout<<"c3 is equal to c1"<<endl;
    }
    ++c1;
    c1+=c2;
    if(c1>c3){
        cout<<"c1 is greater than c3"<<endl;
    }
    else{
        cout<<"c1 is less than c3"<<endl;
    }
}