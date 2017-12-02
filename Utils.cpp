#include "Player.hpp"
#include "Save.hpp"
#include "Cartes.hpp"
#include "CartesEnergie.hpp"
#include "CartesCreature.hpp"
#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include<vector>
#include <cstring>
#include<cstdlib>


using namespace std;

Utils::Utils()
{

}


Utils::~Utils()
{
    //dtor
}

vector<Player>  Utils::Read_Players(string filename)
{
    cout << "Read player" << endl;
    string line;
    vector <Player> players;
    ifstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        while ( getline(file, line) ){
        //    file >> line ; // ":" << player.getCollectionFile();
            cout << line << endl;
            Player* p = lineToPlayer(line);
            if(p){
                    players.push_back(*p);
            }

        }
        file.close();
    }
    return players;
}

void Utils::Write_Player(string filename, Player* player)
{

    ofstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        file << player->getNom() << ":" << player->getPoint() ; // ":" << player.getCollectionFile();
        file.close();
    }

}


vector<Cartes>  Utils::Read_Cartes(string filename, int type)
{
    cout << "Read Cartes" << endl;
    string line;
    vector <Cartes> cartes;
    ifstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        while ( getline(file, line) ){
        //    file >> line ; // ":" << player.getCollectionFile();
            cout << line << endl;
            Cartes* c = lineToCarte(line, type);
            if(c){
                    cartes.push_back(*c);
            }

        }
        file.close();
    }
    return cartes;
}





void Utils::Write_Carte(string filename, Cartes* carte)
{

    cout << "Write Cartes" << endl;
    ofstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        file << carte->getNom() << ":" << carte->getDescription() ; // add les 3 if Creature, speacial ....
        file.close();
    }
}


Player * Utils::lineToPlayer(string line)
{


    vector<string> vplayer =  split(line, ":");
    
    if(vplayer.size() == 2){
    
        Player *player = new Player(vplayer[0], atoi(vplayer[1].c_str()));        
        return player ;
    
    }else{
        cout << "--------- Problem : les information du joueur sont pas complet : " << line << endl;
    
        return NULL;
    }

}

Cartes* Utils::lineToCarte(string line, int type)
{

    vector<string> v =  split(line, ":");

    if(type == 1){
        if(v.size() == 5){

            Cartes* carte = new CartesEnergie(atoi(v[0].c_str()), v[1], v[2], atoi(v[3].c_str()),  atoi(v[4].c_str()));
            return carte ;

        }else{
            cout << "--------- Problem : les information du joueur sont pas complet : " << line << endl;

            return NULL;
        }

    }


    if(type == 2){
        if(v.size() == 5){

            Cartes* carte = new CartesCreature(atoi(v[0].c_str()), v[1], v[2], atoi(v[3].c_str()),  atoi(v[4].c_str()));
            return carte ;

        }else{
            cout << "--------- Problem : les information du joueur sont pas complet : " << line << endl;

            return NULL;
        }

    }

    if(type == 3){
        if(v.size() == 5){

            Cartes* carte = new CartesSpecial(atoi(v[0].c_str()), v[1], v[2], atoi(v[3].c_str()));
            return carte ;

        }else{
            cout << "--------- Problem : les information du joueur sont pas complet : " << line << endl;

            return NULL;
        }

    }

}

vector<string> Utils::split(string str, string sep){
    char* cstr=const_cast<char*>(str.c_str());
    char* current;
    vector<string> arr;
    current=strtok(cstr,sep.c_str());
    while(current != NULL){
        arr.push_back(current);
        current=strtok(NULL, sep.c_str());
    }
    return arr;
}


