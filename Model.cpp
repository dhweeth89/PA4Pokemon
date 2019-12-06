#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include <iostream>
#include "string.h"
#include "math.h"
#include "View.h"
#include "stdlib.h"
#include "Rival.h"
#include "BattleArena.h"

#include <iostream>
#include <list>
#include <iterator>

using namespace std;

/*

    private:

    int time;
    GameObject* object_ptrs[10];
    int num_objects;
    Pokemon* pokemon_ptrs[10];
    int num_pokemon;
    PokemonCenter* center_ptrs[10];
    int num_centers;
    PokemonGym* gym_ptrs[10];
    int num_gyms;

    public:

    Model();
    ~Model();
    Pokemon* GetPokemonPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    //void Display(View& view);
    void ShowStatus();

    */

   Model::Model()
   {
       this->time = 0;
       
       //Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
       
       Pokemon* p1 = new Pokemon("Pikachu", 1, 'P', 2, Point2D(5,1));
       Pokemon* p2 = new Pokemon("Bulbasaur", 2, 'P', 1, Point2D(10,1));

       //int in_Id, Point2D in_loc
       PokemonCenter* c1 = new PokemonCenter(1, 1, 100, Point2D(1,20));
       PokemonCenter* c2 = new PokemonCenter(2, 2, 200, Point2D(10,20));
       
       /*PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, 
unsigned int exp_points_per_unit, int in_id, Point2D in_loc) : Building('G', in_id, in_loc)*/

       PokemonGym* g1 = new PokemonGym(10, 1, 2.0, 3, 1, Point2D());
       PokemonGym* g2 = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5,5) );

//BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc)
       BattleArena* b1 = new BattleArena(3, 5, 5, 1, Point2D(12,13));

//Rival::Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc) 
       Rival* r1 = new Rival("Snorlax", 5, 29, 5, 4, 20, 1, b1);
       Rival* r2 = new Rival("Shaiv", 2, 35, 8, 2, 5, 2, b1);
       Rival* r3 = new Rival("Snake", 2, 50, 6, 5, 5, 2, b1);
       

       object_ptrs.push_back(p1);
       pokemon_ptrs.push_back(p1);

       object_ptrs.push_back(p2);
       pokemon_ptrs.push_back(p2);
       
       object_ptrs.push_back(c1);
       center_ptrs.push_back(c1);

       object_ptrs.push_back(c2);
       center_ptrs.push_back(c2);

       object_ptrs.push_back(g1);
       gym_ptrs.push_back(g1);

       object_ptrs.push_back(g2);
       gym_ptrs.push_back(g2);
    
       object_ptrs.push_back(b1);
       arena_ptrs.push_back(b1);

       object_ptrs.push_back(r1);
       rival_ptrs.push_back(r1);

       object_ptrs.push_back(r2);
       rival_ptrs.push_back(r2);

       object_ptrs.push_back(r3);
       rival_ptrs.push_back(r3);

       active_ptrs = object_ptrs;

       /*
       object_ptrs[2] = c1;
       center_ptrs[0] = c1;

       object_ptrs[3] = c2;
       center_ptrs[1] = c2;

       object_ptrs[4] = g1;
       gym_ptrs[0] = g1;

       object_ptrs[5] = g2;
       gym_ptrs[1] = g2;

       object_ptrs[6] = r1;
       rival_ptrs[0] = r1;

       object_ptrs[7] = r2;
       rival_ptrs[1] = r2;

       object_ptrs[8] = r3;
       rival_ptrs[2] = r3;

       object_ptrs[9] = b1;
       arena_ptrs[0] = b1;
       */

       cout << "Model default constructed" << endl;
   }

   Model::~Model()
   {
       for (int i = 0; i < object_ptrs.size(); i++)
       {
           delete object_ptrs.front();
       }

       cout << "Model destructed." << endl;
   }

   Pokemon* Model::GetPokemonPtr(int id)
   {
       list<Pokemon*>::iterator iterator;
       iterator = pokemon_ptrs.begin();

       for (int i = 1; i < id; i++)
       {
           ++iterator;
       }

       return *iterator;
   }

   PokemonCenter* Model::GetPokemonCenterPtr(int id)
   {
       list<PokemonCenter*>::iterator iterator;
       iterator = center_ptrs.begin();

       for (int i = 1; i < id; i++)
       {
           ++iterator;
       }

       return *iterator;
   }

   PokemonGym* Model::GetPokemonGymPtr(int id)
   {
       list<PokemonGym*>::iterator iterator;
       iterator = gym_ptrs.begin();

       for (int i = 1; i < id; i++)
       {
           ++iterator;
       }

       return *iterator;
   }

   BattleArena* Model::GetArenaPtr(int id)
   {
       list<BattleArena*>::iterator iterator;
       iterator = arena_ptrs.begin();

       for (int i = 1; i < id; i++)
       {
           ++iterator;
       }

       return *iterator;
   }

   Rival* Model::GetRivalPtr(int id)
   {
       list<Rival*>::iterator iterator;
       iterator = rival_ptrs.begin();

       for (int i = 1; i < id; i++)
       {
           ++iterator;
       }

       return *iterator;
   }

   bool Model::Update()
   {
       bool status_to_return = false;
       int gyms_beaten_counter = 0;
       int pokemon_exhausted_counter = 0;
       int pokemon_fainted_counter = 0;
       int arenas_beaten_counter = 0;
       
       this->time += 1;       
/*
       for (int i = 0; i < num_objects; i++)
       {
           if (object_ptrs[i]->Update() == true)
           {
               status_to_return = true;
           }
       }
*/
        for (int i = 0; i < num_gyms; i++)
        {
            if (gym_ptrs[i]->Update() == true)
            {
                status_to_return = true;
            }

            if (gym_ptrs[i]->GetState() == BEATEN)
            {
                gyms_beaten_counter += 1;
            }
        }

        for (int i=0; i < num_centers; i++)
        {
            if (center_ptrs[i]->Update() == true)
            {
                status_to_return = true;
            }
        }

        for (int i = 0; i < num_pokemon; i++)
        {
            if (pokemon_ptrs[i]->Update() == true)
            {
                status_to_return = true;
            }

            if (pokemon_ptrs[i]->GetState() == EXHAUSTED)
            {
                pokemon_exhausted_counter += 1;
            }

            if (pokemon_ptrs[i]->GetState() == FAINTED)
            {
                pokemon_fainted_counter += 1;
            }
        }

        for (int i = 0; i < num_arenas; i++)
        {
            if (arena_ptrs[i]->Update() == true)
            {
                status_to_return = true;
            }

            if (arena_ptrs[i]->GetState() == NO_RIVALS_AVAILABLE)
            {
                arenas_beaten_counter += 1;
            }
        }

        for (int i = 0; i < num_rivals; i++)
        {
            if (rival_ptrs[i]->Update() == true)
            {
                status_to_return = true;
            }
        }



        if (arenas_beaten_counter == num_arenas)
        {
            cout << "GAME OVER: You win! All Battle Arenas Beaten!" << endl;
            exit(EXIT_SUCCESS);
        }
        else if ( (pokemon_exhausted_counter + pokemon_fainted_counter) == num_pokemon)
        {
            cout << "GAME OVER: You lose! All of your Pokemon are either tired or fainted!" << endl;
            exit(EXIT_FAILURE);
        }

        return status_to_return;
   }


   void Model::Display(View& view)
   {
       cout << endl;
       cout << "time: " << this->time << endl;
       cout << endl;
       this->ShowStatus();
       view.Clear();
       for (int i=0; i<num_objects; i++)
       {
           view.Plot(object_ptrs[i]);
       }
       view.Draw();
   }


   void Model::ShowStatus()
   {
       for (int i = 0; i < num_objects; i++ )
       {
           object_ptrs[i]->ShowStatus();
       }
   }


    int Model::GetNumObjects()
    {
        return this->num_objects;
    }

    int Model::GetNumCenters()
    {
        return this->num_centers;
    }

    int Model::GetNumGyms()
    {
        return this->num_gyms;
    }

    int Model::GetNumPokemon()
    {
        return this->num_pokemon;
    }

    int Model::GetNumArenas()
    {
        return this->num_arenas;
    }

    int Model::GetNumRivals()
    {
        return this->num_rivals;
    }