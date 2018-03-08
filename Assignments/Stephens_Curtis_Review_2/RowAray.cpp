/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RowAray.cpp
 * Author: curtisstephens
 * 
 * Created on March 6, 2018, 8:37 PM
 */

#include "RowAray.h"


//construct with size
RowAray::RowAray(unsigned int s) 
{
    size=s;
    rowData=new int[size];
    for(int i=0;i<size;i++)
    {
        rowData[i]=0;
    }   
}

//destruct
RowAray::~RowAray() 
{
    delete[]rowData;
}

//set data
void RowAray::setData(int i, int num)
{
    rowData[i]=num;
}