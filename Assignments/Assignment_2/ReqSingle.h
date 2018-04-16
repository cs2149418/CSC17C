/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ReqSingle.h
 * Author: curtisstephens
 *
 * Created on March 28, 2018, 10:17 AM
 */
#include <iostream>
#include <cstdlib>
#ifndef REQSINGLE_H
#define REQSINGLE_H

class ReqSingle {
private:
    struct Link
    {
        int data;
        Link *next;
    };
    Link *head;
    Link *sortHead;
public:
    ReqSingle()
    {
        head= new Link;
        head->data=0;
        sortHead=new Link;
        sortHead->data=0;
        head->next=sortHead;
        sortHead->next=nullptr;
        
    }
    ReqSingle(int start, int second)
    {
        head=new Link;
        sortHead=new Link;
        head->data=start;
        sortHead->data=second;
        head->next=sortHead;
        sortHead->next=nullptr;
    }
    ~ReqSingle()
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
    void addSort(int);
    void add(int);
    void display();
};

void ReqSingle::addSort(int entry)
{
    //declare
    Link *newNode= new Link;
    Link *ptr=sortHead;
    Link *prev=nullptr;
    newNode->data=entry;
    //loop to value
    
    while(ptr!=nullptr && ptr->data<entry)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    if(prev==nullptr)
    {
        sortHead=newNode;
        newNode->next=ptr;
    }
    else
    {
        //arrange
        prev->next=newNode;
        newNode->next=ptr;
    }
}

void ReqSingle::add(int entry)
{
    //declare
    Link *newNode= new Link;
    Link *ptr=head;
    newNode->data=entry;
    //loop to end of beg.
    while(ptr->next!=sortHead)
    {
        ptr=ptr->next;
    }
    //arrange
    ptr->next=newNode;
    newNode->next=sortHead;
}

void ReqSingle::display()
{
    Link *ptr=head;
    while(ptr!=nullptr)
    {
        std::cout<<ptr->data<<std::endl;
        ptr=ptr->next;
    }
}

#endif /* REQSINGLE_H */

