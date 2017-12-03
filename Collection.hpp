#ifndef COLLECTION_HPP
#define COLLECTION_HPP
#include "Cartes.hpp"

#include "CartesEnergie.hpp"
#include "CartesCreature.hpp"
#include "CartesSpecial.hpp"
#include<vector>

#include <iostream> 
using namespace std;

class Collection
{
    public:
        Collection();
        virtual ~Collection();
        string getType();

        vector <CartesEnergie> cartes_Energies; 
        vector <CartesCreature> cartes_Creatures; 
        vector <CartesSpecial> cartes_Speciales; 

        void setCartes(CartesEnergie CE);
        void setCartes(CartesCreature CC);
        void setCartes(CartesSpecial CS);

        void getCartes(int id);
        void display();

    protected:
    private:

        int nombre_Cartes;
};

#endif // COLLECTION_HPP
