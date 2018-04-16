/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ReqDble.h
 * Author: curtisstephens
 *
 * Created on March 29, 2018, 9:49 PM
 */
#include <iostream>
#include <cstdlib>
#ifndef REQDBLE_H
#define REQDBLE_H

class ReqDble {
private:
    struct Link
    {
        int data;
        Link *prev;
        Link *next;
    };
    Link *head;
    Link *sortHead;
public:
    ReqDble(int start, int second)
    {
        head=new Link;
        sortHead=new Link;
        head->data=start;
        sortHead->data=second;
        head->next=sortHead;
        sortHead->prev=head;
    }
    virtual ~ReqDble()
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
    void add(int);
    void addSort(int);
    void display();

};

void ReqDble::add(int entry)
{
    Link *ptr=head;
    Link *newNode=new Link;
    newNode->data=entry;
    //loop
    while(ptr->next!=sortHead)
    {
        ptr=ptr->next;
    }
    //assign
    ptr->next=newNode;
    newNode->next=sortHead;
    newNode->prev=ptr;
    sortHead->prev=newNode;
}
void ReqDble::addSort(int entry)
{
    Link *ptr=sortHead;
    Link *last=nullptr;
    Link *newNode=new Link;
    newNode->data=entry;
    //check if less than head
    if(entry<sortHead->data)
    {
        sortHead=newNode;
        sortHead->next=ptr;
        ptr->prev=sortHead;
    }
    else
    {
        //loop to variable
        while(ptr!=nullptr && ptr->data<entry)
        {
            last=ptr;
            ptr=ptr->next;
        }
        last->next=newNode;
        newNode->next=ptr;
        newNode->prev=last;
        ptr->prev=newNode;
    }
}
void ReqDble::display()
{
    Link *ptr=head;
    while(ptr!=nullptr)
    {
        std::cout<<ptr->data<<std::endl;
        ptr=ptr->next;
    }
}

#endif /* REQDBLE_H */

