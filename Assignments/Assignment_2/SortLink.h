/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SortLink.h
 * Author: curtisstephens
 *
 * Created on March 25, 2018, 9:14 PM
 */
#include <cstdlib>
#include <iostream>

#ifndef SORTLINK_H
#define SORTLINK_H

class SortLink {
private:
    struct Link
    {
        int data;
        Link *next;
    };
    Link *head;

public:
    //constructors
    SortLink()
    {
        head=new Link;
        head->data=0;
        head->next=nullptr;
    }
    SortLink(int start)
    {
        head=new Link;
        head->data=start;
        head->next=nullptr;
    };
    ~SortLink()
    {
        Link *next;
        Link *ptr=head;
        while(ptr!=nullptr)
        {
            next=ptr->next;
            delete ptr;
            ptr=next;
        }
    }


    //functions
    void add(int); //add link to sorted list
    void display(); //display the list

};

void SortLink::add(int entry)
{
    Link *pntr;
    Link *prev=nullptr;
    Link *newNode=new Link;
    newNode->data=entry;
    
    //check to see if less than head
    if(entry<head->data)
    {
        pntr=head;
        head=newNode;
        newNode->next=pntr;
    }
    else
    {
        pntr=head;
        //traverse list
        while(pntr!=nullptr && pntr->data<entry)
        {
            prev=pntr;
            pntr=pntr->next;
        }
        //insert new node
        prev->next=newNode;
        newNode->next=pntr;
    }
}

void SortLink::display()
{
    Link *pntr=head;
    std::cout<<"Print The List:\n";
    while(pntr!=nullptr)
    {
        std::cout<<pntr->data<<std::endl;
        pntr=pntr->next;
    }
}

#endif /* SORTLINK_H */

