#include <iostream>
#include "Player.hpp"
#include "Save.hpp"
#include "Cartes.hpp"
#include "CartesEnergie.hpp"
#include "CartesCreature.hpp"
#include "CartesSpecial.hpp"
#include "Utils.hpp"
#include <fstream>

#include <string>
#include <cstring>
#include<cstdlib>
#include<vector>

using namespace std;




int main()
{
    //test Player
//    Player* p1 = new Player("Mohammed", 12);

    Save *session1 = new Save();

    session1->load_players();
    session1->load_Cartes();

//    p1->collection.cartes_Speciales = session1->magasin.cartes_Speciales; 
//    p1->collection.cartes_Energies = session1->magasin.cartes_Energies; 
//    p1->collection.cartes_Creatures = session1->magasin.cartes_Creatures; 

    
//    p1->SaveCollection();

//    session1->display();

    //session1->addPlayer();

    //session1->display();
//    session1->load_players();
   // p1->display();
   

//    cout << "chercher joueur";
//    cout << "Donner le nom du joueur : ";
//    string nom;
//    cin >> nom;

//    cout << nom.compare("aba") <<endl;

//    Player p2 = session1->getPlayer(nom);


 //   p2.display();

    //test Cartes Energie

    //    CartesEnergie* carte1 = new CartesEnergie(1, "jdida", "madir walou", 1, 2);
    //
    //
    //  carte1->setNom("jdida 2");

    // cout << carte1->getNom();


    //   carte1->setDescription(" golnalak makadir walou");

    //   cout << carte1->getDescription() << endl;

    //  carte1->display();


    //test Cartes Creature

    //    CartesCreature* carte2 = new CartesCreature(2, "jdida 2", "dir ri chiwa", 300, 273);

    //    cout << carte2->getLp() << endl;

    //    carte2->display();

    //test Cartes Special

    //    CartesSpecial* carte3 = new CartesSpecial(3, "jdida 3", "hadi special", false);

    //    cout << carte3->isRecyclable() << endl;

    //    carte3->display();


    //  Utils utils;

//    utils.Write_Player("player1.txt", p1);

    
//    utils.Read_Players("player1.txt");
    

//    utils.Read_Cartes("Cartes.txt");



    return 0;
}




