#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <string>
using namespace std;

class SavingsAccount {
private:
    string name;
    string account_holders_name;
    string address;
    double annual_interest;
    double current_balance;
    double minbalance;

public:
    SavingsAccount() = default;
    SavingsAccount(string accName, string holderName, string addr, double interest, double balance);
    
    void setname(const string accname);
    void setaccountname(const string holdname);
    void setaddress(const string addr);
    void setinterest(double interest);
    void setbalance(double balance);

    const string &getname() const;
    const string &getaccountname() const;
    const string getaddress();
    double getinterest();
    double getbalance();

    void deposit(double balance);
    void withdraw(double balance);
    double calculateinterest(int periodinmonths);
    void disburseinterest(int periodinmonths);
};

#endif 