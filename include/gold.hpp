#ifndef GOLD_HPP
#define GOLD_HPP
#include"item.hpp"
#include<string>

class Gold: public Item{
	std::string type; // mechant gold, dragon gold, smile pile, normal pile
	int value;
	bool deadDragon; // IS THE DRAGON DEAD?	used to implement the dragon/dragonHord logic
	bool isTied;	 // IS THIS DRAGONHORD TIED TO AN ALIVE DRAGON? same as above
      public:
	// ctor
	Gold(std::string);
	// dtor
	~Gold();
	// returns the value
	int getValue();
	// returns the type
	std::string getType();
	// sets deadDragon to true;
	void DragonIsDead();
	// returns deadDragon
	bool canTake();
	// setter for isTied
	void setIsTied(bool);
	// getter for isTied
	bool getIsTied();
};

#endif
