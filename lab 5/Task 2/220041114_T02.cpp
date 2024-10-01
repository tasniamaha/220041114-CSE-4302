#include<iostream>
#include<string>
#include "employee.h"
using namespace std;
int main(){
    employee emp1,emp2;
    emp1.setname("Alice Johnson");
    emp1.setdob("1996-02-04");
    emp1.setsalary(50000);
    emp2.setname("ABCD EFGH");
    emp2.setdob("1965-03-17");
    emp2.setsalary(70000);
    emp1.getinfo();
    emp2.getinfo();
    employee elder = emp1.compareage(emp2);
    cout << "Elder Employee Info:\n";
    elder.getinfo();
}