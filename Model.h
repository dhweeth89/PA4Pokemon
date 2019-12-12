#ifndef MODEL_H
#define MODEL_H

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Building.h"
#include "Pokemon.h"
#include "View.h"

#include <iostream>
#include <list>
#include <iterator>

#include "string.h"


class Model
{

    private:

    int time;
    
    list <GameObject*> object_ptrs;
    //int num_objects;
    list <GameObject*> active_ptrs;
    //int num_active;
    list <Pokemon*> pokemon_ptrs;
    //int num_pokemon;
    list <PokemonCenter*> center_ptrs;
    //int num_centers;
    list <PokemonGym*> gym_ptrs;
    //int num_gyms;
    list <BattleArena*> arena_ptrs;
    //int num_arenas;
    list <Rival*> rival_ptrs;
    //int num_rivals;

    public:

    Model();
    ~Model();
    
    Pokemon* GetPokemonPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    BattleArena* GetArenaPtr(int id);
    Rival* GetRivalPtr(int id);

    bool Update();
    void Display(View& view);
    void ShowStatus();

    int GetNumObjects();
    int GetNumCenters();
    int GetNumGyms();
    int GetNumPokemon();
    int GetNumArenas();
    int GetNumRivals();

    void NewCommand(char, int, double, double);




};





#endif

