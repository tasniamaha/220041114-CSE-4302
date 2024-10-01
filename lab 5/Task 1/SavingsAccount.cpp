#include "SavingsAccount.h"
#include <iostream>
#include<string>
using namespace std;
SavingsAccount::SavingsAccount(string accName,string holderName,string addr,double interest,double balance)
:name(accName),account_holders_name(holderName),address(addr),annual_interest(interest),current_balance(balance),minbalance(1000)
{}

void SavingsAccount::setname(const string accname)
{
    name=accname;
}

void SavingsAccount::setaccountname(const string holdname)
{
    account_holders_name=holdname;
}

void SavingsAccount::setaddress(const string addr)
{
    address=addr;
}

void SavingsAccount::setinterest(double interest)
{
    annual_interest=interest;
}

void SavingsAccount::setbalance(double balance)
{
    current_balance=balance;
}


const string &SavingsAccount::getname() const
{
    return name;
}

const string &SavingsAccount::getaccountname() const
{
    return account_holders_name;
}



const string SavingsAccount::getaddress()
{
    return address;
}

double SavingsAccount::getinterest()
{
    return annual_interest;
}

double SavingsAccount::getbalance()
{
    return current_balance;
}

void SavingsAccount::deposit(double balance)
{
    current_balance+=balance;
    if (current_balance<minbalance) {
        minbalance = current_balance;
    }
}

void SavingsAccount::withdraw(double balance)
{
    if(balance<=current_balance){
        current_balance-=balance;
        if(current_balance<minbalance){
            minbalance=current_balance;
        }
    }
    else{
        cout<<"Insufficient funds"<<endl;
    }

}



double SavingsAccount::calculateinterest(int periodinmonths)
{
    double interestRatePerMonth = annual_interest / 12;
    int inter=current_balance*(interestRatePerMonth*periodinmonths) / 100;
    return inter;
}

void SavingsAccount::disburseinterest(int periodinmonths)
{
    cout<<"Do You Want to disburse:";
    char ch;
    cin>>ch;
    if(ch=='y'){
        int interest=calculateinterest(periodinmonths);
        current_balance+=interest;
    }
}
