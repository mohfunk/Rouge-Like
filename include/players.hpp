#ifndef PLAYERS_HPP
#define PLAYERS_HPP
#include "characters.hpp"
#include <string>

//class Floor;
// Player is the base class for playable characters
class Player: public Character{
//friend class Floor;
	int cham;
	int maxHP;
      public:	
	Player(int, int, int, int, int, std::string, int, char, char, int, int); // constructor
	~Player(); // dtor
	// changes atk and def to the values given
	virtual void resetAD();
	// returns maxHP
	int getMaxHP();
};

// Shade is a character with 125 HP, 25 Atk, 25 Def and no other features
class Shade: public Player{
      public:
	Shade(); // constructor
	~Shade(); // dtor
	// resets atk and def to base stats
	void resetAD();
};

// Drow is a character with 150 HP, 25 Atk, 15 Def and all potions are 
// magnified by 1.5
class Drow: public Player{
      public:
        Drow(); // constructor
        ~Drow(); // dtor
        // resets atk and def to base stats
	void resetAD();
};

// Vampire is a character with 50 HP, 25 Atk, 25 Def and gains 5 HP every
// attack and has no max hp
class Vampire: public Player{
      public:
        Vampire(); // constructor
        ~Vampire(); // dtor
        // resets atk and def to base stats
	void resetAD();
};

// Troll is a character with 120 HP, 25 Atk, 15 Def and gains 5HP every turn
class Troll: public Player{
      public:
        Troll(); // constructor
        ~Troll(); // dtor
        // resets atk and def to base stats
	void resetAD();
};

// Goblin is a character with 110 HP, 15 Atk, 20 Def and steals 5 gold from
// every enemy slain
class Goblin: public Player{
      public:
        Goblin(); // constructor
        ~Goblin(); // dtor
        // resets atk and def to base stats
	void resetAD();
};

#endif
