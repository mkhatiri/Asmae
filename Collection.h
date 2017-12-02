#ifndef COLLECTION_H
#define COLLECTION_H


#include <iostream> 
using namespace std;

class Collection
{
    public:
        Collection();
        virtual ~Collection();
        string getType();
        Cartes *cartes_Energies[100]; 
        Cartes *cartes_Creatures[100]; 
        Cartes *cartes_Speciales[100]; 
    protected:
    private:
};

#endif // COLLECTION_H
