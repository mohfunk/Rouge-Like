#ifndef GAME_HPP
#define GAME_HPP

#include "players.hpp"
#include "enemies.hpp"
#include "characters.hpp"

class Game{
    public:
        Game();
        ~Game();
        int random(int range);
        void EnemyDamage(Player&, Character&);
        void PlayerDamage(Player&, Character&);
        bool Probability(int, int);
};

#endif
