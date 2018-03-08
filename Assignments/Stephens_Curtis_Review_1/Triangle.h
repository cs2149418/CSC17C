/* 
 * File:   Triangle.h
 * Author: Curtis Stephens
 * Created on February 26nd, 2018, 8:36 PM
 * Purpose:  Specification of a Triangular array from a Row Array
 */

#ifndef TRIANGLE_H
#define	TRIANGLE_H

#include "RowAray.h"
//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Triangle{
    private:
        int szRow;
        RowAray **records;
    public:
        Triangle(int);
        ~Triangle();
        int getSzRow();
        int getData(int,int);
};


#endif	/* TRIANGLE_H */