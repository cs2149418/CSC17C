/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SortDLink.h
 * Author: curtisstephens
 *
 * Created on March 26, 2018, 10:22 AM
 */
#include <iostream>
#include <cstdlib>
#ifndef SORTDLINK_H
#define SORTDLINK_H

class SortDLink {
private:
    struct Link
    {
        int data;
        Link *next;
        Link *prev;
    };
    Link *head;

public:
    SortDLink()
    {
        head=new Link;
        head=0;
        head->next=nullptr;
        head->prev=nullptr;
    }
    SortDLink(int start)
    {
        head=new Link;
        head->data=start;
        head->next=nullptr;
        head->prev=nullptr;
    }
    void add(int);
    void display();
};

void SortDLink::add(int entry)
{
    Link *pntr=head;
    Link *last=nullptr;
    Link *newNode=new Link;
    newNode->data=entry;
    
    //check to see if less than head
    if(entry<head->data)
    {
        head=newNode;
        head->next=pntr;
        pntr->prev=head;
    }
    else
    {
        //traverse list
        while(pntr!=nullptr && pntr->data<entry)
        {
            last=pntr;
            pntr=pntr->next;
        }
        if(last==nullptr)
        {
            head=newNode;
            newNode->next=pntr;
            newNode->prev=nullptr;
            pntr->prev=newNode;
        }
        else
        {
            //insert new node
            last->next=newNode;
            newNode->prev=last;
            newNode->next=pntr;
            pntr->prev=newNode;
        }
    }
}

void SortDLink::display()
{
    Link *ptr=head;
    while(ptr!=nullptr)
    {
        std::cout<<ptr->data<<std::endl;
        ptr=ptr->next;
    }
}

#endif /* SORTDLINK_H */

