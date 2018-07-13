#ifndef PLAYERS_HPP
#define PLAYERS_HPP
#include <string>

#include "characters.hpp"

// Player is the base class for playable characters
class Player: public Character{
    private:
        int cham;
        int maxHP;
    public:	
        Player(int, int, int, int, int, std::string, int, char, char, int, int);
        ~Player();
        virtual void resetAD();
        int getMaxHP();
};

// Shade is a character with 125 HP, 25 Atk, 25 Def and no other features
class Shade: public Player{
    public:
        Shade(); 
        ~Shade(); 
        void resetAD();
};

// Drow is a character with 150 HP, 25 Atk, 15 Def and all potions are 
// magnified by 1.5
class Drow: public Player{
    public:
        Drow(); 
        ~Drow(); 
        void resetAD();
};

// Vampire is a character with 50 HP, 25 Atk, 25 Def and gains 5 HP every
// attack and has no max hp
class Vampire: public Player{
    public:
        Vampire();
        ~Vampire(); 
        void resetAD();
};

// Troll is a character with 120 HP, 25 Atk, 15 Def and gains 5HP every turn
class Troll: public Player{
    public:
        Troll(); 
        ~Troll(); 
        void resetAD();
};

// Goblin is a character with 110 HP, 15 Atk, 20 Def and steals 5 gold from
// every enemy slain
class Goblin: public Player{
    public:
        Goblin(); 
        ~Goblin(); 
        void resetAD();
};

#endif
