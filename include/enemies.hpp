#ifndef ENEMIES_HPP
#define ENEMIES_HPP

#include <string>

#include "characters.hpp"
#include "players.hpp"



class Enemy: public Character {
    private:
        bool hasMoved;	
    public:
        Enemy(int,int,int,int,int,std::string,int,char,char);
        ~Enemy();
        void setMoved(bool);
        bool getMoved(); 
};

class Human: public Enemy {
    public:
        Human();
        ~Human();
};

class Dwarf: public Enemy {
    public:
        Dwarf();
        ~Dwarf();
};

class Elf: public Enemy {
    public:
        Elf();
        ~Elf();
};
class Halfling: public Enemy {
    public:
        Halfling();
        ~Halfling();
};
class Orc: public Enemy {
    public:
        Orc();
        ~Orc();
};

class Merchant: public Enemy {
    public:
        Merchant();
        ~Merchant();
};

class Dragon: public Enemy {
    private:
        int GoldRow;
        int GoldCol;
    public:
        int getGoldRow();
        int getGoldCol();
        Dragon(int,int);
        ~Dragon();
};

#endif
