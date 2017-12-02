#include "Player.hpp"
#include "Save.hpp"
#include "Cartes.hpp"
#include "CartesEnergie.hpp"
#include "CartesCreature.hpp"
#include "Utils.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

Utils::Utils()
{

}


Utils::~Utils()
{
    //dtor
}

void Utils::Read_Players(string filename)
{
    cout << "Read player" << endl;
    string line;
    ifstream file;
    file.open(filename.c_str());
    if (file.is_open()){
        while ( getline(file, line) ){
        //    file >> line ; // ":" << player.getCollectionFile();
            cout << line << endl;
        }
        file.close();
    }
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



