#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include<string>

#include"players.hpp"
#include"floor.hpp"
#include"game.hpp"


class Controller { 
    private:
        Game*   game;		
        Floor*  floor;
        Player* player;

    public:
        Controller();
        ~Controller();
        void notify(int,int,std::string,std::string file);
        void play(std::string file = "");
        bool isEnemy(int,int);
};
#endif

