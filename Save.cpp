#include <string>
#include <cstring>
#include "Save.hpp"
#include "Player.hpp"
#include "Utils.hpp"
#include <cstdlib>
#include <iostream>
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
    
    cout << "nouveau joueur :" << endl;
    p.display();  
    return nombrePlayers;
}

int Save::addPlayer(Player p)
{
    
    if(p.getNom().compare(""))
    {
        players[nombrePlayers] = p;
        nombrePlayers ++;
    }
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

//        cout << "------------- la liste des Cartes --------------- " << endl;

//        magasin.display(); 
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



void Save::saveSession()
{
    Utils utils; 

    vector <Player> vplayers;

    for(int i=0 ; i<nombrePlayers; i++)
    {
        if(players[i].getNom().compare(player.getNom()))  // pour eviter d'inserer le player qui joue la session deux fois.
        {
            players[i].SaveCollection();
            vplayers.push_back(players[i]);
        }
    }
    player.SaveCollection();  // sauvegarder aussi le joueur de la session
    vplayers.push_back(player);

    utils.Write_Player("Data/Players.txt", vplayers);

}



CartesCreature Save::acheterUneCarteC()
{

    int i=0;
    string s;
    CartesCreature cc;
    for( i=0; i<magasin.cartes_Creatures.size();i++)
    {
        cout << "Numero de la carte : "<<  i << " : " << endl; 
        magasin.cartes_Creatures[i].display(); 
    }

retour:
    cout << "inseret le numero de la carte que tu veux acheter" << endl; 
    cin >> s;

    int num = atoi(s.c_str());


    if(num >= magasin.cartes_Creatures.size())
    {
        cout << "numero invalide !!!!!!!!!!!!!!!!!!! " <<endl;
        goto retour;
    
    }else{
        cc = magasin.cartes_Creatures[num];    
    }

    return cc;
    
}



CartesSpecial Save::acheterUneCarteS()
{

    int i=0;
    string s;
    CartesSpecial cs;
    for( i=0; i<magasin.cartes_Speciales.size();i++)
    {
        cout << "Numero de la carte : "<<  i << " : " << endl; 
        magasin.cartes_Speciales[i].display(); 
    }

retour:
    cout << "inseret le numero de la carte que tu veux acheter" << endl; 
    cin >> s;

    int num = atoi(s.c_str());


    if(num >= magasin.cartes_Speciales.size())
    {
        cout << "numero invalide !!!!!!!!!!!!!!!!!!! " <<endl;
        goto retour;
    
    }else{
        cs = magasin.cartes_Speciales[num];    
    }

    return cs;
    
}




CartesEnergie Save::acheterUneCarteE()
{

    int i=0;
    string s;
    CartesEnergie ce;
    for( i=0; i<magasin.cartes_Energies.size();i++)
    {
        cout << "Numero de la carte : "<<  i << " : " << endl; 
        magasin.cartes_Energies[i].display(); 
    }

retour:
    cout << "inseret le numero de la carte que tu veux acheter" << endl; 
    cin >> s;

    int num = atoi(s.c_str());


    if(num >= magasin.cartes_Energies.size())
    {
        cout << "numero invalide !!!!!!!!!!!!!!!!!!! " <<endl;
        goto retour;
    
    }else{
        ce = magasin.cartes_Energies[num];    
    }

    return ce;
    
}



