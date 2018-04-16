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

template <class T>
Table<T>::Table(unsigned int row, unsigned int col)
{
    this->szRow=row;
    this->szCol=col;
    this->columns=new T*[this->szCol];
    for(int i=0;i<this->szCol;i++)
        this->columns[i]=new T(this->szRow);
    for(int i=0;i<this->szCol;i++)
        for(int j=0;j<this->szRow;j++)
        {
            int temp=rand()%90+10;
            this->columns[i]->setData(j,temp);
        }
    
}

template <class T>
Table<T>::Table(const Table& orig) 
{
    this->szRow=orig.szRow;
    this->szCol=orig.szCol;
    this->columns=new T*[this->szCol];
    for(int i=0;i<this->szCol;i++)
        this->columns[i]=new T(this->szRow);
    for(int i=0;i<this->szCol;i++)
        for(int j=0;j<this->szRow;j++)
            this->setData(i,j,orig.getData(i,j));
}

template <class T>
Table<T>::~Table() {
    for(int i=0;i<this->szCol;i++)
        delete[]this->columns[i];
}

template <class T>
void Table<T>::setData(int i, int j, T num)
{
    this->columns[i]->setData(j,num);
}

template <class T>
T Table<T>::getData(int col, int row) const
{
    return this->columns[col]->getData(row);
}