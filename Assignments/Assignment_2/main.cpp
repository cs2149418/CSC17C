/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 * Purpose: Demonstrate the use of singly and doubly  sorted linked lists
 *
 * Created on March 25, 2018, 9:10 PM
 */

#include <cstdlib>
#include <iostream>
#include "SortLink.h"
#include "DblyLink.h"
#include "SortDLink.h"
#include "ReqSingle.h"
#include "ReqDble.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    //Sort Singly Linked List
    cout<<"Singly Link Sorted List:\n";
    SortLink list(5);
    list.add(2);
    list.add(10);
    list.add(6);
    list.display();
    
    //Singly List Request Add
    cout<<"\n\nThe Singly Linked List You Can Add By Request Is:\n";
    ReqSingle req(5,2);
    req.add(3);
    req.add(7);
    req.addSort(7);
    req.addSort(4);
    req.display();
    
    //Doubly Linked List
    cout<<"\n\nDoubly Linked List:\n";
    DblyLink dble(4);
    dble.add(5);
    dble.add(3);
    dble.add(2);
    dble.display();
    
    //Doubly List Request Add
    cout<<"\n\nDoubly Linked List Added By Request: \n";
    ReqDble reqd(4,12);
    reqd.add(15);
    reqd.add(2);
    reqd.add(10);
    reqd.add(11);
    reqd.display();
    
    //Sorted Doubly Linked List
    cout<<"\n\nThe Sorted Doubly Linked List:\n";
    DblyLink sortD(3);
    sortD.add(4);
    sortD.add(8);
    sortD.add(10);
    sortD.display();
     
    return 0;
}

