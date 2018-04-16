/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.h
 * Author: curtisstephens
 *
 * Created on April 8, 2018, 5:27 PM
 */

#ifndef PLAYER_H
#define PLAYER_H

class Player {
private:
    int id;
    float bank;
public:
    //Constructors
    Player(int, int);
    Player(const Player& orig);
    virtual ~Player();
    
    //Functions
    bool checkBank(int);

};

#endif /* PLAYER_H */

