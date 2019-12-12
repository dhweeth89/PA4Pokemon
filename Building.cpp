#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"

using namespace std;

//Builds default constructor, using GameObject constructor
Building::Building() : GameObject('B')
{
    pokemon_count = 0;
    cout << "Building default constructed" << endl;
}

//Creates a building, using GameObject constructor and then adding more values
Building::Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code)
{
    pokemon_count = 0;
    id_num = in_Id;
    location = in_loc;
    display_code = in_code; 
    cout << "Building constructed" << endl;
}

//Destructs a building
Building::~Building()
{
    cout << "Building destructed" << endl;
}

//Adds a pokemon to the building when called
void Building::AddOnePokemon()
{
    pokemon_count++;
}

//Removes a pokemon from the building when called
void Building::RemoveOnePokemon()
{
    if (pokemon_count > 0)
    {
        pokemon_count--;
    }
}

//Prints the status of a building
void Building::ShowStatus()
{
    cout << display_code << id_num << " located at " << location << endl;
    
    if (pokemon_count == 1)
    {
        cout << "\t" << pokemon_count << " pokemon is in this building" << endl;
    }
    else
    {
        cout << "\t" << pokemon_count << " pokemon are in this building" << endl;
    }
    
}

//Tells, when called, whether the building should be visible
bool Building::ShouldBeVisible()
{
    return true;
}

string Building::getName()
{
    return "";
}