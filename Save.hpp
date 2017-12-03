#ifndef SAVE_HPP
#define SAVE_HPP

#include <iostream> 
#include "Player.hpp" 
#include <vector>

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
        Collection magasin;

        CartesCreature acheterUneCarteC(Collection data);
        CartesEnergie acheterUneCarteE(Collection data);
        CartesSpecial acheterUneCarteS(Collection data);
        void initDeck();
        void saveSession();
        Player player;

    protected:
    private:
       Player players[100];
       int nombrePlayers;      
};

#endif // Sava_HPP
