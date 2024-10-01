#include<iostream>
#include<string>
using namespace std;
class flightinfo{
    private:
    int flight_no;
    string destination;
    double distance;
    double MaxfuelCapacity;
    double CalFuel(double distance){
        if(distance<=1000.0){
            return 500.0;
        }
        else if(distance>1000.0 && distance<=2000.0){
            return 1100.0;
        }
        else{
            return 2200.0;
        }
    }
    public:
    void FeedInfo(int a,const string dest,float dist,float m){
        flight_no=a;
        destination=dest;
        distance=dist;
        MaxfuelCapacity=m;
    }
    void ShowInfo(){
        cout<<"Flight Number :"<<flight_no<<endl;
        cout<<"Destination :"<<destination<<endl;
        cout<<"Distance :"<<distance<<endl;
        cout<<"Required fuel :"<<CalFuel(distance)<<endl;
        if(MaxfuelCapacity<CalFuel(distance)){
            cout<<"Not sufficient Fuel Capacity for this flight."<<endl;
        }
        else{
            cout<<"Fuel capacity is fit for this flight distance"<<endl;
        }
    }
};
int main(){
    flightinfo flight;
    flight.FeedInfo(100,"Dhaka",2200,2000);
    flight.ShowInfo();
}