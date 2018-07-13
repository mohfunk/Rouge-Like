#ifndef POTIONSTRATEGY_HPP
#define POTIONSTRATEGY_HPP
#include"players.hpp"
#include<string>

class PotionStrategy{
      public:
	PotionStrategy();
	virtual ~PotionStrategy();
	// changes the players stats depending on which potion they use
	virtual void usePotion(Player &) = 0;
	// gets the name of the potion
	virtual std::string getName() = 0;
};

class RHStrategy: public PotionStrategy{
      public:
	RHStrategy();
        ~RHStrategy();
	// adds 10 HP to player and does not go over cap
	void usePotion(Player &);
	std::string getName();
};

class BAStrategy: public PotionStrategy{
      public:
        BAStrategy();
        ~BAStrategy();
        // adds 5 atk to player for one floor
        void usePotion(Player &);
	std::string getName();
};

class BDStrategy: public PotionStrategy{
      public:
        BDStrategy();
        ~BDStrategy();
        // adds 5 def to player for one floor
        void usePotion(Player &);
	std::string getName();
};

class PHStrategy: public PotionStrategy{
      public:
        PHStrategy();
        ~PHStrategy();
        // removes 10 HP to player and player HP does not go below 0
        void usePotion(Player &);
	std::string getName();
};

class WAStrategy: public PotionStrategy{
      public:
        WAStrategy();
        ~WAStrategy();
        // removes 5 atk to player for one floor
        void usePotion(Player &);
	std::string getName();
};

class WDStrategy: public PotionStrategy{
      public:
        WDStrategy();
        ~WDStrategy();
        // removes 5 def to player for one floor
        void usePotion(Player &);
	std::string getName();
};


#endif
