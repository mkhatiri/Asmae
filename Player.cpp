#include "Player.hpp"

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

    cout << m_Nom << " avec  " << m_Point << " points" << std::endl;

}

void Player::updatePlayer()
{

//on mise a jour les points et les carte ici

}


void Player::init()
{

    cout << "Nom : " ;
    cin >> this->m_Nom ;
    setPoint(0) ;

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


