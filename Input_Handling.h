#include <iostream>
#include "string.h"
#include "stdlib.h"

using namespace std;

class Invalid_Input
{
    public :
        Invalid_Input(string in_ptr) : msg_ptr (in_ptr) { }
        
        const string msg_ptr;
    
    private :
        Invalid_Input ();
    //Makes it such that there is no default construction
};