#include "employee.h"
#include<string>
#include <iostream>
using namespace std;
employee::employee(const string name, const string dob, int salary)
{
    setname("John Doe");
    setdob("2001-01-01");
    setsalary(10000);

}
const string &employee::getname() const
{
    return name;
}

const string &employee::getdob() const
{
    return dob;
}

int employee::getsalary() const
{
    return salary;
}

void employee::setname(const string newname)
{
    if(name.length()>2){
        name=newname;
    }
    else{
        name = "John Doe";
    }
}

void employee::setdob(const string dateofbirth)
{
    if(calculateage(dateofbirth)<18){
        dob="2002-01-01";
    }
    else{
        dob=dateofbirth;
    }
}

void employee::setsalary(int s)
{
    if(s>=10000 && s<=100000){
        salary=s;
    }
    else{
        salary=10000;
    }
}

void employee::getinfo()
{
    cout << "Employee Name: " << getname() << "\n"<< "Date of Birth: " << getdob() << "\n"<< "Salary: BDT " << getsalary() << "\n";
}

void employee::setinfo()
{
    string nameInput, dobInput;
    double salaryInput;
    setname(nameInput);
    setdob(dobInput);
    setsalary(salaryInput);
}

employee employee::compareage(const employee e)
{
    int thisage=calculateage(dob);
    int age=calculateage(e.dob);
    return (thisage > age) ? employee(name, dob, salary) : employee(e.getname(), e.getdob(), e.getsalary());
}
