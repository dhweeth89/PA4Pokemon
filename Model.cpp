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
#include "Input_Handling.h"

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
       list<GameObject*>::iterator iterator;
       
       for (iterator = object_ptrs.begin(); iterator != object_ptrs.end(); iterator++)
       {
           delete (*iterator);
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
       //int gyms_beaten_counter = 0;
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

        list<GameObject*>::iterator iterator;

        for (iterator = active_ptrs.begin(); iterator != active_ptrs.end(); iterator++)
        {
            if ((*iterator)->Update() == true)
            {
                status_to_return = true;
            }

            if ((*iterator)->GetDisplayCode() == 'P' || (*iterator)->GetDisplayCode() == 'p')
            {
                if ((*iterator)->GetState() == EXHAUSTED)
                {
                    cout << (*iterator)->getName() << " has been removed" << endl;
                    iterator = active_ptrs.erase((iterator));
                    //pokemon_exhausted_counter += 1;    
                }
                if ((*iterator)->GetState() == FAINTED)
                {
                    cout << (*iterator)->getName() << " has been removed" << endl;
                    iterator = active_ptrs.erase((iterator));
                    //pokemon_fainted_counter += 1;    
                }

            }

            if ((*iterator)->GetDisplayCode() == 'G' || (*iterator)->GetDisplayCode() == 'g')
            {
                if ((*iterator)->GetState() == BEATEN)
                {
                    cout << "Pokemon Gym " << (*iterator)->GetId() << " has been removed" << endl;
                    iterator = active_ptrs.erase(iterator);
                }
            }

            if ((*iterator)->GetDisplayCode() == 'C' || (*iterator)->GetDisplayCode() == 'c')
            {
                if ((*iterator)->GetState() == NO_STAMINA_POINTS_AVAILABLE)
                {
                    cout << "Pokemon Center " << (*iterator)->GetId() << " has been removed" << endl;
                    iterator = active_ptrs.erase(iterator);
                }
            }

            if ((*iterator)->GetDisplayCode() == 'R' || (*iterator)->GetDisplayCode() == 'r')
            {
                if ((*iterator)->GetState() == FAINTED_RIVAL)
                {
                    cout << (*iterator)->getName() << " has been removed" << endl;
                    iterator = active_ptrs.erase(iterator);
                }
            }

            if ((*iterator)->GetDisplayCode() == 'A')
            {
                if ((*iterator)->GetState() == NO_RIVALS_AVAILABLE)
                {
                    cout << "Battle Arena " << (*iterator)->GetId() << " has been removed" << endl;
                    iterator = active_ptrs.erase(iterator);
                    //arenas_beaten_counter += 1;
                }
            }
        }

        cout << active_ptrs.size() << endl;

    /*

        list<PokemonGym*>::iterator iterator;
        iterator = gym_ptrs.begin();

        for (int i = 0; i < gym_ptrs.size(); i++)
        {
            if ((*iterator)->Update() == true)
            {
                status_to_return = true;
            }
            ++iterator;
        }

        list<PokemonCenter*>::iterator iterator1;
        iterator1 = center_ptrs.begin();

        for (int i = 0; i < center_ptrs.size(); i++)
        {
            if ((*iterator1)->Update() == true)
            {
                status_to_return = true;
            }

            if ((*iterator1)->GetState() == NO_STAMINA_POINTS_AVAILABLE)
            {
                active_ptrs.remove((*iterator1));
            }

            ++iterator1;
        }

        list<Pokemon*>::iterator iterator2;
        iterator2 = pokemon_ptrs.begin();


        for (int i = 0; i < pokemon_ptrs.size(); i++)
        {
            if ((*iterator2)->Update() == true)
            {
                status_to_return = true;
            }

            if ((*iterator2)->GetState() == EXHAUSTED)
            {
                pokemon_exhausted_counter += 1;
                active_ptrs.remove(*iterator2);
            }
            else if ((*iterator2)->GetState() == FAINTED)
            {
                pokemon_fainted_counter += 1;
                active_ptrs.remove(*iterator2);
            }
            ++iterator2;
        }

        list <BattleArena*>::iterator iterator3;
        iterator3 = arena_ptrs.begin();

        for (int i = 0; i < arena_ptrs.size(); i++)
        {
            if ((*iterator3)->Update() == true)
            {
                status_to_return = true;
            }

            if ((*iterator3)->GetState() == NO_RIVALS_AVAILABLE)
            {
                arenas_beaten_counter += 1;
                active_ptrs.remove(*iterator3);
            }
            ++iterator3;
        }

        list <Rival*>::iterator iterator4;
        iterator4 = rival_ptrs.begin();

        for (int i = 0; i < rival_ptrs.size(); i++)
        {
            if ((*iterator4)->Update() == true)
            {
                status_to_return = true;
            }

            ++iterator4;
        }


    */

        list<GameObject*>::iterator iterator1;

        for (iterator1 = object_ptrs.begin(); iterator1 != object_ptrs.end(); iterator1++)
        {
            if ((*iterator1)->GetDisplayCode() == 'P' || (*iterator1)->GetDisplayCode() == 'p')
            {
                if ((*iterator1)->GetState() == EXHAUSTED)
                {
                    pokemon_exhausted_counter += 1;    
                }
                if ((*iterator1)->GetState() == FAINTED)
                {
                    pokemon_fainted_counter += 1;    
                }
            }

            if ((*iterator1)->GetDisplayCode() == 'A')
            {
                if ((*iterator1)->GetState() == NO_RIVALS_AVAILABLE)
                {
                    arenas_beaten_counter += 1;
                }
            }
        }

        
        if (arenas_beaten_counter == arena_ptrs.size())
        {
            cout << "GAME OVER: You win! All Battle Arenas Beaten!" << endl;
            exit(EXIT_SUCCESS);
        }
        else if ( (pokemon_exhausted_counter + pokemon_fainted_counter) == pokemon_ptrs.size())
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

       list<GameObject*>::iterator iterator;
       iterator = active_ptrs.begin();

       for (iterator = active_ptrs.begin(); iterator != active_ptrs.end(); iterator++)
       {
           view.Plot((*iterator));
       }

       view.Draw();
   }


   void Model::ShowStatus()
   {
       list<GameObject*>::iterator iterator;
       iterator = object_ptrs.begin();

       
       for (int i = 0; i < object_ptrs.size(); i++ )
       {
           (*iterator)->ShowStatus();
           ++iterator;
       }
   }


    int Model::GetNumObjects()
    {
        return object_ptrs.size();
    }

    int Model::GetNumCenters()
    {
        return center_ptrs.size();
    }

    int Model::GetNumGyms()
    {
        return gym_ptrs.size();
    }

    int Model::GetNumPokemon()
    {
        return pokemon_ptrs.size();
    }

    int Model::GetNumArenas()
    {
        return arena_ptrs.size();
    }

    int Model::GetNumRivals()
    {
        return rival_ptrs.size();
    }

    void Model::NewCommand(char type, int id, double x, double y)
    {
        cout << "These objects will be built with default values" << endl;
        
        if (type == 'g' || type == 'G')
        {
            if (gym_ptrs.size() >= id)
            {
                throw Invalid_Input("Gym with this ID num already exists, even if not active");
            }

            if (id > 9 || id <= 0)
            {
                throw Invalid_Input("Do not enter an ID greater than 9 or 0/below");
            }
            
            PokemonGym* g1 = new PokemonGym(10, 1, 1.5, 3.3, id, Point2D(x,y));
            object_ptrs.push_back(g1);
            active_ptrs.push_back(g1);
            gym_ptrs.push_back(g1);
        }
        else if (type == 'c' || type == 'C')
        {
            if (center_ptrs.size() >= id)
            {
                throw Invalid_Input("Center with this ID num already exists, even if not active");
            }

            if (id > 9 || id <= 0)
            {
                throw Invalid_Input("Do not enter an ID greater than 9 or 0/below");
            }
            
            PokemonCenter* c1 = new PokemonCenter(id, 2, 100, Point2D(x,y));
            object_ptrs.push_back(c1);
            active_ptrs.push_back(c1);
            center_ptrs.push_back(c1);
        }

        else if (type == 'p' || type == 'p')
        {
            if (pokemon_ptrs.size() >= id)
            {
                throw Invalid_Input("Pokemon with this ID num already exists, even if not active");
            }

            if (id > 9 || id <= 0)
            {
                throw Invalid_Input("Do not enter an ID greater than 9 or 0/below");
            }

            Pokemon* p1 = new Pokemon("Default Pokemon", id, 'P', 2, Point2D(x,y));
            object_ptrs.push_back(p1);
            active_ptrs.push_back(p1);
            pokemon_ptrs.push_back(p1);

        }

        else if (type == 'r' || type == 'R')
        {   
            cout << "This rival will merely be put into the Battle Arena, not to the specified location" << endl;
            
            if (id < rival_ptrs.size())
            {
               throw Invalid_Input("Rival with ID num already exists, even if not active");
            } 

            if (id > 9 || id <= 0)
            {
                throw Invalid_Input("Do not enter an ID greater than 9 or 0/below");
            }

            //Only one battle arena exists; this code only works for 1 battle arena
            Rival* r1 = new Rival("New Rival", 5, 29, 5, 4, 20, 1, (*arena_ptrs.begin()));
            (*arena_ptrs.begin())->AddRival();
            object_ptrs.push_back(r1);
            active_ptrs.push_back(r1);
            rival_ptrs.push_back(r1);    
        }


    }

/*
       Pokemon* p1 = new Pokemon("Pikachu", 1, 'P', 2, Point2D(5,1));
       Pokemon* p2 = new Pokemon("Bulbasaur", 2, 'P', 1, Point2D(10,1));

       //int in_Id, Point2D in_loc
       PokemonCenter* c1 = new PokemonCenter(1, 1, 100, Point2D(1,20));
       PokemonCenter* c2 = new PokemonCenter(2, 2, 200, Point2D(10,20));
       
       /*PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, 
unsigned int exp_points_per_unit, int in_id, Point2D in_loc) : Building('G', in_id, in_loc)*/

/*
       PokemonGym* g1 = new PokemonGym(10, 1, 2.0, 3, 1, Point2D());
       PokemonGym* g2 = new PokemonGym(20, 5, 7.5, 8, 2, Point2D(5,5) );

//BattleArena(unsigned int max_rivals, unsigned int stamina_cost, double dollar_cost, int in_Id, Point2D in_loc)
       BattleArena* b1 = new BattleArena(3, 5, 5, 1, Point2D(12,13));

//Rival::Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, Point2D in_loc) 
       Rival* r1 = new Rival("Snorlax", 5, 29, 5, 4, 20, 1, b1);
       Rival* r2 = new Rival("Shaiv", 2, 35, 8, 2, 5, 2, b1);
       Rival* r3 = new Rival("Snake", 2, 50, 6, 5, 5, 2, b1);
*/

