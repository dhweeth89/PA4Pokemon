#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "View.h"
#include "Building.h"

#include <iostream>
#include "string.h"

using namespace std;

    void DoMoveCommand(Model&, int, Point2D);
    void DoMoveToCenterCommand(Model&, int, int);
    void DoMoveToGymCommand(Model&, int, int);
    void DoMoveToArenaCommand(Model&, int, int);
    
    void DoStopCommand(Model&, int);
    void DoTrainInGymCommand(Model&, int, unsigned int);
    void DoRecoverInCenterCommand(Model&, int, unsigned int);
    void DoBattleInArenaCommand(Model&, int, int);

    void DoGoCommand(Model&, View&);
    void DoRunCommand(Model&, View&);


#endif