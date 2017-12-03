#include "CartesSpecial.hpp"
#include "Cartes.hpp"

using namespace std;


CartesSpecial::CartesSpecial(int id, string nom, string description, int prix, bool recyclable, int effet) : Cartes(id, nom, description, prix) , m_Recyclable(recyclable), m_effet(effet)
{
    cout << " -- carte recyclable : " << recyclable << endl; 
}


CartesSpecial::CartesSpecial()
{
    //ctor
}

CartesSpecial::~CartesSpecial()
{
    //dtor
}

void CartesSpecial::display()
{
    Cartes::display();    
    cout << "--------- Carte Speacial -----------" << endl;
    cout << " -- carte recyclable : " << isRecyclable() << endl; 
    cout << " -- Effet : " << getEffet() << endl; 
}

bool CartesSpecial::getRecyclable()
{
    return m_Recyclable;
}

void CartesSpecial::setRecyclable(bool recyclable)
{
    m_Recyclable = recyclable;
}


bool CartesSpecial::isRecyclable()
{
    return getRecyclable();
}

int CartesSpecial::getEffet()
{
    return m_effet;
}








