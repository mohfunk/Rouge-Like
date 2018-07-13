#ifndef GAME_H
#define GAME_H
#include "players.h"
#include "enemies.h"
#include "characters.h"

class Game{
      public:
	Game();// constructor
	~Game();// dtor
	// returns an integer from 0 the the range minus 1
	int random(int range);
	// deacreases the enemies hp by the amount of dameage they recieve
	void EnemyDamage(Player&, Character&);
	// decreases the players hp by the amount of damage they recieve
	void PlayerDamage(Player&, Character&);
	// a utility method that checks if the number given equals the other number which is
	// random
	bool Probability(int, int);
};

#endif
