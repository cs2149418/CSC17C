/* 
 * File:   NegChoice.h
 * Author: Curtis Stephens
 *
 * Created on April 10, 2018, 10:50 PM
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#ifndef NEGCHOICE_H
#define NEGCHOICE_H

class NegChoice {
private:
    int value;
public:
    NegChoice(int val)
    {   value= val;   }
    int getValue()
    {   return value;   }
};

#endif /* NEGCHOICE_H */

