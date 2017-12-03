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
        
        vector <CartesEnergie> Read_Cartes(string fileName, CartesEnergie CE);
        vector <CartesCreature> Read_Cartes(string fileName, CartesCreature CC);
        vector <CartesSpecial> Read_Cartes(string fileName, CartesSpecial CS);


        void Write_Carte(string fileName, Cartes* carte);
        
        
        //
        
        Player* lineToPlayer(string line);

        CartesEnergie* lineToCarte(string line, CartesEnergie CE);
        CartesSpecial* lineToCarte(string line, CartesSpecial CS);
        CartesCreature* lineToCarte(string line, CartesCreature CC );

        vector<string> split(string str, string sep);
    protected:
    private:
        string m_fileName;




};

#endif // PLAYER_HPP
