#include <string>
#include "Menu.hpp"
#include "Player.hpp"
#include "Utils.hpp"
#include <cstdlib>

using namespace std;

Menu::Menu()
{

    session.load_players();
    session.load_Cartes();
}

Menu::~Menu()
{
    //dtor
}

void Menu::description()
{
    cout << ".........Bienvenu sur le jeu de Asmae Bouabdalaoui .........   " << endl;
    cout << "Description du jeu :  " << endl;
    cout << " Chaque joueur a des cartes énergies et créatures devant lui \
       Le joueur 1 ne peut pas attaquer car sa carte créature nécessite 2 pts d'énergie (dont le domaine est Targaryens ici) " << endl;
    cout << " Par contre le joueur 2 peut attaquer car sa carte créature demande 1 pt de stark et 1 pt de targaryen. " << endl;
    cout << " Le joueur 1 a 25 points (LP) et le joueur 2 à 30 points (LP).  " << endl;
    cout << " Si un joueur veut attaquer un autre avec une carte créature il doit d'abord tuer toutes les créatures de son adversaire.  " << endl;
    cout << " seul le joueur 2 peut attaquer. Cependant il doit d'abord détruire la carte créature de son adversaire " << endl;
    cout << " Pour cela il va jouer sa carte créature et infliger à 30 points de dégâts. Ainsi, la créature du joueur 1 aura maintenant 70 LP. " << endl;


}


void Menu::menuPrincipal()
{

   string choix ;
   
retour : 
   cout << "  ********** Bienvenue *******  " << endl;

   cout << " A :  Se connecter " << endl;

   cout << " B :  Nouveau joueur " << endl;

   cout << " C :  Liste des joueurs " << endl;

   cout << " Q :  Quiter " << endl;

   cout << "  *****************************" << endl;                         
   cout << "Tapper le caractaire lier pour choisir le menue " << endl;
    
   cin >> choix ; 
   
    if(choix.compare("A") && choix.compare("B") && choix.compare("Q") && choix.compare("C") )
    {
        cout << " !!!!!!!!!!!!!!!!! choix incorrect  !!!!!!!!!! " << endl;
        goto retour;
    }else{
    
        if(!choix.compare("B"))
        {
            Player p;
            p.init();
            // generer la premier collection au hasard
            int randomvariable = rand() % session.magasin.cartes_Energies.size();
            CartesEnergie  randomCarte = session.magasin.cartes_Energies[randomvariable];
            p.collection.cartes_Energies.push_back(randomCarte);

            randomvariable = rand() % session.magasin.cartes_Creatures.size();
            CartesCreature  randomCarte2 = session.magasin.cartes_Creatures[randomvariable];
            p.collection.cartes_Creatures.push_back(randomCarte2);

            randomvariable = rand() % session.magasin.cartes_Speciales.size();
            CartesSpecial  randomCarte3 = session.magasin.cartes_Speciales[randomvariable];
            p.collection.cartes_Speciales.push_back(randomCarte3);

            session.addPlayer(p);
            goto retour; 
        }

        if(!choix.compare("A"))
        {
            string nom;
            cout << "inserer le nom du joueur " << endl;
            cin >> nom;
            Player p1 = session.getPlayer(nom);

            if(!p1.getNom().compare(""))
            {
                cout << " !!!!!!!!!!!!!!!!!!!!!!    invalide nom du joueur !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" <<endl; 
                // session.display();
                goto retour;
            }else{
                session.player = p1;
            }

retour2:

            cout << "  ********** Bienvenue " << session.player.getNom() << " *******  " << endl;                         

            cout << " A :  Joueer un matche " << endl;                                      

            cout << " B :  Acheter une carte " << endl;                                    

            cout << " C :  Liste des joueur " << endl;                                    

            cout << " D :  Personaliser le Deck " << endl;                                    

            cout << " F :  afficher le deck " << endl;                                    

            cout << " G :  Afficher la liste des cartes " << endl;                                    

            cout << " Q :  Quiter " << endl;  

            cout << "  **************************************************************" << endl;                         
            cout << " Tapper le caractaire lier pour choisir le menue " << endl;         

            cin >> choix ;

            if(choix.compare("A") && choix.compare("B") && choix.compare("Q") && choix.compare("C")  && choix.compare("D")  && choix.compare("F") && choix.compare("G"))        
            {                                                                          
                cout << " !!!!!!!!!!!!!!!!! choix incorrect  !!!!!!!!!! " << endl;     
                goto retour2;                                                           
            }

            if(!choix.compare("C"))
            {
                session.display();
                goto retour2;
            }

            if(!choix.compare("G")) 
            {
                session.player.displayCollection();
                goto retour2;
            }

            if(!choix.compare("F")) 
            {
                session.player.Deck.display();
                goto retour2;
            }



            if(!choix.compare("A"))
            {
                cout << " Fonction a faire prochainement  " <<endl; 
                goto retour2; 
            }


            if(!choix.compare("D"))
            {
                cout << " personaliser votre deck " << endl;

                cout << "  selctionner une Carte Energie " << endl ; 
                CartesEnergie CE = session.acheterUneCarteE(session.player.collection);
                session.player.Deck.cartes_Energies.push_back(CE);


                cout << "  selctionner une Carte Special " << endl ; 
                CartesSpecial CS = session.acheterUneCarteS(session.player.collection);
                session.player.Deck.cartes_Speciales.push_back(CS);




                cout << "  selctionner une Carte Creatre " << endl ; 
                CartesCreature CC = session.acheterUneCarteC(session.player.collection);
                session.player.Deck.cartes_Creatures.push_back(CC);


                cout << " deck bien initialiser " << endl;


                goto retour2;    
            }


            if(!choix.compare("B"))
            {

                cout << "  ********** Bienvenue " << session.player.getNom() << "( " << session.player.getPoint() << " point de vie )  *******  " << endl;                         
                cout << " A :  Acheter une carte Energie " << endl;                                      

                cout << " B :  Acheter une carte Creature " << endl;                                    

                cout << " C :  Acheter une carte Special " << endl;                                    

                cout << " R :  Annuler " << endl;  

                cout << " Q :  Quiter " << endl;  

                cout << "  **************************************************************" << endl;                         
                cout << "Tapper le caractaire lier pour choisir le menue " << endl;         

                cin >> choix ;

                if(choix.compare("A") && choix.compare("B") && choix.compare("Q") && choix.compare("C") && choix.compare("R") )        
                {                                                                          
                    cout << " !!!!!!!!!!!!!!!!! choix incorrect  !!!!!!!!!! " << endl;     
                    goto retour2;                                                           
                }

                if(!choix.compare("A"))
                {
                    CartesEnergie CE = session.acheterUneCarteE(session.magasin);
                    if(CE.getPrix() <= session.player.getPoint())
                    { 
                        session.player.collection.cartes_Energies.push_back(CE);
                        session.player.setPoint(session.player.getPoint() - CE.getPrix());
                        cout << " achat valide " << endl;;
                        goto retour2;
                    }else
                    {
                        cout << " achat invalide : ********** solde insuffisant " << endl;
                        goto retour2;
                    }
                }

                if(!choix.compare("B"))
                {
                    CartesCreature CC = session.acheterUneCarteC(session.magasin);
                    if(CC.getPrix() <= session.player.getPoint())
                    {
                        session.player.collection.cartes_Creatures.push_back(CC);
                        session.player.setPoint(session.player.getPoint() - CC.getPrix());
                        cout << " achat valide ";
                        goto retour2;
                    }else
                    {
                        cout << " achat invalide : ********** solde insuffisant " << endl;
                        goto retour2;
                    }
                }


                if(!choix.compare("C"))
                {
                    CartesSpecial CS = session.acheterUneCarteS(session.magasin);
                    if(CS.getPrix() <= session.player.getPoint())
                    {
                        session.player.collection.cartes_Speciales.push_back(CS);
                        session.player.setPoint(session.player.getPoint() - CS.getPrix());
                        cout << " achat valide ";
                        goto retour2;
                    }else
                    {
                        cout << " achat invalide : ********** solde insuffisant " << endl;
                        goto retour2;
                    }
                }


                if(!choix.compare("R"))
                {
                    goto retour2;
                }

                if(!choix.compare("Q"))
                {
                    session.saveSession();
                }
            }
        }

        if(!choix.compare("C"))
        {
            session.display();
            goto retour;
        }

        if(!choix.compare("Q"))
        {
            session.saveSession();
        }
    }




}

