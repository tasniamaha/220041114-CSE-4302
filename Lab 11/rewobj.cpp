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
    void diskin(int);
    void diskout();
    static int diskcount();
};
int person::diskcount(){
    ifstream infile;
    infile.open("PERSFILE.dat",ios::binary);
    infile.seekg(0,ios::end);
    return (int) infile.tellg()/sizeof(person);
}
void person::diskin(int pn){
    ifstream infile;
    infile.open("PERSFILE.dat",ios::binary);
    infile.seekg(pn*sizeof(*this));
    infile.read((char*)this,sizeof(*this));
}
void person::diskout(){
    ofstream outfile;
    outfile.open("PERSFILE.dat",ios::app|ios::binary);
    outfile.write((char*)this,sizeof(*this));
}
int main(){
    person p;
    char ch;
    do{
        cout<<"Enter data:\n";
        p.getdata();
        p.diskout();
        cout<<"Enter another?(y/n)\n";
        cin>>ch;
    }while(ch=='y');
    int n=p.diskcount();
    cout<<"There are "<<n<<" Persons in file\n";
    for(int i=0;i<n;i++){
        cout<<"Person:"<<i+1<<"\n";
        p.diskin(i);
        p.showdata();
    }
    cout<<endl;
}
