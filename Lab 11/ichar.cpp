#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    char ch;
    ifstream infile("Test.txt");
    while(!infile.eof()){
        infile.get(ch);
        cout<<ch;
    }
    cout<<endl;
}