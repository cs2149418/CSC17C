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
template <class T>
RowAray<T>::RowAray(unsigned int s) 
{
    this->size=s;
    this->rowData=new T[this->size];
    for(int i=0;i<this->size;i++)
    {
        this->rowData[i]=0;
    }   
}

//destruct
template <class T>
RowAray<T>::~RowAray() 
{
    delete[]this->rowData;
}

//set data
template <class T>
void RowAray<T>::setData(int i, T num)
{
    this->rowData[i]=num;
}