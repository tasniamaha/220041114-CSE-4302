#include<iostream>
using namespace std;
class Calculator{
    private:
    int ans;
    void set(int a){
        ans=a;
    }
    int get(){
        return ans;
    }
    public:
    Calculator(){
        ans=0;
    }
    ~Calculator(){
        
        cout<<"0"<<endl;
        cout<<"Destructor of the Calculator object is called."<<endl;
    }
    void add(int a){
        set(ans+a);
        
    }
    void subtract(int a){
        set(ans-a);
       
    }
    void multiply(int a){
        set(ans*a);
        
    }
    int divideBy(int a){
        if(a==0){
            cout<<"Invalid arithmetic operation."<<endl;
            return -1;
        }
        else{
            int rem=get()%a;
            set(get()/a);
            return rem;
        }
    }
    void display(){
        
        cout<<"Calculator display: "<<get()<<endl;
    }
    
    
    void clear(){
        set(0);
        
    }
};
int main(){
    Calculator calc;
    calc.add(10);
    calc.display();
    calc.subtract(7);
    calc.display();
    calc.multiply(31);
    calc.display();
    calc.subtract(42);
    calc.display();
    calc.divideBy(7);
    calc.display();
    calc.divideBy(0);
    calc.display();
    calc.add(7);
    calc.display();
    calc.clear();
    calc.display();
}