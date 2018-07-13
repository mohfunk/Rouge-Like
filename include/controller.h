#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"players.h"
#include"floor.h"
#include"game.h"
#include<string>
class Controller { 
	Game *game;		// a pointer to a game object
	Floor *floor;		// a pointer to a floor object
	Player *player;		// a pointer to a player object
	public:
	Controller(); 		// contructor
	~Controller();		// dtor
	// notifies the floor that the player is going to move
	void notify(int,int,std::string,std::string file);
	// starts the game and reads in input to notify other classes in order
	// to update the game
	void play(std::string file = "");
	// returns ture if the row and col given is the posn of an enemy false otherwise
	bool isEnemy(int,int);
};
#endif

