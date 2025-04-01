#include<iostream>
#include<fstream>
using namespace std;
class person{
    private:
    char name[80];
    short age;
    public:
    void getdata(){
        cout<<"Enter name:";
        cin>>name;
        cout<<"Enter Age:";
        cin>>age;
    }
    void showdata(){
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
    }
};
int main(){
    person p;
    ifstream infile("PERSON.dat",ios::binary);
    infile.read(reinterpret_cast<char*>(&p),sizeof(p));
    p.showdata();
}