#ifndef SAVE_HPP
#define SAVE_HPP

#include <iostream> 
#include "Player.hpp" 

using namespace std;



class Save
{
    public:
        Save();
        virtual ~Save();
        int addPlayer();
        int addPlayer(Player p);
        void display();
        
        void load_players();

    protected:
    private:
       Player *players[10];
       int nombrePlayers;      
};

#endif // PLAYER_HPP
