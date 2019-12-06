#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "Building.h"
#include "GameCommand.h"
#include "View.h"

#include <iostream>
#include "string.h"

using namespace std;

/*

    void DoMoveCommand(Model&, int, Point2D);
    void DoMoveToCenterCommand(Model&, int, int);
    void DoMoveToGymCommand(Model&, int, int);
    void DoStopCommand(Model&, int);
    void DoTrainInGymCommand(Model&, int, unsigned int);
    void DoRecoverInCenterCommand(Model&, int, unsigned int);
    void DoBattleInArenaCommand(Model&, int, int);
    //void DoGoCommand(Model&, View&);
    //void DoRunCommand(Model&, View&);

*/

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1)
{
    if (pokemon_id <= 0 || pokemon_id > model.GetNumPokemon())
    {
        cout << "Error: Please enter a valid command!" << endl; 
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);

        cout << "Moving " << ptrPokemon->getName() << " to " << p1 << endl;
        ptrPokemon->StartMoving(p1);
    }
    
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id)
{
    if ( (pokemon_id <= 0 || pokemon_id > model.GetNumPokemon()) || (center_id <= 0 || center_id > model.GetNumCenters() ) )
    {
        cout << "Error: Please enter a valid command!" << endl; 
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        PokemonCenter* ptrCenter = model.GetPokemonCenterPtr(center_id);

        cout << "Moving " << ptrPokemon->getName() << " to Center " << center_id << endl;
        ptrPokemon->StartMovingToCenter(ptrCenter);
    }

}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id)
{
    if ( (pokemon_id <= 0 || pokemon_id > model.GetNumPokemon()) || (gym_id <= 0 || gym_id > model.GetNumGyms() ) )
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        PokemonGym* ptrGym = model.GetPokemonGymPtr(gym_id);

        cout << "Moving " << ptrPokemon->getName() << " to Gym " << gym_id << endl;
        ptrPokemon->StartMovingToGym(ptrGym);
    }
    
}

void DoMoveToArenaCommand(Model& model, int pokemon_id, int arena_id)
{
    if ( (pokemon_id <= 0 || pokemon_id > model.GetNumPokemon()) || (arena_id <= 0 || arena_id > model.GetNumArenas() ) )
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        BattleArena* ptrArena = model.GetArenaPtr(arena_id);

        cout << "Moving " << ptrPokemon->getName() << " to Arena " << arena_id << endl;
        ptrPokemon->StartMovingToArena(ptrArena);
    }
}


void DoStopCommand(Model& model, int pokemon_id)
{
    if ( pokemon_id <= 0 || pokemon_id > model.GetNumPokemon() )
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        
        cout << "Stopping " << ptrPokemon->getName() << endl;
        ptrPokemon->Stop();
    }
    
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units)
{
    if ( pokemon_id <= 0 || pokemon_id > model.GetNumPokemon() )
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        
        cout << "Training " << ptrPokemon->getName() << endl;
        ptrPokemon->StartTraining(training_units);
    }
    
}


void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points)
{
    if ( pokemon_id <= 0 || pokemon_id > model.GetNumPokemon() )
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        
        cout << "Recovering " << ptrPokemon->getName() << "'s stamina" << endl;
        ptrPokemon->StartRecoveringStamina(stamina_points);
    }
}

void DoGoCommand(Model& model, View& view)
{
    cout << "Advancing one tick." << endl;
    model.Update();
    model.Display(view);
}


void DoRunCommand(Model& model, View& view)
{
    cout << "Advancing to next event." << endl;
    int i = 0;
    bool updateTruth = false;

    while (i<5 && !(updateTruth))
    {
        //model.Display(view);
        updateTruth = model.Update();
        model.Display(view);
        i++;
    }

    //If the thing updates, it stops running.  If i reaches 5, you stop.  Only one of these conditions has to be met to exit loop
}

void DoBattleInArenaCommand(Model& model, int pokemon_id, int rival_id)
{
    if (pokemon_id <= 0 || pokemon_id > model.GetNumPokemon())
    {
        cout << "Please enter a valid pokemon_id" << endl;
    }
    else
    {
        if (rival_id <= 0 || rival_id > model.GetNumRivals())
        {
            cout << "Please enter a valid rival_id" << endl;
        }
        else
        {
            Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
            Rival* ptrRival = model.GetRivalPtr(rival_id);
            cout << ptrPokemon->getName() << " battling " << ptrRival->GetName() << endl;
           
            ptrPokemon->ReadyBattle(ptrRival);
        }
        
    }
}




