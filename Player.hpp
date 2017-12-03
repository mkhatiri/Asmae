#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream> 
#include "Collection.hpp"
using namespace std;



class Player
{
    public:
        Player();
        Player(string nom, int point);
        virtual ~Player();
        void updatePlayer();
        void display();
        string getNom();
        int getPoint();

        void setNom(string nom);
        void setPoint(int point);

        void addCarteToCollection(CartesEnergie CE);
        void addCarteToCollection(CartesSpecial CS);
        void addCarteToCollection(CartesCreature CC);
        void displayCollection();  

        void init();

        Collection collection;
        Collection Deck;


        void SaveCollection();

    protected:
    private:
        string m_Nom;
        int m_Point;      
};

#endif // PLAYER_HPP
