#include "CartesCreature.hpp"
#include "Cartes.hpp"

using namespace std;



CartesCreature::CartesCreature(int id, string nom, string description, int prix ,int lp, int hp) : Cartes(id, nom, description, prix) , m_Lp(lp), m_Hp(hp)
{
    cout << " -- Life Points : " << lp << endl; 
    cout << " -- Hit Points : " << hp << endl; 
}


CartesCreature::CartesCreature()
{
    //dtor
}



CartesCreature::~CartesCreature()
{
    //dtor
}

void CartesCreature::display()
{
    Cartes::display();    
    cout << "--------- Carte Creature -----------" << endl;
    cout << " -- Life Points : " << getLp() << endl;
    cout << " -- Hit Points : " << getHp() << endl;
    cout << "----------- les attaques possible ----------------" << endl;
    cout << "--------- TO DO ------------------------------- " <<endl;
}

int CartesCreature::getLp()
{
    return m_Lp;
}

void CartesCreature::setLp(int lp)
{
    m_Lp = lp;
}

int CartesCreature::getHp()
{
    return m_Hp;
}

void CartesCreature::setHp(int hp)
{
    m_Hp = hp;
}










