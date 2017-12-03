#ifndef SAVE_HPP
#define SAVE_HPP

#include <iostream> 
#include "Player.hpp" 
#include<vector>

using namespace std;



class Save
{
    public:
        Save();
        virtual ~Save();
        int addPlayer();
        int addPlayer(Player p);
        void display();
        Player getPlayer(string nom); 
        void load_players();
        void load_Cartes();

    protected:
    private:
       Player players[100];
       int nombrePlayers;      
       Collection magasin;
};

#endif // PLAYER_HPP
