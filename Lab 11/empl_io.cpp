#include <fstream> 
#include <iostream>
#include <typeinfo> 
using namespace std;
#include <process.h>
const int LEN = 32; 
const int MAXEM = 100;
enum employee_type{tmanager,tscientist,tlabourer};
class employee{
    private:
    char name[LEN];
    unsigned long number;
    static int n;
    static employee* arrap[];
    public:
    virtual void getdata(){
        cin.ignore(10,'\n');
        cout<<"Enter last name:";
        cin>>name;
        cout<<"Enter number:";
        cin>>number;
    }
    virtual void putdata(){
        cout<<"name:"<<name<<'\n';
        cout<<"Number:"<<number<<number;
    }
};