#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "BattleArena.h"

using namespace std;



/*
      private:

        unsigned int max_num_rivals;
        unsigned int num_rivals_remaining;
        double dollar_cost_per_fight;
        unsigned int stamina_cost_per_fight;
        unsigned int pokemon_count;

        public:

        BattleArena();
        BattleArena(unsigned int, unsigned int, double, int, Point2D);
        ~BattleArena();

        unsigned int GetNumRivalsRemaining();
        bool HasEnoughRivals();
        double GetDollarCost();
        unsigned int GetStaminaCost();
        bool IsAbleToFight(double, unsigned int);
        bool Update();
        bool IsBeaten();
        void ShowStatus();        
    };
*/

BattleArena::BattleArena() : Building('A', 1, Point2D())
{
    max_num_rivals = 3;
    pokemon_count = 0;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = 4;
    stamina_cost_per_fight = 3;
    state = RIVALS_AVAILABLE;
    cout << "BattleArena default constructed" << endl;
}

BattleArena::BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc):Building('A', in_Id, in_loc)
{
    pokemon_count = 0;
    max_num_rivals = max_rivals;
    num_rivals_remaining = max_num_rivals;
    dollar_cost_per_fight = dollar_cost;
    stamina_cost_per_fight = stamina_cost;
    state = RIVALS_AVAILABLE;
    cout << "BattleArena constructed" << endl;
}

BattleArena::~BattleArena()
{
    cout << "BattleArena destructed" << endl;
}


unsigned int BattleArena::GetNumRivalsRemaining()
{
    return num_rivals_remaining;
}

bool BattleArena::HasEnoughRivals()
{
    if (num_rivals_remaining >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double BattleArena::GetDollarCost()
{
    return dollar_cost_per_fight;
}

unsigned int BattleArena::GetStaminaCost()
{
    return stamina_cost_per_fight;
}

bool BattleArena::IsAbleToFight(double budget, unsigned int stamina)
{
    if ( (budget > dollar_cost_per_fight) && (stamina > stamina_cost_per_fight) )
    {
        return true;
    }
    else
    {
        return false;
    }    
}

bool BattleArena::Update()
{
    if (num_rivals_remaining == 0 && state == RIVALS_AVAILABLE)
    {
        state = NO_RIVALS_AVAILABLE;
        return true;
    }
    else
    {
        return false;
    }
    
}

bool BattleArena::IsBeaten()
{
    if (num_rivals_remaining == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BattleArena::ShowStatus()
{
    cout << "Battle Arena status: ";
    Building::ShowStatus();
    cout << "\tMax number of rivals: " << max_num_rivals << endl;
    cout << "\tStamina cost per fight: " << stamina_cost_per_fight << endl;;
    cout << "\tPokemon dollars per fight: " << dollar_cost_per_fight << endl;
    
    if (num_rivals_remaining == 1)
    {
        cout << "\t" << num_rivals_remaining << " rival is remaining for this arena" << endl;
    }
    else
    {
        cout << "\t" << num_rivals_remaining << " rivals are remaining for this arena" << endl;
    }
}

void BattleArena::RemoveRival()
{
    if (num_rivals_remaining > 0)
    {
        num_rivals_remaining--;
    }
}

void BattleArena::AddRival()
{
    num_rivals_remaining++;
}

string BattleArena::getName()
{
    return "";
}



