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



