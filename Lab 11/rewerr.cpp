#include<iostream>
#include<fstream>
#include<process.h>
using namespace std;
const int MAX=100;
int buff[MAX];
int main(){
    for(int i=0;i<MAX;i++){
        buff[i]=i;
    }
    ofstream outfile;
    outfile.open("c:edata.dat",ios::trunc|ios::binary);
    if(!outfile){
        cerr<<"Could not open output\n"<<endl;
        exit (1);
    }
    cout<<"Writing...\n";
    outfile.write(reinterpret_cast<char*>(buff),MAX*sizeof(int));
    if(!outfile){
        cerr<<"Could not write output"<<endl;
        exit(1);
    }
    outfile.close();
    for(int i=0;i<MAX;i++){
        buff[i]=0;
    }
    ifstream infile;
    infile.open("c:edata.dat",ios::binary);
    if(!infile){
        cout<<"could not open input"<<endl;
        exit(1);
    }
    cout<<"Reading.."<<endl;
    if(!infile){
        cerr<<"Could not read from input\n";
        exit(1);
    }
    //cout<<"Reading....\n";
    infile.read(reinterpret_cast<char*>(buff),MAX*sizeof(int));
    for(int i=0;i<MAX;i++){
        if(buff[i]!=i){
            cerr<<"Incorrect\n";
            return 1;
        }
        cout<<"correct\n";
    }
}
