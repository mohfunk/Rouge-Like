#ifndef POTIONSTRATEGY_HPP
#define POTIONSTRATEGY_HPP

#include<string>

#include"players.hpp"

class PotionStrategy{
    public:
        PotionStrategy();
        virtual ~PotionStrategy();
        virtual void usePotion(Player &) = 0;
        virtual std::string getName() = 0;
};

class RHStrategy: public PotionStrategy{
    public:
        RHStrategy();
        ~RHStrategy();
        void usePotion(Player &);
        std::string getName();
};

class BAStrategy: public PotionStrategy{
    public:
        BAStrategy();
        ~BAStrategy();
        void usePotion(Player &);
        std::string getName();
};

class BDStrategy: public PotionStrategy{
    public:
        BDStrategy();
        ~BDStrategy();
        void usePotion(Player &);
        std::string getName();
};

class PHStrategy: public PotionStrategy{
    public:
        PHStrategy();
        ~PHStrategy();
        void usePotion(Player &);
        std::string getName();
};

class WAStrategy: public PotionStrategy{
    public:
        WAStrategy();
        ~WAStrategy();
        void usePotion(Player &);
        std::string getName();
};

class WDStrategy: public PotionStrategy{
    public:
        WDStrategy();
        ~WDStrategy();
        void usePotion(Player &);
        std::string getName();
};


#endif
