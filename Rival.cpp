#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "BattleArena.h"
#include "Rival.h"

/*
        double health;
        double physical_damage;
        double magical_damage;
        double defense;
        double stamina_cost_per_fight;
        bool is_in_arena;
        BattleArena* current_arena;

        public:

        Rival(string, double, double, double, double, double, int, Point2D);
        void TakeHit(double, double, double);
        double Get_Phys_Dmg();
        double Get_Magic_Dmg();
        double Get_Defense();
        double Get_Health();
        bool Update();
        void ShowStatus();


    };
*/

Rival::Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, BattleArena* arena) : GameObject(arena->GetLocation(), id, 'R')
{
    this->name = name;
    this->speed = speed;
    this->health = hp;
    this->physical_damage = phys_dmg;
    this->magical_damage = magic_dmg;
    this->defense = def;
    this->current_arena = arena;
    is_in_arena = true;
    cout << "RIval constructed" << endl;

}

void Rival::TakeHit(double physical_damage, double magical_damage, double defense)
{
    double damage;

    if (rand() < .5)
    {
        damage = ((100.0 - defense)/100) * physical_damage;
        cout << display_code << id_num << ": Physical attack was done to me" << endl;
    }
    else
    {
        damage = ((100.0 - defense)/100) * magical_damage;
        cout << display_code << id_num << ": Magic attack was done to me" << endl;
    }
    
    health -= damage;    

}

bool Rival::IsAlive()
{
    if (health <= 0)
    {
        state = FAINTED_RIVAL;
        current_arena->RemoveRival();
        return false;
    }
    else
    {
        state = ALIVE_RIVAL;
        return true;
    }
    
}

double Rival::Get_Phys_Dmg()
{
    return this->physical_damage;
}

double Rival::Get_Magic_Dmg()
{
    return this->magical_damage;
}

double Rival::Get_Defense()
{
    return this->defense;
}

double Rival::Get_Health()
{
    return this->health;
}

bool Rival::Update()
{
    if (this->health > 0 && state == ALIVE_RIVAL)
    {
        state = ALIVE_RIVAL;
        return false;
    }
    if (this->health <= 0 && state == ALIVE_RIVAL)
    {
        state = FAINTED_RIVAL;
        return true;
    }
}

void Rival::ShowStatus()
{
    cout << "Rival status: ";
    GameObject::ShowStatus();

    if (state == ALIVE_RIVAL)
    {
        cout << "\t" << name << " is alive." << endl;
    }
    else
    {
        cout << "\t" << name << " is fainted." << endl;
    }

    cout << "\tHealth: " << health << endl;
    cout << "\tPhysical damage: " << physical_damage << endl;
    cout << "\tMagical damage: " << magical_damage << endl;
    cout << "\tDefense: " << defense << endl;

    cout << endl;

}

bool Rival::ShouldBeVisible()
{
    if (this->state != FAINTED_RIVAL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Rival::getName()
{
    return this->name;
}

