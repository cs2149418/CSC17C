/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Player.cpp
 * Author: curtisstephens
 * 
 * Created on April 8, 2018, 5:27 PM
 */

#include "Player.h"

Player::Player(int ID, int money) 
{
    id=ID;
    bank=money;
}

Player::Player(const Player& orig) 
{
    this->id=orig.id;
    this->bank=orig.bank;
}

Player::~Player() 
{
    
}

//check bank
bool Player::checkBank(int amount)
{
    if(amount <= bank)
        return true;
    else
        return false;
}

