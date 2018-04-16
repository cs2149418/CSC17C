/* 
 * File:   Player.h
 * Author: Curtis Stephens
 *
 * Created on April 8, 2018, 5:27 PM
 */
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#ifndef PLAYER_H
#define PLAYER_H

using namespace std; //Name-space under which system libraries exist

class Player {
private:
    int id;
    float bank;
    map<int,string> games;
public:
    //Constructors
    Player(int, int);
    Player(const Player& orig);
    virtual ~Player();
    
    //Functions
    bool checkBank(int); //check balance
    void addBank(int); //add to bank
    void subBank(int); //subtract from bank
    float bankDisp();  //display bank

    //container functions
    void addGame(int,string);  //add game
    void dispGame();  //display container
    void dispRatio(int); //display ratios
};

#endif /* PLAYER_H */

