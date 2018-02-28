/* 
 * File:   Table.h
 * Author: Curtis Stephens
 * Created on February 26nd, 2018, 8:36 PM
 * Specification for the Table
 */

#ifndef TABLE_H
#define	TABLE_H

#include "RowAray.h"
//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

class Table{
    private:
        int szRow;
        int szCol;
        RowAray **records;
    public:
        Table(int,int);
        ~Table();
        int getSzRow();
        int getSzCol();
        int getData(int,int);
};

#endif	/* TABLE_H */