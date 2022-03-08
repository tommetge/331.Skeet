/***********************************************************************
 * Header File:
 *    COLOR PARSER
 * Author:
 *    Team 1
 * Summary:
 *    Parses comma-separated list of colors for defining the background
 ************************************************************************/

#pragma once

#include "background_color.h"
#include "expression.h"

#include <string>
#include <vector>

/*************************************************************************
 * ColorParser
 * Parses colors
 *************************************************************************/
class ColorParser
{
public:
    ColorParser(const std::string& input)
        : input(input)
    {}

    BackgroundColor parse();

private:
    void getNext();
    void advanceIndex();

    std::string input;
    std::vector<Expression *> expressions;
    int32_t index;
};
