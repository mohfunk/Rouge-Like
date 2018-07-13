#ifndef POTION_HPP
#define POTION_HPP

#include<string>

#include"item.hpp"
#include"potionstrategy.hpp"
#include"players.hpp"

class Potion: public Item{
    private:
        bool view;  		
        PotionStrategy *ps;	
    public:
        Potion(PotionStrategy *);
        ~Potion();
        bool getView();
        void usePotion(Player &);
        std::string getName();
        void viewTrue();
};

#endif
