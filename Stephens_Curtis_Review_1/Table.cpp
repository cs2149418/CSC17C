/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.cpp
 * Author: Curtis Stephens
 * 
 * Created on February 26, 2018, 8:35 PM
 */
#include "RowAray.h"
#include "Table.h"
//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Table::Table(int rows, int cols) 
{
    szRow=rows;
    szCol=cols;
    records=new RowAray*[szRow];
}

Table::~Table() 
{
    delete[]records;
}

int Table::getSzCol()
{
    return szCol;
}

int Table::getSzRow()
{
    return szRow;
}

int Table::getData(int row, int col)
{
    return records[row]->getData(col);
}