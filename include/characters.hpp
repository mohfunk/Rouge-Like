#ifndef CHARACTERS_HPP
#define CHARACTERS_HPP
#include <string>
//class Floor;
class Character{
//friend class Floor;
      private:
	int HP;
	int Atk;
	int Def;
	int row; 		// row position of charactor on the board
	int column; 		// column position of charactor on the board
	std::string race;	// race name
	int Gold;
	char prev;
	char symbol;		 // symbol that represents the character on the floor
      public:
	Character(int, int, int, int, int, std::string, int, char, char); // constructor
	virtual ~Character(); // dtor
	// returns the characters health
	int getHP();
	// changes the characters HP when taking damage or when healing 
	void setHP(int);
	// returns the characters defence
	int getDef();
	// changes the characters defence when they have taken a bad potion
	void setDef(int);
	// returns the characters attack
	int getAtk();
	// changes the characters attack when they have taken a bad potion
	void setAtk(int);
	// returns the characters row position
        int getRow();
        // changes the characters row position
        void setRow(int);
	// returns the characters column position
        int getCol();
        // changes the characters column position
        void setCol(int);
	// returns the characters race
	std::string getRace();
	// returns the characters gold amount
        int getGold();
        // changes the characters gold amount
        void setGold(int);
	// returns the prev state of the floor
        char getPrev();
        // changes the what the state of the floor was before the character moved there
        void setPrev(char);
	// returns the characters symbol
	char getSymbol();
	// returns true if HP = 0
	bool isDead();
};

#endif
