/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   List.h
 * Author: curtisstephens
 *
 * Created on May 30, 2018, 9:39 PM
 */

#ifndef LIST_H
#define LIST_H

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;


class List {
private:
    const int size=100000;
    short *array;

public:
    List()
    {
        array=new short[size];
        for(int i=0;i<size;i++)
            array[i]=
    }
    virtual ~List();


};

#endif /* LIST_H */

