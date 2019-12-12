#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "View.h"
#include "GameCommand.h"
#include "Rival.h"
#include "BattleArena.h"
#include "Input_Handling.h"

#include <iostream>
#include "string.h"
#include "math.h"
#include "stdlib.h"

using namespace std;

int main()
{
    cout << "EC327: Introduction to Software Engineering" << endl;
    cout << "Fall 2019" << endl;
    cout << "Programming Assignment 3" << endl;
    
    
    cout << "                                  ,'\\ " << endl;
    cout << "   _.----.        ____         ,'  _\\   ___    ___     ____ " << endl;
    cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. " << endl;
    cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  | " << endl;
    cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | " << endl;
    cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | " << endl;
    cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     | " << endl;
    cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    | " << endl;
    cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   | " << endl;
    cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | " << endl;
    cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   | " << endl;
    cout << "                                `'                            '-._| " << endl;

    
    
    
    char entryCode = 0;
    char type = 0;
    double x;
    double y;
    int id1;
    int id2;
    unsigned int stamina_amount;
    unsigned int unit_amount;

    srand(time(NULL));
    
    Model model = Model();
    View view = View();

    model.Display(view);


    while (entryCode != 'q')
    {
        cout << "Enter Command: ";
        
        cin >> entryCode;

        try{
        switch (entryCode)
        {
            case 'm':
            {    
                if (!(cin >> id1))
                {
                    throw Invalid_Input("Expected an integer for Pokemon ID");
                }
                
                if (!(cin >> x))
                {
                    throw Invalid_Input("Expected a double for x coordinate");
                }
                
                if (!(cin >> y))
                {
                    throw Invalid_Input("Expected a double for y coordinate");
                }

                DoMoveCommand(model, id1, Point2D(x,y));
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            case 'g':
            {
                if (!(cin >> id1))
                {
                   throw Invalid_Input("Expected an integer for Pokemon ID"); 
                }
                if (!(cin >> id2))
                {
                   throw Invalid_Input("Expected an integer for Gym ID"); 
                }
                DoMoveToGymCommand(model, id1, id2);
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            case 'c':
            {
                if (!(cin >> id1))
                {
                   throw Invalid_Input("Expected an integer for Pokemon ID"); 
                }
                if (!(cin >> id2))
                {
                   throw Invalid_Input("Expected an integer for Gym ID"); 
                }
                DoMoveToCenterCommand(model, id1, id2);
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            case 's':
            {
                if (!(cin >> id1))
                {
                   throw Invalid_Input("Expected an integer for Pokemon ID"); 
                }
                DoStopCommand(model, id1);
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            case 'r':
            {
               if (!(cin >> id1))
                {
                   throw Invalid_Input("Expected an integer for Pokemon ID"); 
                }
                if (!(cin >> stamina_amount))
                {
                   throw Invalid_Input("Expected an unsigned integer for stamina amount"); 
                }
                DoRecoverInCenterCommand(model, id1, stamina_amount);
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            case 't':
            {
                if (!(cin >> id1))
                {
                   throw Invalid_Input("Expected an integer for Pokemon ID"); 
                }
                if (!(cin >> unit_amount))
                {
                   throw Invalid_Input("Expected an unsigned integer for Training Unit Amount"); 
                }
                DoTrainInGymCommand(model, id1, unit_amount);
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            case 'v':
            {
                DoGoCommand(model, view);
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            case 'x':
            {
                DoRunCommand(model, view);
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            case 'q':
            {
                break;
            }

            case 'b':
            {
                if (!(cin >> id1))
                {
                   throw Invalid_Input("Expected an integer for Pokemon ID"); 
                }
                if (!(cin >> id2))
                {
                   throw Invalid_Input("Expected an integer for Rival ID"); 
                }
                DoBattleInArenaCommand(model, id1, id2);
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            case 'a':
            {
                if (!(cin >> id1))
                {
                   throw Invalid_Input("Expected an integer for Pokemon ID"); 
                }
                if (!(cin >> id2))
                {
                   throw Invalid_Input("Expected an integer for Battle Arena ID"); 
                }
                  
                DoMoveToArenaCommand(model, id1, id2);
                cin.clear();
                cin.ignore(500, '\n');  
                break;
            }

            case 'n':
            {
                if (!(cin >> type))
                {
                    throw Invalid_Input("Expected a char for display code");
                }
                if (!(cin >> id1))
                {
                    throw Invalid_Input("Expected an int for the ID #");
                }
                if (!(cin >> x))
                {
                    throw Invalid_Input("Expected a double for x coordinate");
                }
                
                if (!(cin >> y))
                {
                    throw Invalid_Input("Expected a double for y coordinate");
                }

                if (x > 20 || x < 0 || y < 0 || y > 20)
                {
                    throw Invalid_Input("Make sure object is within the plotting boundary range");
                }

                model.NewCommand(type, id1, x, y);
                cin.clear();
                cin.ignore(500, '\n');
                break;
            }

            default:
            {
                throw Invalid_Input("Please enter a valid command code");
                break;
            }
        }
        }


        catch (Invalid_Input& except)
        {
            cout << "Invalid input - " << except.msg_ptr << endl;
            cin.clear();
            cin.ignore(500, '\n');
            // actions to be taken if the input is wrong
        }

    }

    return 0;
}


/*
cout << "                                  ,'\\ " << endl;
cout << "   _.----.        ____         ,'  _\\   ___    ___     ____ " << endl;
cout << "_,-'       `.     |    |  /`.   \\,-'    |   \\  /   |   |    \\  |`. " << endl;
cout << "\\      __    \\    '-.  | /   `.  ___    |    \\/    |   '-.   \\ |  | " << endl;
cout << " \\.    \\ \\   |  __  |  |/    ,','_  `.  |          | __  |    \\|  | " << endl;
cout << "   \\    \\/   /,' _`.|      ,' / / / /   |          ,' _`.|     |  | " << endl;
cout << "    \\     ,-'/  /   \\    ,'   | \\/ / ,`.|         /  /   \\  |     | " << endl;
cout << "     \\    \\ |   \\_/  |   `-.  \\    `'  /|  |    ||   \\_/  | |\\    | " << endl;
cout << "      \\    \\ \\      /       `-.`.___,-' |  |\\  /| \\      /  | |   | " << endl;
cout << "       \\    \\ `.__,'|  |`-._    `|      |__| \\/ |  `.__,'|  | |   | " << endl;
cout << "        \\_.-'       |__|    `-._ |              '-.|     '-.| |   | " << endl;
cout << "                                `'                            '-._| " << endl;
*/