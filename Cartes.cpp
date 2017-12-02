#include "Cartes.hpp"

using namespace std;


Cartes::Cartes(int id, string nom, string description): m_nom(nom) , m_description(description), m_id(id)
{
    cout << "new Carte : " << endl;
    cout << " - Nom : " << nom << endl;
    cout << " - Description : " << description << endl;     
}

Cartes::Cartes()
{
    //dtor
}


Cartes::~Cartes()
{
    //dtor
}

void Cartes::display()
{
    cout << "Nom : " << getNom() << endl;
    cout << "Description : " << getDescription() << endl;     

}

string Cartes::getNom()
{
    return m_nom;
}

void Cartes::setNom(string nom)
{
    m_nom = nom;
}

string Cartes::getDescription()
{
    return m_description;
}

void Cartes::setDescription(string description)
{
    m_description = description;
}










