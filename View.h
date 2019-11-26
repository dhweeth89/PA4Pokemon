#ifndef VIEW_H
#define VIEW_H

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "Building.h"

#include <iostream>
#include "string.h"

using namespace std;

class View {

    static const int view_maxsize = 20;

    private:

    int size;
    double scale;
    Point2D origin;
    char grid[view_maxsize][view_maxsize][2];
    
    
    bool GetSubscripts(int&, int&, Point2D);

    public:

    View();
    void Clear();
    void Plot(GameObject*);

    void Draw();

};

#endif