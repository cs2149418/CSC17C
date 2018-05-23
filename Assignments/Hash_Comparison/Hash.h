/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Hash.h
 * Author: curtisstephens
 *
 * Created on May 20, 2018, 7:03 PM
 */

#ifndef HASH_H
#define HASH_H

// CPP program to implement hashing with chaining
#include<iostream>
#include <list>
using namespace std;
 
class Hash
{
    int BUCKET;    // No. of buckets
 
    // Pointer to an array containing buckets
    list<int> *table;
public:
    Hash(int V);  // Constructor
 
    // inserts a key into hash table
    void insertItem(string x);
 
    // hash function to map values to key
    unsigned int hashFunction(const std::string& str)
    {
       unsigned int b    = 378551;
       unsigned int a    = 63689;
       unsigned int hash = 0;

       for(std::size_t i = 0; i < str.length(); i++)
       {
          hash = hash * a + str[i];
          a    = a * b;
       }

       return hash;
    }
    
    int HashSearch(int key)
    {
        list <int> :: iterator i;
        int index = hashFunction(key);

        for (i = table[index].begin();i != table[index].end(); i++)
        {
            if (*i == key)
            return 0;
        }
        return -1;
    }
    
};
 
Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new list<int>[BUCKET];
}
 
void Hash::insertItem(string key)
{
    int index = hashFunction(key);
    table[index].push_back(key); 
}
 

 

 

#endif /* HASH_H */

