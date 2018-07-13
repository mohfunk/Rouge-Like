#ifndef POTION_HPP
#define POTION_HPP
#include<string>
#include"item.hpp"
#include"potionstrategy.hpp"
#include"players.hpp"

class Potion: public Item{
	bool view;  		// is it visible to the player?
	PotionStrategy *ps;	// pointer to PotionStrategy obj
      public:
	Potion(PotionStrategy *);
	~Potion();
	// returns type
	// std::string getType();
	// returns view
	bool getView();
	// uses the potion on the player
	void usePotion(Player &);
	// gets the name of the potion
	std::string getName();
	// sets view to true
	void viewTrue();
};

#endif