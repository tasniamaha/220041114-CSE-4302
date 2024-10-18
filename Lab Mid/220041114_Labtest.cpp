#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class laptop{
    private:
    string modelno;
    double price;
    string manufacturer;
    public:
    void setmodel(const string m){
        modelno=m;
    }
    void setprice(double p){
        price=p;
    }
    void setmanufact(const string mfr){
        manufacturer=mfr;
    }
    const string getmodel(){
        return modelno;
    }
    double getprice(){
        return price;
    }
    const string getmanufact(){
        return manufacturer;
    }
    void display(){
        cout<<"Model:"<<modelno<<" "<<"Manufacturer:"<<manufacturer<<" "<<"Price:"<<price<<endl;
    }
    bool operator<(const laptop& other){
        return this->manufacturer<other.manufacturer;
    }
    
};
void sortbymanufacturer(laptop l[],int size){
        sort(l,l+size);
}
int main(){
    laptop l[10];
    string m,mfr;
    double p;
    for(int i=0;i<10;i++){
        cout<<i+1;
        cout<<"Enter model no:";
        cin>>m;
        cout<<"Enter price:";
        cin>>p;
        cout<<"Enter Manufacturer Name:";
        cin>>mfr;
        l[i].setmodel(m);
        l[i].setprice(p);
        l[i].setmanufact(mfr);
    }
    for(int i=0;i<10;i++){
        l[i].display();
    }
    sortbymanufacturer(l,10);
    for(int i=0;i<10;i++){
        l[i].display();
    }
}