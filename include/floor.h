#ifndef FLOOR_H
#define FLOOR_H
#include "characters.h"
#include "players.h"
#include <string>
#include "textdisplay.h"
#include "game.h"
#include "potion.h"
#include "potionstrategy.h"
#include "gold.h"
#include "enemies.h"
class Floor{
	Player *player;		// pointer to a player object
	std::string action;	// action to be printed
	int floornum;		// current floor
	TextDisplay *td;	// poitner to a textDisplay object
	Game *game;		// pointer to a game object
	Potion **potion;	// array of potion pointers
	Gold **gold;		// array of gold pointers
	Enemy **enemy;		// array of enemy pointers
	Dragon **dragon;	// array of dragon pointers
	// returns true if the space can be occupied, false otherwise
	bool isValid(int, int);
	// sets the character to a random valid point on the floor
	void setInitialPosn(Player &, char exit = 0);
	bool RH; 		// determines if Restore Health potions visible
	bool BA;		// determines if Boost Attack   potions visible
	bool BD;		// determines if Boost Defence  potions visible
	bool PH;		// determines if Poison Health  potions visible
	bool WA;		// determines if Wound Attack   potions visible
	bool WD;		// determines if Wound Defence  potions visible
	bool HostilM;		// determines if merchants are hostile
	int countp;		// number of potions on the floor to free
	int countg;		// number of gold    on the floor to free
	int counte;		// number of enemies on the floor to free
	int countd; 		// number of dragons on the floor to free
	int capp;   		// maximum capacity to the potions array
	int capg;   		// maximum capacity to the gold    array
	int cape;   		// maximum capacity to the enemies array
	int capd;  		// maximum capacity to the dragon  array
      public:
	Floor(Player &, Game &, std::string file); // constructor
	~Floor(); // dtor
	// Prints the floor by calling td and prints character stats
	void printFloor();
	// sets the position on the floor with the char
	void setPoint(int, int, Player &, std::string file);
	// notification on player movement that is recieved from controller and
	// updates players position
	void notify(int row, int col, std::string input, std::string file);
	// changes the string action with a new string
	void setAction(std::string);
	// returns the floornum
	int getFloornum();
	// returns a random int corresponding to a chamber
	int chamber(int cham = -1);
	// returns a random int corresponding to the row
	int row(int);
	// returns a random int corresponding to the column
	int Col(int, int);
	// resets the floor and does the random generation of objects
	// and there placement on the floor
	void reset(std::string file);
	// uses the potion that is on the given row and column
	void usePotion(int,int);
	// gets the char for the given row and col of the floor 
	char getCell(int,int);
	// checks the surrounding cells of the player for potions
	void checkForP();
	// helper for checkForP
	void checkHelp(int, int);
	// sets the potions with given names to true
	void setPotionsTrue(std::string);
	// returns true if the given coords contain a dot entity
	bool isDot(int, int);
	// returns true if a player exists in one unit radius from the given coords 
	bool nearByPlayer(int,int);
	// returns true if there's at least one dot entity withing a one unit radius from the given coords
	bool canMove(int,int);
	// Handles the enenmy movement behaviour
	void MoveEnemy(Enemy&);
	// manages enemy behaviour
	void Enemybeh();
	// manages player attack system
	void PlayerAtk(int,int);
	// manages Enemy attack system
	void EnemyAtk(Enemy &);
	// sets coords for a dragon around a dragon hords
	void setDragon(Dragon&, int, int);
	// returns true if there is a dragon within one unit radius from the given coords
	bool isDragonNear(int,int);
	// needed for spawning dragons from files
	// checks if the given coords are in one unit radius from each other 
	bool isOneRad(int,int,int,int);
};

#endif
