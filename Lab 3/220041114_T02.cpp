#include<iostream>
#include<string>
using namespace std;
class temperature{
    private:
    float val;
    string unit;
    public:
    temperature(){

    }
    void assign(float value,const string u){
        if(u=="C" || u== "F" || u=="K"){
            unit=u;
        }
        else{
            cout<<"Invalid Input"<<endl;
            return ;

        }
        if(u=="C" && value>=-273.15){
            val=value;
        }
        else if(u=="F" && value>=-459.67){
            val=value;
        }
        else if(u=="K" && value>=0){
            val=value;
        }
        else{
            cout<<"Invalid input"<<endl;
            return ;
        }
    }
    float convert(const string target){
        if(target==unit){
            return val;
        }
        if(target=="C" && unit=="F"){
            return val*(9/5)+32;
        }
        if(target=="C" && unit=="K"){
            return val-273.15;
        }
        if(target=="F" && unit=="C"){
            return (val-32)*5/9;
        }
        if(target=="F" && unit=="K"){
            return  (val-32)*5/9+273.15;
        }
        if(target=="K" && unit=="C"){
            return val+273.15;
        }
        if(target=="K" && unit=="F"){
            return (val-273.15)*9/5+32;
        }
        return 0;
    }
    void print(){
        
        cout<<"Temperature is "<<val<<" "<<unit<<endl;
    }
};
int main(){
    temperature temp;
    temp.assign(100.0,"C");
    temp.print();
    int f=temp.convert("F");
    cout<<"Temperature in Fahrenheit: "<<f<<" F"<<endl;
    int k=temp.convert("K");
    cout<<"Temperature in Kelvin: "<<k<<" K"<<endl;
    int c=temp.convert("C");
    cout<<"Temperature in Celsius: "<<c<<" C"<<endl;
}