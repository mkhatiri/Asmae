#include <string>
#include "Save.hpp"
#include "Player.hpp"
#include "Utils.hpp"

using namespace std;

Save::Save()
{
    nombrePlayers = 0;
}

Save::~Save()
{
    //dtor
}

int Save::addPlayer()
{
    Player p;
    p.init();
    
    players[nombrePlayers] = p;

    nombrePlayers ++;
    
    cout << "nouveau joueur :" ;
    p.display();  
    return nombrePlayers;
}

int Save::addPlayer(Player p)
{
    
    players[nombrePlayers] = p;

    nombrePlayers ++;
    
    cout << "nouveau joueur :" ;
    p.display();  
    return nombrePlayers;
}

void Save::display()
{
    int i = 0;
        cout << endl;
        cout << "------------- la liste des joueurs --------------- " << endl;

        for(i = 0; i < nombrePlayers; i++){
            players[i].display();
        }
}



void Save::load_players()
{

    Utils utils ;
    int i = 0;
    vector <Player> vplayers = utils.Read_Players("player1.txt");

    for(i = 0; i< vplayers.size(); i++)
        addPlayer(vplayers[i]);
}


Player Save::getPlayer(string nom)
{
    Player p1;

    int i;
    int find = false;

    for(i=0; i<nombrePlayers; i++)
    {
        if(nom.compare(players[i].getNom()) == 0)
           {
               p1 = players[i];
               find = true;
           }
    }
    
    if(!find)
        cout << nom << " n'esite pas "<< endl;
       
    return p1;    

}


