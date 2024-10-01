#include "SavingsAccount.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include <iomanip>
#include<algorithm>
void editbykey(SavingsAccount &acc){
    string accName,holderName,addr;
    double interestRate,balance;
    cout<<"Enter account name: ";
    getline(cin,accName);
    cout<<"Enter account holder's name: ";
    getline(cin,holderName);
    cout<<"Enter address: ";
    getline(cin, addr);
    cout <<"Enter annual interest rate: ";
    cin>>interestRate;
    cout<<"Enter current balance: ";
    cin>>balance;
    acc.setname(accName);
    acc.setaccountname(holderName);
    acc.setaddress(addr);
    acc.setinterest(interestRate);
    acc.setbalance(balance);
    cin.ignore();
}
string genname(int minlen,int maxlen){
    int len=minlen + rand() % (maxlen - minlen + 1);
    string word;
    for (int i = 0; i < len; ++i) {
        char letter = 'a' + rand() % 26;
        word += letter;
    }
    return word;
}
string generateRandomAccountName(int minLen, int maxLen) {
    string firstWord = genname(minLen, maxLen);  
    string secondWord = genname(minLen, maxLen); 
    return firstWord + " " + secondWord; 
}
string generaterandomholdername(int minlen,int maxlen){
    string firstWord = genname(minlen, maxlen);  
    string secondWord = genname(minlen, maxlen); 
    return firstWord + " " + secondWord;
}
string generaterandomaddress(int minlen,int maxlen){
    string firstWord = genname(minlen, maxlen);  
    string secondWord = genname(minlen, maxlen); 
    string thirdWord = genname(minlen, maxlen); 
    string fourthWord = genname(minlen, maxlen); 
    string fifthWord = genname(minlen, maxlen); 
    return firstWord + " " + secondWord+" "+thirdWord+" "+fourthWord+" "+fifthWord;
}
double generateRandomInterestRate(double minRate, double maxRate, double step) {
    int numSteps = (maxRate - minRate) / step + 1;
    int randomStep = rand() % numSteps;
    return minRate + randomStep * step;
}
int generateRandomBalance(int minBalance, int maxBalance) {
    return minBalance + rand() % (maxBalance - minBalance + 1);
}

void randomgenerate(SavingsAccount &account){
    srand(static_cast<unsigned>(time(0))); 
    string accountName = generateRandomAccountName(4, 10);
    string accountHolderName = generaterandomholdername(4, 10);
    string address = generaterandomaddress(4, 10);
    double annualInterestRate = generateRandomInterestRate(2.0, 5.0, 0.10);
    int currentBalance = generateRandomBalance(1000, 50000);

}
void ShowInterestAll(SavingsAccount accounts[], int numAccounts) {
    for (int i = 0; i < numAccounts; ++i) {
        double interest = accounts[i].calculateinterest(12);
        cout << "Interest for " << accounts[i].getaccountname() << ": " << interest << "\n";
    }

}
bool compareByAccountName(const SavingsAccount a, const SavingsAccount b) {
    return a.getaccountname() < b.getaccountname();
}

void ShowAllAlphabetically(SavingsAccount accounts[]) {
    for (int i = 0; i <100; ++i) {
        cout << "Account Name: " << accounts[i].getaccountname() << ", Current Balance: " << accounts[i].getbalance() << "\n";
    }
}
int main(){
    SavingsAccount acc[100];
    for (int i = 0; i < 2; i++) {
        editbykey(acc[i]);
    }
    for(int i=2;i<100;i++){
        randomgenerate(acc[i]);
    }
    char confirm;
    cout << "Confirm disbursement (y/n)? ";
    cin >> confirm;
    
    if (confirm == 'y') {
        for (int i = 0; i < 100; ++i) {
            acc[i].disburseinterest(12);
        }
        cout << "Interest disbursed.\n";
    }
    ShowInterestAll(acc,100);
    ShowAllAlphabetically(acc);
}
