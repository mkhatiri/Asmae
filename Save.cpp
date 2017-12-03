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
    
  //  cout << "nouveau joueur :" ;
  //  p.display();  
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

        cout << "------------- la liste des Cartes --------------- " << endl;

        magasin.display(); 
}




void Save::load_players()
{

    Utils utils ;
    int i = 0;
    vector <Player> vplayers = utils.Read_Players("Data/Players.txt");

    for(i = 0; i< vplayers.size(); i++)
        addPlayer(vplayers[i]);
}


Player Save::getPlayer(string nom)
{
    Player p1;

    int i;
    int find = false;

    for(i=0; i<nombrePlayers-1; i++)
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

void Save::load_Cartes()
{

    Utils utils ;
    int i = 0;

    CartesCreature CC;
    CartesSpecial CS;
    CartesEnergie CE;


    vector <CartesCreature> vCC = utils.Read_Cartes("Data/CarteCreature.txt", CC);
    for(i = 0; i< vCC.size(); i++)
        magasin.setCartes(vCC[i]);


    vector <CartesSpecial> vCS = utils.Read_Cartes("Data/CarteSpecial.txt", CS);
    for(i = 0; i< vCS.size(); i++)
        magasin.setCartes(vCS[i]);

    vector <CartesEnergie> vCE = utils.Read_Cartes("Data/CarteEnergie.txt", CE);
    for(i = 0; i< vCE.size(); i++)
        magasin.setCartes(vCE[i]);
}


