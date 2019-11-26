#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"

using namespace std;

PokemonCenter::PokemonCenter() : Building('C', 1, Point2D())
{
    stamina_capacity = 100;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = 5;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter default constructed" << endl;
}

PokemonCenter::PokemonCenter(int in_Id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc) : Building('C', in_Id, in_loc)
{
    stamina_capacity = stamina_cap;
    num_stamina_points_remaining = stamina_capacity;
    dollar_cost_per_stamina_point = stamina_cost;
    state = STAMINA_POINTS_AVAILABLE;
    cout << "PokemonCenter constructed" << endl;
}

PokemonCenter::~PokemonCenter()
{
    cout << "Pokemon Center destructed" << endl;
}


bool PokemonCenter::HasStaminaPoints()
{
    if (num_stamina_points_remaining > 0)
    {
        return true;
    }
    else
    {
        return false;
    }    
}

unsigned int PokemonCenter::GetNumStaminaPointsRemaining()
{
    return num_stamina_points_remaining;
}

bool PokemonCenter::CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
    if ( (stamina_points * dollar_cost_per_stamina_point) <= budget)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double PokemonCenter::GetDollarCost(unsigned int stamina_points)
{
    return stamina_points * dollar_cost_per_stamina_point;
}

unsigned int PokemonCenter::DistributeStamina(unsigned int points_needed)
{
    if (num_stamina_points_remaining >= points_needed)
    {
        num_stamina_points_remaining -= points_needed;
        return points_needed;
    }
    if (num_stamina_points_remaining < points_needed)
    {
        unsigned int points_to_give = num_stamina_points_remaining;
        num_stamina_points_remaining = 0;
        return points_to_give;
    }

}

bool PokemonCenter::Update()
{
    if (num_stamina_points_remaining == 0 && state == STAMINA_POINTS_AVAILABLE)
    {
        state = NO_STAMINA_POINTS_AVAILABLE;
        display_code = 'c';
        cout << "Pokemon Center " << id_num << " has ran out of stamina points" << endl;
    }
    else
    {
        cout << "Pokemon Center " << id_num << " has not run out of stamina points" << endl;
        return false;
    }
}

void PokemonCenter::ShowStatus()
{
    cout << "Pokemon Center Status: ";
    Building::ShowStatus();
    cout << "\tPokemon dollars per stamina point: " << dollar_cost_per_stamina_point << endl;
    
    if (num_stamina_points_remaining == 1)
    {
        cout << "\t" << num_stamina_points_remaining << " stamina point remaining" << endl;
    }
    else
    {
        cout << "\t" << num_stamina_points_remaining << " stamina points remaining" << endl;
    }

    cout << endl;   
}