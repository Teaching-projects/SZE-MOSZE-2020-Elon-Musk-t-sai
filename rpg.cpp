#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

typedef unsigned int uint_t;

class player{
    public:
    player(uint_t hp, uint_t dmg, string n):health(hp),damage(dmg),name(n){
    
    }
    uint_t getHealth(){
        return health;
    }
    uint_t getDamage(){
        return damage;
    }
    
    void receivedDamage(uint_t dmg){

        if(health>dmg){
            health = health - dmg;
        }else if(dmg>=health)
        {
            health=0;
        }
        cout << name << " Received damage: " << dmg << " Health remaining: " << health <<endl; 
       
        if(health==0){
            cout << name << " lost all Healthpoint." << endl;
        }   
    }
    string getName(){
        return name;
    }
    private:
    uint_t health;
    uint_t damage;
    string name;
};

class game{
    public:
    game(player p1, player p2):player1(p1),player2(p2){}
    void play(){
        cout << player1.getName() << " HP: " << player1.getHealth() << " DMG: " << player1.getDamage() << endl;
        cout << player2.getName() << " HP: " << player2.getHealth() << " DMG: " << player2.getDamage() << endl;
        while (player1.getHealth()!=0 && player2.getHealth()!=0)
        {
            cout << player1.getName() << " -> " << player2.getName() << endl;
            player2.receivedDamage(player1.getDamage());
            if(player2.getHealth() ==0){
                break;
            }
            cout << player2.getName() << " -> " << player1.getName() << endl;
            player1.receivedDamage(player2.getDamage());
        }
        
    }
    private:
    player player1, player2;
};

int main(int argc,char *argv[]){
    
    uint_t player1hp;
    uint_t player2hp;
    uint_t player1dmg;
    uint_t player2dmg;

    player1hp = atoi(argv[2]);
    player1dmg = atoi(argv[3]);
    player2hp = atoi(argv[5]);
    player2dmg = atoi(argv[6]);


    player p1 = player(player1hp, player1dmg, string(argv[1]));
    player p2 = player(player2hp, player2dmg, string(argv[4]));
    game g=game(p1,p2);
    g.play();

    return 0;
}