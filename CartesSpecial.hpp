#ifndef CARTESSPECIAL_HPP
#define CARTESSPECIAL_HPP


#include <iostream> 
#include "Cartes.hpp"

using namespace std;

class CartesSpecial :  public Cartes
{
    public:
        CartesSpecial(int id, string nom, string description, int prix, bool recyclable, int effet);
        virtual ~CartesSpecial();

        CartesSpecial();
        bool getRecyclable();
        void setRecyclable(bool recyclable);

        bool isRecyclable();
        int getEffet();        

        
        virtual int GetCardType() { return 3; }
        void display(); 

    protected:
    private:

        // cycle de vie de la carte : Si recyclable == false ==> la carte est unique usage 
        bool m_Recyclable;
        int m_effet;


        
    
};

#endif // CARTESSPECIAL_HPP
