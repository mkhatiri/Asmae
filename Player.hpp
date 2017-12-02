#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream> 

using namespace std;



class Player
{
    public:
        Player();
        Player(string nom, string prenom);
        virtual ~Player();
        void updatePlayer();
        void display();
        void init();
    protected:
    private:
        string nom;
        string prenom;
        string id;
        int point;      
};

#endif // PLAYER_HPP
