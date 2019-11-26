#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "Building.h"
#include "View.h"

#include <iostream>
#include "string.h"

using namespace std;

/*

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
    void Plot(GameObject * ptr);

    void Draw();

*/

View::View()
{
    size = 11;
    scale = 2;
    origin = Point2D(0,0);
}

bool View::GetSubscripts(int& out_x, int& out_y, Point2D location)
{
    
    out_x = (int) ((location.x - origin.x) / scale);
    out_y = (int) ((location.y - origin.y) / scale);

    if (out_x <= view_maxsize || out_y <= view_maxsize)
    {
        return true;
    }
    else
    {
        cout << "An object is outside the display" << endl;
        return false;
    }
    
}

void View::Clear()
{
    for (int i = view_maxsize; i >= 0; i--)
    {
        for (int j = 0; j < view_maxsize; j++)
        {
            grid[j][i][0] = '.';
            grid[j][i][1] = ' '; 
        }
    }
}

void View::Plot(GameObject *ptr)
{
    int out_x;
    int out_y;

    if (GetSubscripts(out_x, out_y, ptr->GetLocation()) == true)
    {
        if (ptr->ShouldBeVisible() == true)
        {
            ptr->DrawSelf(grid[out_x][out_y]);
        }
    }
}

void View::Draw()
{
    bool y_index = true;

    for (int i=(size-1); i>=0; i--)
    {
        if (y_index == true)
        {
            cout << i * 2;
            y_index = false;
            if ((i * 2) < 10)
            {
                cout << " ";
            }

        }
        else
        {
            cout << "  ";
            y_index = true;
        }

        for (int j=0; j<size; j++)
        {
            cout<<grid[j][i][0];
            cout<<grid[j][i][1];
        }
    cout << endl;
    }

    cout << "  ";

    bool x_index_two_digits = false;
    bool x_index = true;

    for (int i=0; i<size; i++)
    {
        if (x_index == true)
        {
            if ( (i*2) >= 10)
            {
                x_index_two_digits = true;
            }

            if (x_index_two_digits == true)
            {
                cout << (i * 2);
                x_index = false;
            }
            else
            {
                cout << (i * 2) << " ";
                x_index = false;
            }
        }
        else 
        {
            cout << "  ";
            x_index = true;
        }
    }

    cout << endl;
    cout << endl;
}

