#ifndef MENU_HPP
#define MENU_HPP

#include <iostream> 
#include "Player.hpp" 
#include "Save.hpp" 
#include<vector>

using namespace std;



class Menu
{
    public:
        Menu();
        virtual ~Menu();


        void menuPrincipal();
        void description();

        Save session;

    protected:
    private:
};

#endif // MENU_HPP
