#include "CartesSpecial.hpp"
#include "Cartes.hpp"

using namespace std;


CartesSpecial::CartesSpecial(int id, string nom, string description, bool recyclable) : Cartes(id, nom, description) , m_Recyclable(recyclable)
{
    cout << " -- carte recyclable : " << recyclable << endl; 
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










