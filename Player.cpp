#include "Player.hpp"

using namespace std;

Player::Player()
{

}

Player::Player(string nom, string prenom): nom(nom), prenom(prenom)
{
    char a = prenom[0];

    string ID = a + nom;
    id = ID;
    point = 0;
}

Player::~Player()
{
    //dtor
}

void Player::display()
{

    cout << id << " avec  " << point << " points" << std::endl;

}

void Player::updatePlayer()
{

//on mise a jour les points et les carte ici

}


void Player::init()
{

    cout << "Nom : " ;
    cin >> this->nom;
    cout << "Prenom : ";
    cin >> this->prenom;
    char pc = this->prenom[0];
    id = pc + this->nom;
    point = 0 ;

}
