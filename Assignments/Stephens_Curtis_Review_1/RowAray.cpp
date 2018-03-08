/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.cpp
 * Author: Curtis Stephens
 * 
 * Created on February 26, 2018, 8:34 PM
 */

#include "RowAray.h"
//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

RowAray::RowAray(int cols) 
{
    srand(static_cast<unsigned int>(time(0)));
    size=cols;
    rowData=new int[cols];
    for(int i=0;i<cols;i++)
        rowData[i]=rand()%99+10;
}

RowAray::~RowAray() 
{
    delete[]rowData;
}

int RowAray::getSize()
{
    return size;
}

int RowAray::getData(int i)
{
    return rowData[i];
}

