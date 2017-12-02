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


using namespace std;



class Utils
{
    public:
        Utils();
        virtual ~Utils();
        
        // Player
        void Read_Players(string fileName);
        void Write_Player(string fileName, Player* player);
        
        
        //Cartes
        
        void Read_Cartes(string fileName);
        void Write_Carte(string fileName, Player* player);
        
        
        //

    protected:
    private:
        string m_fileName;




};

#endif // PLAYER_HPP
