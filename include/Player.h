#ifndef PLAYER_H
#define PLAYER_H


class Player
{
    public:
        Player(string nom, string prenom);
        virtual ~Player();

        display();

    protected:
    private:
        string nom;
        string prenom;
        string id;
        string password;
};

#endif // PLAYER_H
