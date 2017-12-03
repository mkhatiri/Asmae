#include "Player.hpp"
#include "Utils.hpp"

using namespace std;

Player::Player()
{

}

Player::Player(string nom, int point=0): m_Nom(nom), m_Point(point)
{

}

Player::~Player()
{
    //dtor
}

void Player::display()
{

    cout << "Nom du joueur : " << m_Nom ;
    cout << " avec " << m_Point << " Points de vie  "  << endl;

    displayCollection();
}

void Player::updatePlayer()
{

//on mise a jour les points et les carte ici

}


void Player::init()
{

    cout << "Donner le Nom : " ;
    cin >> this->m_Nom ;
    setPoint(30);
    
    cout << "nouveau : ";

    display();


}


string Player::getNom()
{

    return m_Nom;

}


void Player::setNom(string nom)
{

    m_Nom = nom ;

}


int Player::getPoint()
{

    return m_Point;

}

void Player::setPoint(int point)
{

    m_Point = point ;

}


void Player::addCarteToCollection(CartesEnergie CE)
{
    collection.setCartes(CE);
}


void Player::addCarteToCollection(CartesSpecial CS)
{
    collection.setCartes(CS);
}

void Player::addCarteToCollection(CartesCreature CC)
{
    collection.setCartes(CC);
}


void Player::displayCollection()
{
    int i;

    cout <<" *************  " <<  " Carte Energie ************* "<< endl;
    for(i==0; i< collection.cartes_Energies.size(); i++)
        collection.cartes_Energies[i].display();
    

    cout <<" ************* "<<   " Carte Speacial ************ "<< endl;
    for(i==0; i< collection.cartes_Speciales.size(); i++)
        collection.cartes_Speciales[i].display();


    cout <<" *************  Carte Creature ************* "<< endl;
    for(i==0; i< collection.cartes_Creatures.size(); i++)
        collection.cartes_Creatures[i].display();
}


void Player::SaveCollection()
{

    int i=0;

    cout << "Save Carte Creature ........ " << endl;;
    string fileName = "Data/" + getNom() + "C.txt";
    Utils utils;
    utils.Write_Carte(fileName, collection.cartes_Creatures);
    cout << "Cartes Creature sauvgarder !!!!!!!!! " << endl; 

    cout << "Save Carte Special ........ " << endl;;
    fileName = "Data/" + getNom() + "S.txt";
    utils.Write_Carte(fileName, collection.cartes_Speciales);
    cout << "Cartes Special sauvgarder !!!!!!!!! " << endl; 

    cout << "Save Carte Energie ........ " << endl;;
    fileName = "Data/" + getNom() + "E.txt";
    utils.Write_Carte(fileName, collection.cartes_Energies);
    cout << "Cartes Energie sauvgarder !!!!!!!!! " << endl; 

}
