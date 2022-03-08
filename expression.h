/***********************************************************************
 * Header File:
 *    EXPRESSION
 * Author:
 *    Team 1
 * Summary:
 *    Defines all expressions parsable by ColorParser
 ************************************************************************/

#pragma once

#include <string>

/*************************************************************************
 * Background Color
 *************************************************************************/
class Expression
{
public:
    virtual void interpret(std::string &token) = 0;
};

class ValueExpression : public Expression
{
public:
    void interpret(std::string &token)
    {
        numValue = std::stod(token);
    }

    double numValue;
};

class EOFExpression : public Expression
{ };
