#include<iostream>
#include<string>
#include<vector>
using namespace std;
class vehicle{
    protected:
    string license_plate;
    string manufacturer;
    double carriage_limit;
    public:
    vehicle(const string& lc,const string& m,double lim): license_plate(lc),manufacturer(m),carriage_limit(lim){

    }
    virtual void maintenance()const=0;
    virtual ~vehicle(){}
};
class gasoline_vehicle:virtual public vehicle{
    protected:
    double fuel_cap;
    string fuel_type;
    public:
    gasoline_vehicle(const string& lc,const string& m,double lim,double f_cap,const string& f_type) : vehicle(lc,m,lim),fuel_cap(f_cap),fuel_type(f_type){}
    virtual ~gasoline_vehicle(){}
};
class electric_vehicle: virtual public vehicle{
    protected:
    double battery_capacity;
    double charge_time;
    public:
    electric_vehicle(const string& lc,const string& m,double lim,double cap,double time):vehicle(lc,m,lim),battery_capacity(cap),charge_time(time){}
    void maintenance() const override{
        cout<<"Electric Vehicle - maintenance"<<endl;
    }
    
};
class car:public gasoline_vehicle{
    private:
    int passengercapacity;
    public:
    car(const string& lc,const string& m,double lim,double f_cap,const string& f_type,int p_cap): vehicle(lc, m, lim),gasoline_vehicle(lc,m,lim,f_cap,f_type),passengercapacity(p_cap){}
    void maintenance() const override{
        cout<<"Car - maintenance"<<endl;
    }
};
class truck:public gasoline_vehicle{
    private:
    double cargo_cap;
    public:
    truck(const string& lc,const string& m,double lim,double f_cap,const string& f_type,double c_cap): vehicle(lc, m, lim),gasoline_vehicle(lc,m,lim,f_cap,f_type),cargo_cap(c_cap){}
    void maintenance() const override{
        cout<<"Truck - maintenance"<<endl;
    }
};
class motorcycle:public gasoline_vehicle{
    public:
    motorcycle(const string& lc,const string& m,double lim,double f_cap,const string& f_type): vehicle(lc, m, lim),gasoline_vehicle(lc,m,lim,f_cap,f_type){}
    void maintenance() const override{
        cout<<"Motorcycle - maintenance"<<endl;
    }
};
class hybrid_vehicle:public gasoline_vehicle,public electric_vehicle{
    private:
    double efficiency;
    public:
    hybrid_vehicle(const string& lc,const string& m,double lim,double f_cap,const string& f_type,double cap,double time): vehicle(lc, m, lim),gasoline_vehicle(lc,m,lim,f_cap,f_type),electric_vehicle(lc,m,lim,cap,time){}
    void maintenance() const override{
        cout<<"Hybrid Vehicle - maintenance"<<endl;
    }
};
class employee{
    protected:
    string name;
    int id;
    public:
    employee(const string& name,int id) : name(name),id(id){}
    virtual void display() const=0;
    virtual ~employee(){}
};
class driver:public employee{
    public:
    driver(const string& name,int id):employee(name,id){}
    void display() const override{
        cout<<"Name:"<<name<<endl;
        cout<<"ID:"<<id<<endl;
    }
};
class manager:public employee{
    public:
    manager(const string& name,int id):employee(name,id){}
    void display() const override{
        cout<<"Name:Mr. "<<name<<endl;
        cout<<"ID:"<<id<<endl;
    }
};

class branch{
    private:
    vector<vehicle*> vehicles;
    vector<employee*> emp;
    public:
    void addVehicle(vehicle* v){
        vehicles.push_back(v);
    }
    void addemployee(employee* e){
        emp.push_back(e);
    }
    void maintenance_all_vehicle() const{
        for(auto v:vehicles){
            v->maintenance();
        }
    }
    void displayallemployee() const{
        for(auto e:emp){
            e->display();
        }
    }
    ~branch(){
        for(auto v:vehicles){
            delete v;
        }
        for(auto e:emp){
            delete e;
        }
    }
};
int main(){
    branch br;
    cout<<"Enter for motorcycle:"<<endl;
    for(int i=0;i<10;i++){
        string lc,m,ft;
        double limit,f_cap;
        cout<<"License:";
        cin>>lc;
        cout<<"Manufacturer:";
        cin>>m;
        cout<<"Fuel type:";
        cin>>ft;
        cout<<"Carriage Limit:";
        cin>>limit;
        cout<<"Fuel capacity:";
        cin>>f_cap;
        br.addVehicle(new motorcycle(lc,m,limit,f_cap,ft));
    }
    cout<<"Enter for car"<<endl;
    for(int i=0;i<10;i++){
        string lc,m,ft;
        double limit,f_cap;
        cout<<"License:";
        cin>>lc;
        cout<<"Manufacturer:";
        cin>>m;
        cout<<"Fuel type:";
        cin>>ft;
        cout<<"Carriage Limit::";
        cin>>limit;
        cout<<"Fuel capacity:";
        cin>>f_cap;
        int pc;
        cout<<"Passenger Capacity:";
        cin>>pc;
        br.addVehicle(new car(lc,m,limit,f_cap,ft,pc));
    }
    cout<<"Enter for truck"<<endl;
    for(int i=0;i<10;i++){
        string lc,m,ft;
        double limit,f_cap;
        cout<<"License:";
        cin>>lc;
        cout<<"Manufacturer:";
        cin>>m;
        cout<<"Fuel type:";
        cin>>ft;
        cout<<"Carriage Limit:";
        cin>>limit;
        cout<<"Fuel capacity:";
        cin>>f_cap;
        double cargo_cap;
        cout<<"Cargo capacity:";
        cin>>cargo_cap;
        br.addVehicle(new truck(lc,m,limit,f_cap,ft,cargo_cap));
    }
    cout<<"Enter for electric vehicle"<<endl;
    for(int i=0;i<10;i++){
        string lc,m;
        double limit,bat_cap,time;
        cout<<"License:";
        cin>>lc;
        cout<<"Manufacturer:";
        cin>>m;
        cout<<"Carriage Limit:";
        cin>>limit;
        cout<<"Battery Capacity:";
        cin>>bat_cap;
        cout<<"Charging time:";
        cin>>time;
        br.addVehicle(new electric_vehicle(lc,m,limit,bat_cap,time));
    }
    cout<<"Enter for hybrid vehicle:"<<endl;
     for (int i = 0; i < 10; i++) {
        string lc, m, ft;
        double limit, bat_cap, time, f_cap, efficiency;
        cout << "License:";
        cin >> lc;
        cout << "Manufacturer:";
        cin >> m;
        cout << "Fuel type:";
        cin >> ft;
        cout << "Carriage Limit::";
        cin >> limit;
        cout << "Fuel capacity:";
        cin >> f_cap;
        cout << "Battery Capacity:";
        cin >> bat_cap;
        cout << "Charging time:";
        cin >> time;
        cout << "Efficiency:";
        cin >> efficiency;

        
        br.addVehicle(new hybrid_vehicle(lc, m, limit, f_cap, ft, bat_cap, time));
    }
    cout<<"Enter info of Managers:"<<endl;
    for (int i = 0; i < 10; i++) {
        string name;
        int id;
        cout << "Manager " << i + 1 << " details (name id): ";
        cin >> name >> id;
        br.addemployee(new manager(name, id));
    }
    cout<<"Enter info of drivers:"<<endl;
    for (int i = 0; i < 30; i++) {
        string name;
        int id;
        cout << "Driver " << i + 1 << " details (name id): ";
        cin >> name >> id;
        br.addemployee(new driver(name, id));
    }
    br.displayallemployee();
    br.maintenance_all_vehicle();
}

