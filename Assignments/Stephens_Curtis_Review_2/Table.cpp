/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Table.cpp
 * Author: curtisstephens
 * 
 * Created on March 6, 2018, 8:35 PM
 */

#include "Table.h"
#include <ctime>
#include <iostream>

Table::Table(unsigned int row, unsigned int col)
{
    szRow=row;
    szCol=col;
    columns=new RowAray*[szCol];
    for(int i=0;i<szCol;i++)
        columns[i]=new RowAray(szRow);
    for(int i=0;i<szCol;i++)
        for(int j=0;j<szRow;j++)
        {
            int temp=rand()%90+10;
            columns[i]->setData(j,temp);
        }
    
}

Table::Table(const Table& orig) 
{
    this->szRow=orig.szRow;
    this->szCol=orig.szCol;
    this->columns=new RowAray*[szCol];
    for(int i=0;i<szCol;i++)
        columns[i]=new RowAray(szRow);
    for(int i=0;i<szCol;i++)
        for(int j=0;j<szRow;j++)
            this->setData(i,j,orig.getData(i,j));
}

Table::~Table() {
    for(int i=0;i<szCol;i++)
        delete[]columns[i];
}

void Table::setData(int i, int j, int num)
{
    columns[i]->setData(j,num);
}

int Table::getData(int col, int row) const
{
    return columns[col]->getData(row);
}