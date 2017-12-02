#ifndef CARTESENERGIE_HPP
#define CARTESCREATURE_HPP


#include <iostream> 
#include "Cartes.hpp"

using namespace std;

class CartesCreature :  public Cartes
{
    public:
        CartesCreature(int id, string nom, string description, int lp, int hp);
        virtual ~CartesCreature();

        int getLp();
        void setLp(int lp);
        int getHp();
        void setHp(int hp);
        

        
        virtual int GetCardType() { return 2; }
        void display(); 

    protected:
    private:

        /* Life Points */
           int m_Lp;
        /* Hit Points*/
           int m_Hp;



        
    
};

#endif // CARTESCREATURE_HPP
