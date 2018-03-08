/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Triangle.cpp
 * Author: Curtis Stephens
 * 
 * Created on February 26, 2018, 8:32 PM
 */

#include "Triangle.h"
#include "RowAray.h"
//User Libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

Triangle::Triangle(int size) 
{
    szRow=size;
    records=new RowAray*[size];
    for(int i=0;i<size;i++)
        records[i]=new RowAray(size);
}

Triangle::~Triangle() 
{
    delete[]records;
}

int Triangle::getSzRow()
{
    return szRow;
}

int Triangle::getData(int row, int col)
{
    int temp;
    temp=records[row]->getData(col);
    return temp;
}