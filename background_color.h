/***********************************************************************
 * Header File:
 *    BACKGROUND COLOR
 * Author:
 *    Team 1
 * Summary:
 *    Convenience class wrapping the RGB definition of a background color
 ************************************************************************/

#pragma once

#include <string>
#include <sstream>

#define SEPARATOR ","

/*************************************************************************
 * Background Color
 *************************************************************************/
struct BackgroundColor
{
    double red;
    double green;
    double blue;

    std::string str()
    {
        std::ostringstream os;
        os << red << SEPARATOR << green << SEPARATOR << blue << std::endl;

        return os.str();
    }
};
