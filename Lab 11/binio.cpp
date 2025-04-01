#include<iostream>
#include<fstream>
using namespace std;
const int MAX=100;
int buff[MAX];
int main(){
    for(int i=0;i<MAX;i++){
        buff[i]=i;
    }
    ofstream outfile("edata.dat",ios::binary);
    outfile.write(reinterpret_cast<char*>(buff),MAX*sizeof(int));
    outfile.close();
    for(int i=0;i<MAX;i++){
        buff[i]=0;
    }
    ifstream infile("edata.dat",ios::binary);
    infile.read(reinterpret_cast<char*>(buff),MAX*sizeof(int));
    for(int i=0;i<MAX;i++){
        if(buff[i]!=i){
            cerr<<"Incorrect\n";
            return 1;
        }
        cout<<"correct\n";
    }
}