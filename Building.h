#ifndef BUILDING_H
#define BUILDING_H

#include <iostream>
#include "Point2D.h"
#include "GameObject.h"

class Building : public GameObject
{
    private:
        unsigned int pokemon_count;
    
    public:
        Building();
        Building(char, int, Point2D);
        ~Building();

        void AddOnePokemon();

        void RemoveOnePokemon();

        void ShowStatus();

        bool ShouldBeVisible();
};

#endif