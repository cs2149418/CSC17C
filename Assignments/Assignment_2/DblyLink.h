/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DblyLink.h
 * Author: curtisstephens
 *
 * Created on March 25, 2018, 10:02 PM
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#ifndef DBLYLINK_H
#define DBLYLINK_H

class DblyLink {
private:
    struct Link
    {
        int data;
        Link *prev;
        Link *next;
    };
    Link *head;

public:
    //constructors
    DblyLink()
    {
        head= new Link;
        head->next=nullptr;
        head->prev=nullptr;
        head->data=0;
    }
    DblyLink(int start)
    {
        head=new Link;
        head->next=nullptr;
        head->prev=nullptr;
        head->data=start;
    }

    //functions
    void add(int);
    void display();

};

void DblyLink::add(int entry)
{
    Link *pntr=head;
    Link *newNode=new Link;
    newNode->data=entry;
    newNode->next=nullptr;
    newNode->prev=nullptr;
    while(pntr->next!=nullptr)
    {
        pntr=pntr->next;
    }
    pntr->next=newNode;
    newNode->prev=pntr;
}

void DblyLink::display()
{
    Link *pntr=head;
    std::cout<<"Print The List:\n";
    while(pntr!=nullptr)
    {
        std::cout<<pntr->data<<std::endl;
        pntr=pntr->next;
    }
}

#endif /* DBLYLINK_H */

