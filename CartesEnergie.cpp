#include "CartesEnergie.hpp"
#include "Cartes.hpp"

using namespace std;


CartesEnergie::CartesEnergie(int id, string nom, string description, int prix, int domaine, int energie) : Cartes(id, nom, description, prix) , m_Domaine(domaine), m_Energie(energie)
{
//    cout << " -- Domaine : " << domaine << endl; 
//    cout << " -- Energie : " << energie << endl; 
}

CartesEnergie::CartesEnergie()
{
    //tor
}

CartesEnergie::~CartesEnergie()
{
    //dtor
}

void CartesEnergie::display()
{
    Cartes::display();    
    cout << "--------- Carte Creature -----------" << endl;
    cout << " -- Domaine : " << getDomaine() << endl;    // on va classifier dans un fichier le Domaine pour avoir le nom de domaine.
    cout << " -- Energie : " << getEnergie() << endl;
}

int CartesEnergie::getDomaine()
{
    return m_Domaine;
}

void CartesEnergie::setDomaine(int domaine)
{
    m_Domaine = domaine;
}

int CartesEnergie::getEnergie()
{
    return m_Energie;
}

void CartesEnergie::setEnergie(int energie)
{
    m_Energie = energie;
}










