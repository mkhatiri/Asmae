#ifndef CARTESENERGIE_HPP
#define CARTESENERGIE_HPP


#include <iostream> 
#include "Cartes.hpp"

using namespace std;

class CartesEnergie :  public Cartes
{
    public:
        CartesEnergie(int id, string nom, string description, int prix, int domaine, int energie);
        virtual ~CartesEnergie();

        CartesEnergie();
        int getDomaine();
        void setDomaine(int energie);
        int getEnergie();
        void setEnergie(int energie);
        

        
        virtual int GetCardType() { return 1; }
        void display(); 

    protected:
    private:

        // Domaine de cette carte 
           int m_Domaine;
        // l'énergie de cette carte
           int m_Energie;



        
    
};

#endif // CARTESENERGIE_HPP
