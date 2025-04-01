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
    char ch;
    person p;
    fstream file;
    file.open("GROUP.dat",ios::app|ios::out|ios::in|ios::binary);
    do{
        cout<<"Enter persons data:\n";
        p.getdata();
        file.write(reinterpret_cast<char*>(&p),sizeof(p));
        cout<<"Enter another person(y/n)?";
        cin>>ch;
    }while(ch=='y');
    file.seekg(0);
    file.read(reinterpret_cast<char*>(&p),sizeof(p));
    while(!file.eof()){
        cout<<"Person:\n";
        p.showdata();
        file.read(reinterpret_cast<char*>(&p),sizeof(p));
    }
    cout<<endl;

}