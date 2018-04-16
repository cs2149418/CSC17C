/*
 * I Certify That This Is My Own Working Code 
 */

/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 * Purpose: Roulette Game For CSC 17A Midterm Project
 *
 * Created on April 8, 2018, 5:14 PM
 */

//Libraries
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <ctime>
#include <fstream>
#include <vector>

#include "Player.h"

//Functions

//Constants

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    //Declare
    int entry;
    float chips;
    string error="a", invalid="b"; //for catch
    
    //Intro
    cout<<"Welcome to the Casino! Please Try Our New Video Roulette Game!\n\n";
    cout<<"Please Enter Your Player ID Number: ";  //enter id
    cin>>entry;
    do
    {
        cout<<"What Amount of Chips Would You Like to Buy? ";  //buy chips
        cin>>chips;
    }while(chips<=0 || chips >=10000);
    
    //Create Player
    Player player(entry, chips);
    
    //Start The Game
    cout<<"What Would You Like To Do?\n"
            <<"1) Play by Number\n"
            <<"2) Play by Color (C)\n"
            <<"3) Quit\n"
            <<"Choice: ";
    cin>>entry;
    try
    {
        if(cin.fail())
            throw error;
        else if(entry<=0||entry>3)
            throw invalid;
    }
    catch(string error)
    {
        cout<<"Not An Integer. Please Enter a Valid Selection: ";
        cin>>entry;
    }
    //loop the game
    while(entry!=3)
    {
        //play by number
        if(entry==1)
    }
    
    
    return 0;
}

