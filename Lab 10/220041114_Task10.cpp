#include<iostream>
#include<string>
#include<vector>
using namespace std;
class BaseCharacter; 
class BossEnemy{
    private:
    string name;
    int health;
    int attack_power;
    public:
    BossEnemy() : name("Boss"),health(150),attack_power(30){}
    void attack(BaseCharacter& b);
    void damage(int d);
    bool alive(){
        return health>0;
    }
};
class CharacterActions{
    public:
    virtual void attack(BossEnemy& boss)=0;
    virtual void defend(int damage)=0;
    virtual void useSpecialAbility(BossEnemy& boss)=0;
    virtual void displayStats()=0;
    virtual ~CharacterActions() {}
};
class BaseCharacter:public CharacterActions{
    protected:
    string name;
    int health;
    int mana;
    int attack_power;
    string special_ability;
    int special_ability_power;
    bool used;
    public:
    BaseCharacter(string n,int h,int m,int at,string ability,int power) : name(n),health(h),mana(0),attack_power(at),special_ability(ability),special_ability_power(power){}
    void attack(BossEnemy& boss) override{
        cout<<name<<" attacks with power "<<attack_power<<" !"<<endl;
       boss.damage(attack_power);
        mana+=50;
        used=false;
    }
    void defend(int damage) override{
        cout<<name<<" defends.Attack blocked.Health now:"<<health<<endl;
    }
    void useSpecialAbility(BossEnemy& boss) override{
        if(mana>=100){
            cout<<name<<" uses "<<special_ability<<" with power "<<special_ability_power<<" !"<<endl;
            boss.damage(special_ability_power);
            mana=0;
            used=true;
        }
        else{
            cout << name << " does not have enough mana to use " << special_ability << "!" << endl;
        }
    }
    void displayStats() override{
        cout<<"Name: "<<name<<endl;
        cout<<"Health: "<<health<<endl;
        cout<<"Mana: "<<mana<<endl;
    }
    void damage(int d){
        health-=d;
        cout<<name<<" takes "<<d<<" damage! Health now: "<<health<<endl;
    }
    bool alive(){
        return health>0;
    }
    const string& getname(){
        return name;
    }
    int get_attack(){
        if(used){
            used=false;
            return special_ability_power;
        }
        else{
            return attack_power;
        }
    }
    int getmana(){
        return mana;
    }
    virtual ~BaseCharacter() {}

};
class Warrior:public BaseCharacter{
    public:
    Warrior(): BaseCharacter("Warrior",100,0,25,"Berserk Rage",35){}


};
class Archer: public BaseCharacter{
    public:
    Archer(): BaseCharacter("Archer",120,0,20,"Arcane Blast",35){}
};
class Mage: public BaseCharacter{
    public:
    Mage(): BaseCharacter("Mage",90,0,20,"Fire Arrow",30){}
};
void BossEnemy::attack(BaseCharacter &b)
{
    cout << name << " attacks " << b.getname() << " with power " << attack_power << "!" << endl;
    b.damage(attack_power);
}
void BossEnemy::damage(int d)
{
    health-=d;
    cout<<name<<" takes "<<d<<" damage! Health now: "<<health<<endl;
}
class gameEngine
{
private:
    vector<BaseCharacter*> players;
    BossEnemy Boss;
    public:
    gameEngine(const vector<BaseCharacter*>& p,BossEnemy& b): players(p),Boss(b){}
    void playgame(){
        cout<<"Game begins! Players vs. Boss"<<endl;
        while(Boss.alive()){
            for(auto& p:players){
                if(!p->alive()){
                    cout<<"Game Over"<<endl;
                    return;
                }
                p->attack(Boss);
                if(p->getmana()>=100){
                    p->useSpecialAbility(Boss);
                    
                    if(!Boss.alive()){
                        cout<<"Boss defeated! Players win!"<<endl;
                        return;
                    }
                }
            }
            for(auto& p:players){
                if(Boss.alive() && p->alive()){
                    Boss.attack(*p);
                    if(!p->alive()){
                        cout<<"Game Over"<<endl;
                        return;
                    }
                }
            }
        }
    }
    ~gameEngine(){
        for(auto p:players){
            delete p;
        }
        
    }
};
int main(){
    vector<BaseCharacter*> players;
    BossEnemy Boss;
    players.push_back(new Warrior());
    players.push_back(new Archer());
    players.push_back(new Mage());
    gameEngine ge(players,Boss);
    ge.playgame();
}
