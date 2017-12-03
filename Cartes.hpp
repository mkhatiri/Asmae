#ifndef CARTES_HPP
#define CARTES_HPP


#include <iostream> 
using namespace std;

class Cartes
{
    public:
        
        Cartes();
        Cartes(int id, string nom, string description, int prix);
        virtual ~Cartes();
        string getNom();
        void setNom(string nom);
        string getDescription();
        void setDescription(string description);
        int getId();
        void setId(int id);

        int getPrix();
        void setPrix(int id);
//        virtual int GetCardType() = 0;
        void display(); 

    protected:
        int m_id; //chaque Carte dans le jeu a un id unique.
        string m_nom;
        string m_description;
        int m_prix;
        
    private:
    
};

#endif // CARTES_HPP
