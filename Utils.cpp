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


vector<Player>  Utils::Read_Players(string filename)
{
    cout << "Read player" << endl;
    string line;
    vector <Player> players;
    ifstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        while ( getline(file, line) ){
        //  file >> line ; // ":" << player.getCollectionFile();
        //    cout << line << endl;
            Player* p = lineToPlayer(line);
            if(p){
                    players.push_back(*p);
            }

        }
        file.close();
    }
    else{
            cout << filename << " n'esiste pas " << endl;
    
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


vector<CartesEnergie>  Utils::Read_Cartes(string filename, CartesEnergie CE)
{
    cout << "Read Cartes Energie ............" << endl;
    string line;
    vector <CartesEnergie> cartes;
    ifstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        while ( getline(file, line) ){
        //    file >> line ; // ":" << player.getCollectionFile();
    //        cout << line << endl;
            CartesEnergie* c = lineToCarte(line, CE);
            if(c){
                    cartes.push_back(*c);
            }

        }
        file.close();
    }
    else{
            cout << filename << " n'esiste pas " << endl;
    }
    return cartes;
}


vector<CartesSpecial>  Utils::Read_Cartes(string filename, CartesSpecial CS)
{
    cout << "Read Cartes Special ............" << endl;
    string line;
    vector <CartesSpecial> cartes;
    ifstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        while ( getline(file, line) ){
        //    file >> line ; // ":" << player.getCollectionFile();
//            cout << line << endl;
            CartesSpecial* c = lineToCarte(line, CS);
            if(c){
                    cartes.push_back(*c);
            }

        }
        file.close();
    }
    else{
            cout << filename << " n'esiste pas " << endl;
    }
    return cartes;
}

vector<CartesCreature>  Utils::Read_Cartes(string filename, CartesCreature CC)
{
    cout << "Read Cartes Creature ............" << endl;
    string line;
    vector <CartesCreature> cartes;
    ifstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        while ( getline(file, line) ){
        //    file >> line ; // ":" << player.getCollectionFile();
  //          cout << line << endl;
            CartesCreature* c = lineToCarte(line, CC);
            if(c){
                    cartes.push_back(*c);
            }

        }
        file.close();
    }
    else{
            cout << filename << " n'esiste pas " << endl;
    }
    return cartes;
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

CartesEnergie* Utils::lineToCarte(string line, CartesEnergie CE)
{

    vector<string> v =  split(line, ":");

        if(v.size() == 6){

            CartesEnergie* carte = new CartesEnergie(atoi(v[0].c_str()), v[1], v[2], atoi(v[3].c_str()),  atoi(v[4].c_str()),atoi(v[5].c_str()) );
            return carte ;

        }else{
            cout << "--------- Problem : les information du joueur sont pas complet : " << line << endl;

            return NULL;

    }

}

CartesSpecial* Utils::lineToCarte(string line, CartesSpecial CS)
{

    vector<string> v =  split(line, ":");

        if(v.size() == 6){

            CartesSpecial* carte = new CartesSpecial(atoi(v[0].c_str()), v[1], v[2], atoi(v[3].c_str()), atoi(v[4].c_str()), atoi(v[5].c_str()));
            return carte ;

        }else{
            cout << "--------- Problem : les information du joueur sont pas complet : " << line << endl;

            return NULL;
        }

}


CartesCreature* Utils::lineToCarte(string line, CartesCreature CC)
{

    vector<string> v =  split(line, ":");

        if(v.size() == 6){

            CartesCreature* carte = new CartesCreature(atoi(v[0].c_str()), v[1], v[2], atoi(v[3].c_str()), atoi(v[4].c_str()), atoi(v[5].c_str()));
            return carte ;

        }else{
            cout << "--------- Problem : les information du joueur sont pas complet : " << line << endl;

            return NULL;
        }

}





void Utils::Write_Carte(string filename, vector <CartesEnergie>  CE)
{

    cout << "Write Cartes" << endl;
    ofstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        for(int i=0; i<CE.size(); i++){
            file << CE[i].getId() << ":";
            file << CE[i].getNom() << ":" ;
            file << CE[i].getDescription() << ":";
            file << CE[i].getPrix() << ":";
            file << CE[i].getDomaine() << ":"; 
            file << CE[i].getEnergie() << endl;
        }
        file.close();
    }
}

void Utils::Write_Carte(string filename, vector <CartesSpecial> CS)
{

    cout << "Write Cartes" << endl;
    ofstream file;
    file.open(filename.c_str());
    if (file.is_open()){

        for(int i=0; i<CS.size(); i++){
            file << CS[i].getId() << ":";
            file << CS[i].getNom() << ":" ;
            file << CS[i].getDescription() << ":";
            file << CS[i].getPrix() << ":";
            file << CS[i].getRecyclable() << ":"; 
            file << CS[i].getEffet() << endl;
        }
        file.close();
    }
}

void Utils::Write_Carte(string filename, vector <CartesCreature> CC)
{

    cout << "Write Cartes" << endl;
    ofstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        for(int i=0; i<CC.size(); i++){
            file << CC[i].getId() << ":";
            file << CC[i].getNom() << ":" ;
            file << CC[i].getDescription() << ":";
            file << CC[i].getPrix() << ":";
            file << CC[i].getLp() << ":"; 
            file << CC[i].getHp() << endl;
        }
        file.close();
    }
}
