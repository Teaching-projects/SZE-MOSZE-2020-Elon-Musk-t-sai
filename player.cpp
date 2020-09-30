#include "player.hpp"


    uint_t Player::getHealth() const{
        return health;
    }
    uint_t Player::getDamage() const{
        return damage;
    }
    
    void Player::receivedDamage(Player p){
        const uint_t dmg = p.getDamage();
        if(health>dmg){
            health = health - dmg;
        }else         {
            health=0;
        }
          
    }
    std::string Player::getName() const{
        return name;
    }

