#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>

typedef unsigned int uint_t;

class Player{
    public:
    Player(const uint_t hp, const uint_t dmg, const std::string n):health(hp),damage(dmg),name(n){
    
    }
    uint_t getHealth() const;

    uint_t getDamage() const;
    
    void receivedDamage(const Player p); 

    std::string getName() const;

    private:
    uint_t health;
    const uint_t damage;
    const std::string name;
};
#endif //PLAYER_HPP//






