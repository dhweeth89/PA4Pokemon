#ifndef POKEMON_H
#define POKEMON_H


#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Building.h"
#include <iostream>
#include "string.h"
#include "Rival.h"
#include "BattleArena.h"

using namespace std;

enum PokemonStates{
        STOPPED = 0,
        MOVING = 1,
        EXHAUSTED = 2,
        IN_GYM = 3,
        IN_CENTER = 4,
        MOVING_TO_GYM = 5,
        MOVING_TO_CENTER = 6,
        TRAINING_IN_GYM = 7,
        RECOVERING_STAMINA = 8,
        IN_ARENA = 9,
        MOVING_TO_ARENA = 10,
        BATTLE = 11,
        FAINTED = 12
    };



class Pokemon : public GameObject{

    private:

        double speed;
        bool is_in_gym;
        bool is_in_center;
        unsigned int stamina;
        unsigned int experience_points;
        double pokemon_dollars;
        unsigned int training_units_to_buy;
        unsigned int stamina_points_to_buy;
        string name;
        PokemonCenter* current_center;
        PokemonGym* current_gym;
        Point2D destination;
        Vector2D delta;

        //Added in PA4
        double health;
        double store_health;
        double physical_damage;
        double magical_damage;
        double defense;
        Rival* target;
        bool is_in_arena;
        BattleArena* current_arena;


    protected:

        bool UpdateLocation();
        void SetupDestination(Point2D);

    public:

        Pokemon();
        Pokemon(char);
        Pokemon(string, int, char, unsigned int, Point2D);
        ~Pokemon();

        void StartMoving(Point2D);
        void StartMovingToCenter(PokemonCenter*);
        void StartMovingToGym(PokemonGym*);
        void StartMovingToArena(BattleArena*);
        void StartTraining(unsigned int);
        void StartRecoveringStamina(unsigned int);
        void Stop();
        bool IsExhausted();
        bool ShouldBeVisible();
        void ShowStatus();
        bool Update();
        bool IsAlive();
        void TakeHit(double, double, double);
        void ReadyBattle(Rival*);
        bool StartBattle();

        
        string getName();

};


double GetRandomAmountOfPokemonDollars();

#endif