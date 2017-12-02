#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream> 
#include "Player.hpp"
#include "Save.hpp"
#include "Cartes.hpp"
#include "CartesEnergie.hpp"
#include "CartesCreature.hpp"
#include "CartesSpecial.hpp"
#include <fstream>
#include<vector>

using namespace std;



class Utils
{
    public:
        Utils();
        virtual ~Utils();
        
        // Player
        vector <Player>  Read_Players(string fileName);
        void Write_Player(string fileName, Player* player);
        
        
        //Cartes
        
        vector <Cartes> Read_Cartes(string fileName, int type);
        void Write_Carte(string fileName, Cartes* carte);
        
        
        //
        
        Player* lineToPlayer(string line);
        Cartes* lineToCarte(string line, int type);

        vector<string> split(string str, string sep);
    protected:
    private:
        string m_fileName;




};

#endif // PLAYER_HPP
