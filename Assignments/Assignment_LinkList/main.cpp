/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on March 19, 2018, 6:32 PM
 */

#include <cstdlib>
#include "LinkedList.h"
#include "SimpleVector.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    LinkedList<int> list(2);
    list.addLst(5);
    list.addLst(10);
    list.insrtBefore(5,3);
    list.insrtAfter(5,4);
    list.insrtBeg(1);
    list.prntLst();
    list.deleteVal(6);
    list.deleteVal(2);
    list.prntLst();

    return 0;
}

