#include "Cartes.hpp"
#include "CartesEnergie.hpp"
#include "CartesCreature.hpp"
#include "CartesSpecial.hpp"
#include "Collection.hpp"
#include<vector>

using namespace std;


Collection::Collection()
{
    nombre_Cartes = 0;
}

Collection::~Collection()
{
    //dtor
}

void Collection::setCartes(CartesEnergie CE)
{
    
    cartes_Energies.push_back(CE);
    nombre_Cartes++;
}

void Collection::setCartes(CartesSpecial CE)
{
    
    cartes_Speciales.push_back(CE);
    nombre_Cartes++;
}

void Collection::setCartes(CartesCreature CE)
{
    
    cartes_Creatures.push_back(CE);
    nombre_Cartes++;
}


void Collection::display()
{
   int i=0; 
    cout << " ******* Cartes Energie *********** " << endl; 
    
    for(i=0; i<cartes_Energies.size(); i++)
        cartes_Energies[i].display();

    cout << " ******* Cartes Special *********** " << endl; 
    for(i=0; i<cartes_Speciales.size(); i++)
        cartes_Speciales[i].display();

    cout << " ******* Cartes Creature *********** " << endl; 
    for(i=0; i<cartes_Creatures.size(); i++)
        cartes_Creatures[i].display();


}
