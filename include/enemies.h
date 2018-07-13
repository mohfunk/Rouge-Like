#ifndef ENEMIES_H
#define ENEMIES_H
#include "characters.h"
#include "players.h"
#include <string>
class Enemy: public Character{
	bool hasMoved;	// a boolean to help us in the EnemyBeh method of floor.
	public:
	Enemy(int,int,int,int,int,std::string,int,char,char); // ctor
	~Enemy(); // dtor
	void setMoved(bool); // setter for hasMoved
	bool getMoved();     // getter for hasMoved
};

class Human: public Enemy{
      public:
	Human(); // constructor
	~Human(); //dtor
};

class Dwarf: public Enemy{
      public:
	Dwarf(); // constructor
        ~Dwarf(); //dtor
};

class Elf: public Enemy{
      public:
	Elf(); // constructor
        ~Elf(); //dtor
};
class Halfling: public Enemy{
	public:
	Halfling();
	~Halfling();
};
class Orc: public Enemy{
      public:
        Orc(); // constructor
        ~Orc(); //dtor
};

class Merchant: public Enemy{
      public:
        Merchant(); // constructor
        ~Merchant(); //dtor
};

class Dragon: public Enemy{
	int GoldRow;
	int GoldCol;
      public:
	int getGoldRow();
	int getGoldCol();
        Dragon(int,int); // constructor
        ~Dragon(); //dtor
};

#endif
