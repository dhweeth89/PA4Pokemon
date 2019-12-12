#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "Vector2D.h"
#include "Point2D.h"

using namespace std;

class GameObject
{
    protected:
        //Class variables
        Point2D location;
        int id_num;
        char display_code; 
        char state;

    public:
        //Constructors
        GameObject(char);
        GameObject(Point2D, int, char);
        virtual ~GameObject();
        
        
        //Functions
        Point2D GetLocation();
        void DrawSelf(char *);
        int GetId();
        char GetState();
        char GetDisplayCode();
        //void ShowStatus();
        virtual bool Update() = 0;
        virtual void ShowStatus();
        virtual bool ShouldBeVisible() = 0;
        virtual string getName() = 0;

};

//Will add pure virtual functions later

#endif