#include <iostream>
#include "Player.hpp"
#include "Save.hpp"
#include "Cartes.hpp"
#include "CartesEnergie.hpp"
#include "CartesCreature.hpp"
#include "CartesSpecial.hpp"
#include "Utils.hpp"
#include <fstream>


using namespace std;

int main()
{
    //test Player
    Player* p1 = new Player("Mohammed", 12);

    Save *session1 = new Save();

    //session1->addPlayer();

    //session1->display();
    p1->display();

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


    Utils utils;

  //  utils.Write_Player("player1.txt", p1);
    
    utils.Read_Players("player1.txt");
    


    return 0;
}
