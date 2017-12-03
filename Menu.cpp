#include <string>
#include "Menu.hpp"
#include "Player.hpp"
#include "Utils.hpp"

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
            Player p1;
            p1.init();
            session.addPlayer(p1);
            session.player = p1;
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
            }

    retour2:

            session.player = p1;
            session.player.display();
            session.player.displayCollection();
            cout << "  ********** Bienvenue " << session.player.getNom() << " *******  " << endl;                         

            cout << " A :  Joueer un matche " << endl;                                      

            cout << " B :  Acheter une carte " << endl;                                    

            cout << " C :  Liste des joueur " << endl;                                    

            cout << " D :  Personaliser le Deck " << endl;                                    

            cout << " F :  Afficher la liste des cartes " << endl;                                    

            cout << " Q :  Quiter " << endl;  

            cout << "  **************************************************************" << endl;                         
            cout << "Tapper le caractaire lier pour choisir le menue " << endl;         

            cin >> choix ;

            if(choix.compare("A") && choix.compare("B") && choix.compare("Q") && choix.compare("C")  && choix.compare("D")  && choix.compare("F") )        
            {                                                                          
                cout << " !!!!!!!!!!!!!!!!! choix incorrect  !!!!!!!!!! " << endl;     
                goto retour2;                                                           
            }

            if(!choix.compare("C"))
            {
                session.display();
                goto retour2;
            }

            if(!choix.compare("C")) 
            {
                session.player.displayCollection();
                goto retour2;
            }


            if(!choix.compare("A"))
            {
                cout << " Fonction a faire prochainement  " <<endl; 
                goto retour2; 
            }


            if(!choix.compare("D"))
            {
                cout << " a faire " <<endl;
               // session.initDeck();
                goto retour2;    
            }


            if(!choix.compare("B"))
            {

            cout << "  ********** Bienvenue " << session.player.getNom() << " *******  " << endl;                         
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
                    CartesEnergie CE = session.acheterUneCarteE();
                    if(CE.getPrix() <= session.player.getPoint())
                    {
                        session.player.collection.cartes_Energies.push_back(CE);
                        session.player.setPoint(session.player.getPoint() - CE.getPrix());
                        cout << " achat valide ";
                        session.player.displayCollection();
                        goto retour2;
                    }else
                    {
                        cout << " achat invalide : ********** solde insuffisant " << endl;
                        goto retour2;
                    }
                }

                if(!choix.compare("B"))
                {
                    CartesCreature CC = session.acheterUneCarteC();
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
                    CartesSpecial CS = session.acheterUneCarteS();
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

