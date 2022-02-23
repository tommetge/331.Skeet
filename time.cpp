/***********************************************************************
 * Implementation File:
 *    TIME
 * Author:
 *    Br. Helfrich
 * Summary:
 *    Time in level, what level it is, etc.
 ************************************************************************/

#include "time.h"
#include <sstream>
using namespace std;

/************************
 * TIME GET TEXT
 * Get the status text
 ************************/
string Time::getText() const
{
    ostringstream sout;

    sout << "Time:  " << secondsLeft();

    return sout.str();
}
