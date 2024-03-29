#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonGym.h"

using namespace std;

PokemonGym::PokemonGym() : Building('G', 1, Point2D())
{
    state = NOT_BEATEN;
    max_number_of_training_units = 10;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = 1;
    dollar_cost_per_training_unit = 1.0;
    experience_points_per_training_unit = 2;
    cout << "PokemonGym default constructed" << endl;
}

PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, 
unsigned int exp_points_per_unit, int in_id, Point2D in_loc) : Building('G', in_id, in_loc)
{
    state = NOT_BEATEN;
    max_number_of_training_units = max_training_units;
    num_training_units_remaining = max_number_of_training_units;
    stamina_cost_per_training_unit = stamina_cost;
    dollar_cost_per_training_unit = dollar_cost;
    experience_points_per_training_unit = exp_points_per_unit;
    cout << "PokemonGym constructed" << endl;
}

PokemonGym::~PokemonGym()
{
    cout << "PokemonGym destructed" << endl;
}

double PokemonGym::GetDollarCost(unsigned int unit_qty)
{
    return dollar_cost_per_training_unit * unit_qty;    
}

unsigned int PokemonGym::GetStaminaCost(unsigned int unit_qty)
{
    return stamina_cost_per_training_unit * unit_qty;
}

unsigned int PokemonGym::GetNumTrainingUnitsRemaining()
{
    return num_training_units_remaining;
}

bool PokemonGym::IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
{
    if ( (unit_qty * dollar_cost_per_training_unit <= budget) && (unit_qty * stamina_cost_per_training_unit <= stamina))
    {
        return true;
    }
    else
    {
        return false;
    }
}

unsigned int PokemonGym::TrainPokemon(unsigned int training_units)
{

    if (training_units > num_training_units_remaining)
    {
        cout << "Gym has fewer training units than requested: " << num_training_units_remaining << " instead of " << training_units << endl;
        training_units = num_training_units_remaining;
        num_training_units_remaining = 0;
        return training_units * experience_points_per_training_unit;
    }
    else
    {
       cout << "Gym has enough training units" << endl;
       num_training_units_remaining -= training_units;
       return training_units * experience_points_per_training_unit;
    }
}

bool PokemonGym::Update()
{
    if (num_training_units_remaining == 0 && state == NOT_BEATEN)
    {
        state = BEATEN;
        display_code = 'g';
        cout << display_code << id_num << " has been beaten" << endl;
        return true;
    }
    else
    {
        cout << display_code << id_num << " has not yet been beaten" << endl;
        return false;
    }
}

bool PokemonGym::IsBeaten()
{
    if (state == BEATEN)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void PokemonGym::ShowStatus()
{
    cout << "Pokemon Gym Status: ";
    Building::ShowStatus();
    cout << "\tMax number of training units: " << max_number_of_training_units << endl;
    cout << "\tStamina cost per training unit: " << stamina_cost_per_training_unit << endl;
    cout << "\tPokemon dollars per training unit: " << dollar_cost_per_training_unit << endl;
    cout << "\tExperience points per training unit: " << experience_points_per_training_unit << endl;
    
    if (num_training_units_remaining == 1)
    {
        cout << "\t" << num_training_units_remaining << " training unit is remaining for this gym" << endl;
    }
    else
    {
        cout << "\t" << num_training_units_remaining << " training units are remaining for this gym" << endl;
    }

    cout << endl;    
}

string PokemonGym::getName()
{
    return "";
}

