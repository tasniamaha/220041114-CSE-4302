#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){
    string str="Time is a great teacher, but unfortunately it kills all its pupils. Berlioz";
    ofstream outfile("Test.txt");
    for(int i=0;i<str.length();i++){
        outfile.put(str[i]);
    }
    cout<<"File written.\n";
}