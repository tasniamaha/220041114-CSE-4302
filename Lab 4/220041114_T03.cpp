#include<iostream>
#include<string>
using namespace std;
class BankAccount{
    private:
    int account_num;
    string account_name;
    string type;
    double current_balance;
    const double minimum=100.0;
    static int tot_account;
    static int active_account;
    static double tot_tax;
    public:
    BankAccount(int id,const string name,const string t){
        account_num=id;
        account_name=name;
        type=t;
        current_balance=0.0;
        tot_account++;
        active_account++;
    }
    void showbalance(){
        cout<<"Current Balance: "<<current_balance<<endl;
    }
    void deposit(double a){
        if(a>=0) current_balance+=a;
        else cout<<"Inavalid input"<<endl;
    }
    void withdraw(double a){
        if(a>=0 && current_balance-a>=minimum){
            current_balance-=a;
        }
        else if(a<0) cout<<"Invalid input"<<endl;
        else cout<<"Insufficient balance"<<endl;
    }
    void giveinterest(double r=0.03){
        double interest=current_balance*r;
        double tax=interest*0.10;
        double net=interest-tax;
        current_balance+=net;
        cout<<"Net interest added :"<<net<<endl;
    }
    double getbalance(){
        return current_balance;
    }
    static int getaccount(){
        return tot_account;
    }
    static int getactive(){
        return active_account;
    }
    static double gettax(){
        return tot_tax;
    }
    ~BankAccount(){
        active_account--;
        double interest=current_balance*0.03;
        double tax=interest*0.10;
        tot_tax+=tax;
        cout<<"Account of "<<account_name<<" with account no "<<account_num<<" is destroyed with a balance BDT "<<current_balance<<endl;
    }
};
int BankAccount::tot_account=0;
int BankAccount::active_account=0;
double BankAccount::tot_tax=0.0;
BankAccount Larger(BankAccount ac1,BankAccount ac2){
    if(ac1.getbalance()>ac2.getbalance()){
        return ac1;
    }
    else return ac2;
}
void display_stat(){
    cout<<"Total account :"<<BankAccount::getaccount()<<endl;
    cout<<"Total active account :"<<BankAccount::getactive()<<endl;
    cout<<"Total tax:"<<BankAccount::gettax()<<endl;
}
int main(){
    BankAccount ac1(1234,"xyz","savings");
    ac1.showbalance();
    ac1.deposit(10000);
    ac1.giveinterest();
    ac1.showbalance();
    BankAccount ac2(4567,"abc","current");
    ac2.showbalance();
    ac2.deposit(2000);
    ac2.giveinterest();
    //cout<<"Account with higher balance:"<<Larger(ac1,ac2)<<endl;
    display_stat();

}