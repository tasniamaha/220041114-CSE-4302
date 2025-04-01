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
    ifstream infile;
    infile.open("GROUP.dat",ios::app|ios::out|ios::in|ios::binary);
    infile.seekg(0,ios::end);
    int end=infile.tellg();
    int n=end/sizeof(p);
    cout<<"There are "<<n<<" Persons in file\n";
    cout<<"enter person number:";
    cin>>n;
    int position=(n-1)*sizeof(p);
    infile.seekg(position);
    infile.read(reinterpret_cast<char*>(&p),sizeof(p));
    p.showdata();
    cout<<endl;
}