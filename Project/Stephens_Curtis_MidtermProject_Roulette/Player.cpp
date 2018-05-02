/* 
 * File:   Player.cpp
 * Author: Curtis Stephens
 * 
 * Created on April 8, 2018, 5:27 PM
 */

#include "Player.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>

using namespace std; //Name-space under which system libraries exist
//******************************
//Default
//******************************
Player::Player(int ID, int money) 
{
    id=ID;
    bank=money;
}

//******************************
//Copy Construct
//******************************
Player::Player(const Player& orig) 
{
    this->id=orig.id;
    this->bank=orig.bank;
}

//******************************
//Destructor
//******************************
Player::~Player() 
{
    games.clear();
}

//******************************
//check bank
//******************************
bool Player::checkBank(int amount)
{
    if(amount <= bank)
        return true;
    else
        return false;
}

//******************************
//add to bank
//******************************
void Player::addBank(int amount)
{
    bank+=amount;
}

//******************************
//subtract from bank
//******************************
void Player::subBank(int amount)
{
    bank-=amount;
    if(bank<=0)
    {
        std::cout<<"You are out of chips! How much would you like to buy? $";
        std::cin>>bank;
    }
}

//******************************
//display bank
//******************************
float Player::bankDisp()
{
    return bank;
}

//******************************
//display ID
//******************************
int Player::getId()
{
    return id;
}

//******************************
//add to container
//******************************
void Player::addGame(int game, string result)
{
    games[game]=result;
}

//******************************
//display the container
//******************************
void Player::dispGame()
{
    //declare iterator
    std::map<int,string>::iterator it =games.begin();
    //cycle and display
    while(it!=games.end())
    {
        cout<<"Game: "<<it->first<<" Result: "<<it->second<<endl;
        it++;
    } 
}

//******************************
//display the ratios
//******************************
void Player::dispRatio(int game)
{
    //declare iterator
    std::map<int,string>::iterator it =games.begin();
    //ratio win
    int count=0;
    it=games.begin();
    while(it!=games.end())
    {
        if(it->second=="Win")
        {
            count++;
        }
        it++;
    }
    //display
    float winRatio=(count/game)*100;
    cout<<"\nYour win ratio is "<<winRatio<<"%\n";
            
    //ratio lose
    count=0;
    it=games.begin();  //reset iterator
    //loop and count
    while(it!=games.end())
    {
        if(it->second=="Lose")
        {
            count++;
        }
        it++;
    }
    //display
    float loseRatio=(count/game)*100;
    cout<<"Your loss ratio is "<<winRatio<<"%\n\n";
}