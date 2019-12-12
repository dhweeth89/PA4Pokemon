#ifndef RIVAL_H
#define RIVAL_H


#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"
#include "BattleArena.h"

    
    enum RivalStates{
        ALIVE_RIVAL = 0,
        FAINTED_RIVAL = 1
    };

    
    class Rival : public GameObject
    {

        protected:

        double speed;
        string name;
        double health;
        double physical_damage;
        double magical_damage;
        double defense;
        double stamina_cost_per_fight;
        bool is_in_arena;
        BattleArena* current_arena;

        public:

        Rival(string, double, double, double, double, double, int, BattleArena*);
        void TakeHit(double, double, double);
        double Get_Phys_Dmg();
        double Get_Magic_Dmg();
        double Get_Defense();
        double Get_Health();
        bool Update();
        void ShowStatus();
        bool IsAlive();
        bool ShouldBeVisible();
        string getName();
    };
    
#endif