#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;
class employee{
    private:
    string name;
    string dob;
    int salary;
    int calculateage(const string dob){
        int yr=stoi(dob.substr(0,4));
        return abs(yr-2024);
    }
    public:
    employee()=default;
    employee(const string name,const string dob,int salary);
    const string &getname() const;
    const string &getdob() const;
    int getsalary() const;
    void setname(const string newname);
    void setdob(const string dateofbirth);
    void setsalary(int s);
    void getinfo();
    void setinfo();
    employee compareage(const employee e);
};
#endif