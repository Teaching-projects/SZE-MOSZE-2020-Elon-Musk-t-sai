#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

typedef unsigned int uint_t;

class Player{
    public:
    Player(const uint_t hp, const uint_t dmg, const std::string n):health(hp),damage(dmg),name(n){
    
    }
    Player(){

    }
    static int jsonParser(const std::string path){
        
        int result = 0;
        std::string line;
        std::ifstream json_file(path);
        if(json_file.is_open()){
            
            char s1[] = {'\"',' ',',',':'};

            result = 1;
            int position = 0;
            while (std::getline(json_file, line))
            {
                
                if (position == 0 || position == 4)
                {
                    position+=1;
                    continue;
                }
                
                std::string delimiter = ":";
                std::string token = line.substr(line.find(delimiter),line.length()-1);
                for (size_t i = 0; i < 4; i++)
                {
                    token.erase(std::remove(token.begin(),token.end(),s1[i]),token.end());
                }
                std::cout << token << std::endl;
                position+=1;
                
            }

        }

        return result;
    }

    const uint_t getHealth();

    const uint_t getDamage();
    
    void receivedDamage(const Player p); 

    const std::string getName();

    private:
    uint_t health;
    uint_t damage;
    std::string name;
};
    
#endif //PLAYER_HPP//