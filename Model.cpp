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

       num_objects = 6;
       num_pokemon = 2;
       num_centers = 2;
       num_gyms = 2;

       object_ptrs[0] = p1;
       pokemon_ptrs[0] = p1;

       object_ptrs[1] = p2;
       pokemon_ptrs[1] = p2;
       
       object_ptrs[2] = c1;
       center_ptrs[0] = c1;

       object_ptrs[3] = c2;
       center_ptrs[1] = c2;

       object_ptrs[4] = g1;
       gym_ptrs[0] = g1;

       object_ptrs[5] = g2;
       gym_ptrs[1] = g2;

       cout << "Model default constructed" << endl;
   }

   Model::~Model()
   {
       for (int i = 0; i < 6; i++)
       {
           delete object_ptrs[i];
       }

       cout << "Model destructed." << endl;
   }

   Pokemon* Model::GetPokemonPtr(int id)
   {
       return pokemon_ptrs[id-1];
   }

   PokemonCenter* Model::GetPokemonCenterPtr(int id)
   {
       return center_ptrs[id-1];
   }

   PokemonGym* Model::GetPokemonGymPtr(int id)
   {
       return gym_ptrs[id-1];
   }

   bool Model::Update()
   {
       bool status_to_return = false;
       int gyms_beaten_counter = 0;
       int pokemon_exhausted_counter = 0;
       
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
        }



        if (gyms_beaten_counter == num_gyms)
        {
            cout << "GAME OVER: You win! All Pokemon Gyms Beaten!" << endl;
            exit(EXIT_SUCCESS);
        }
        else if (pokemon_exhausted_counter == num_pokemon)
        {
            cout << "GAME OVER: You lose! All of your Pokemon are tired!" << endl;
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