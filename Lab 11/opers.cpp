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
};
int main(){
    person p;
    p.getdata();
    ofstream outfile("PERSON.dat",ios::binary);
    outfile.write(reinterpret_cast<char*>(&p),sizeof(p));
    
}