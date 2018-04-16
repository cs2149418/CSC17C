/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 * Created in 2018
 * Purpose:  Midterm Project Roulette Game
 */

//System Libraries
#include <iostream>  //Input - Output Library
#include <ctime>     //Time for rand
#include <cstdlib>   //Srand to set the seed
#include <string>    ///string function
#include <cmath>     // math functions
#include <iomanip>   //set precision
#include <fstream>   //read file
#include <vector>   //vector
#include <map>      //map
#include <queue>  //queue
#include <algorithm> //for algorithms
#include <iterator>  //for iterators
#include "Player.h"  //player class
#include "NegChoice.h" //input verification temp class

using namespace std; //Name-space under which system libraries exist

//User Libraries

//NO CONSTANTS!!!!!

//Function Prototypes
int random(int, int);  //color random
int bonus();  //bonus function
void dcatch(int entry, int max); //catch with max
void tcatch(int entry, int min, int max);  //catch with min and max
void rcatch(int entry);  //catch with no max
int checkAcct(int valid[],int check, int size); //check for valid account

//Execution begins here
int main(int argc, char** argv) {
    //Declare variables
    string name;
    bool checkBank;
    int entry, choice, color, guessMax, guessed, winner2, money, bet; //random variables
    int min=0, max = 10; //min max for number game
    float wins = 0;   //set win counter
    float losses = 0;  //set lose counter
    float game = 1;//set play counter 
    int results=-1, acctNum;  //verify acct
    string win="Win", lose="Lose";
    
    //containers
    vector<int> storeWinner; //vector for winning numbers
    map<int,string> games;
    queue<int> hotNum;
   
    
    //accounts map set up
    int validAcct[20]={543, 785, 313, 432, 765, 345, 678, 409, 945,
                                284, 851, 274, 345, 456, 235, 143, 178, 993, 
                                169, 420}; //valid accts
    string names[20]={"Mark", "David", "Henry", "Kristina", "Ant$ ", 
                            "Herman", "Tyler", "Kohl", "Tracy", "Coby", "Nina", 
                            "Sean", "John", "Mia", "Thomas", "Nick", "Pat", 
                            "Eric", "Robert", "Curtis"};  //valid names
    std::map<int,string> accts; //map
    for(int i=0;i<20;i++)   //assign map
    {
        accts[validAcct[i]]=names[i];
    }

    //Intro and set up
    cout<<"Welcome to the Roulette Game!\n"; //greeting
    cout<<"Enter Your Account Number(prof use 543): ";
    
    //enter account
    cin>>acctNum;               //enter account number
    rcatch(acctNum);   //validate
    results=checkAcct(validAcct,acctNum,20); //search map
    if(results==-1) //if not valid
    {
        cout<<"Not a valid account number, opening new account.\n"
            <<"What is your name?";
        cin>>name;
        int newAcct=random(999,100);
        accts[newAcct]=name;
        acctNum=newAcct;
    }
    else  //if valid
    {
        cout<<"Welcome Back "<<accts[acctNum]<<"!!!\n";
    }
    //purchase chips
    cout<<"How many dollars in chips would you like to purchase? $";
    cin>>money;
    dcatch(money,10000);
    while(money<=0||money>10000) //validate
    {
        cin>>money;
        dcatch(money,10000);
    }
    
    //initialize player
    Player player(acctNum,money);
    //bonus for playing today
    int bonused=bonus();
    player.addBank(bonused); //add to bank
    cout<<"You received a $"<<bonused<<" bonus for playing today!\n";
    cout<<"Your bank is $"<<player.bankDisp()<<endl;
    
    //play
    while(entry!=3)
    {
        //menu
        cout<<"\n\nWhat would you like to do?\n"
                <<"1) Play by color\n"
                <<"2) Play by number\n"
                <<"3) Quit\n"
                <<"Choice: ";
        cin>>entry;
        tcatch(entry,1,3);
        //entry and validate input
        while(entry<1||entry>3)
        {
            cin>>entry;
            tcatch(entry,1,3);
        }
    
        //play by color
        if (entry==1) //choose the color game
        {
            while(color!=4)
            {
            cout<<"You chose to play by number!\n";
            
            //winning number list
            if(game!=1)
            {
                cout<<"\nWinning numbers so far: ";
                for(int i=1;i<game;i++)
                {
                    cout<<storeWinner[i]<<" ";
                }
                cout<<endl;
            }
            
            //choose
            cout<<"Choose a color! Black (1), Red (2), or Green(3) "
                    <<"To quit enter (4): ";
            cin>>color;  //choose color
            tcatch(color,1,4);
            while(color<1||color>4)
            {
                cout<<"You chose to play by number!\n";
                cout<<"Choose a color! Black (1), Red (2), or Green(3) "
                    <<"To quit enter (4): ";
                cin>>color;  //choose color
                tcatch(color,1,4);
            }
            
            //break to quit
            if(color==4)
            {
                break;
            }
            
            //generate number
            int winner=random(36,0);
            if(storeWinner.empty()) //check to see if empty
            {
                storeWinner.insert(storeWinner.end(),winner);
            }
            else //else push back
            {
                storeWinner.push_back(winner); //store winning vector
            }
            int winNum;
            //green
            if(winner==0||winner==36)
            {
                winNum=3;
            }
            //red
            else if(winner%2==0)
            {
                winNum=1;
            }
            //black
            else if(winner%2==1)
            {
                winNum=2;
            }
            
            //bet
            cout<<"How much do you want to bet on this spin? $";
            cin>>bet;
            //validate
            rcatch(bet);
            while(checkBank==false)
            {
                checkBank=player.checkBank(bet);
                if(checkBank==false)
                {
                    cout<<"Bet exceeds your chip count, "
                            <<"you have $"<<player.bankDisp()<<" available."
                            <<" Enter your bet: $";
                    cin>>bet;
                    rcatch(bet);
                }
            }
            
            //win
            if (color == winNum)      
            {
                cout << "You win!" << endl;
                if(color==3)
                {
                    bet*=18;
                    player.addBank(bet);
                    player.addGame(game,win);
                }
                else
                {
                    player.addBank(bet);
                    player.addGame(game,win);
                }
                game++;    //add play
                cout << "You have $" << player.bankDisp()
                         << " left. \n" << endl;      //funds left
            }
            
            //lose!!!
            else   
            {
                cout << "You lose." << endl;
                player.subBank(bet);
                player.addGame(game,lose);
                game++;  //add play
                cout << "You have $" << player.bankDisp()
                         << " left. \n" << endl;      //funds left
            }
                    cout << endl;

            }
        }
        
        //play by number
        else if (entry==2)  //choose number game
        {
        do   //start number game
        {
            //winning number list
            if(game!=1)
            {
                cout<<"\nWinning numbers so far: ";
                for(int i=1;i<game;i++)
                {
                    cout<<storeWinner[i]<<" ";
                }
                cout<<endl;
            }
            
            //setup
            cout << "How many plays do you want for this spin? (up to 10 per ";
            cout << "spin; enter -1 when done): ";
            cin >> guessMax;  //how many guesses for this spin
            tcatch(guessMax,-1,10);
            
            //validate input
            while(guessMax<-1||guessMax>10)
            {
                cin >> guessMax;  //how many guesses for this spin
                tcatch(guessMax,-1,10);
            }
            
            //generate winning number
            int winner2=random(36,0);
            if(storeWinner.empty()) //check to see if empty
            {
                storeWinner.insert(storeWinner.begin(),winner2);
            }
            else //else push back
            {
                storeWinner.push_back(winner2); //store winning vector
            }
            //guess and compare
            for (int guess = 1; guess <= guessMax; guess++)  //guess loop
            {
                cout<<"What number would you like to play for ";
                cout<<"play number " << guess << "? (0-36): ";
                cin>> guessed;  //guess number
                tcatch(guessed,0,37);
                //guess and validate
                while(guessed<0||guessed>37)
                {
                    cin >> guessed;  //guess number
                    tcatch(guessed,0,37);
                }
                
                //bet
                cout<<"How much would you like to bet for this play? $";
                cin>>bet;   //enter bet
                //validate
                rcatch(bet);
                while(checkBank==false)
                {
                    checkBank=player.checkBank(bet);
                    if(checkBank==false)
                    {
                        cout<<"Bet exceeds your chip count, "
                                <<"you have $"<<player.bankDisp()<<" available."
                                <<" Enter your bet: $";
                        cin>>bet;
                        rcatch(bet);
                    }
                }
                
                //win
                int winAmounted = bet*40;   //win amount
                if (guessed == winner2)  //winning number
                {
                    cout << "This number hit!" << endl; //win
                    player.addBank(winAmounted);
                    player.addGame(game,win);
                    game++;
                    cout << "You have $" << player.bankDisp()
                         << " left. \n" << endl;      //funds left
                }
                
                //lose
                else    // losing number
                {
                    cout << "This number missed." << endl;  //lose
                    player.subBank(bet); //subtract losings
                    player.addGame(game,lose);
                    game++; //add plays
                    cout << "You have $" << player.bankDisp()
                         << " left. \n" << endl;      //funds left
                }
            }            
            cout << "The Winning Number is "; 
            cout << winner2 << "\n\n";        //display winning number 
        } while (guessMax != -1);  //to end game
    }
    
    while(choice!=4)
    {
        //Data Manipulation Start
        cout<<"\n\nUser Information Menu\n";
        cout<<"1) Display member list\n"
                <<"2) Display games won/lost\n"
                <<"3) Frequency of winning numbers\n"
                <<"4) Quit\n"
                <<"Choice: ";
        cin>>choice;
        //validate
        tcatch(choice,1,4);
        while(choice<1||choice>4)
        {
            cin>>choice;
            tcatch(choice,1,4);
        }
        
        //display member list
        if(choice==1)
        {
            //declare iterator
            map<int,string>::iterator iter=accts.begin();
            //loop for display
            while(iter!=accts.end())
            {
                cout<<"ID: "<<iter->first
                        <<"\nName: "<<iter->second<<endl<<endl;
                iter++;
            }
        }
        
        //display games won/lost
        else if(choice==2)
        {
            player.dispGame();
            player.dispRatio(game);
        }
        
        //vector frequency
        else if(choice==3)
        {
            //sort
            std::sort(storeWinner.begin(),storeWinner.end());
            //declare iterator
            vector<int>::iterator vect;
            //loop for each number
            for(int i=0;i<36;i++)
            {
                //variables
                int freq=0;
                vect=storeWinner.begin();
                //loop for frequency
                while(vect!=storeWinner.end())
                {
                    //if they match add freq
                    if(i==*vect)
                    {
                        freq++;
                    }
                    vect++;
                    //output
                
                }
                cout<<"Number: "<<i<<" Frequency: "<<freq<<endl;
            }
        }
    }
        
    //ending bank
        cout<<"Thank you for playing "<<accts[acctNum]<<".\n"
                <<"Please cash out your remaining $"<<player.bankDisp()
                <<" in chips with the cashier.\n";
        
    //Exit stage right!
    }
    return 0;}  //end

//******************************
//Functions

//***************************
//randomize numbers color
//***************************
int random(int red, int black)
{
    unsigned seed = time(0);  //set seed
    srand(seed);   //initialize random
    int winner1=(rand() % (red - black + 1)) + black;  //randomize
    return winner1;    //return
}

//***************************
//randomize bonus
//***************************
int bonus()
{
    int min=0;
    int max=20;  //set max
    unsigned seed = time(0);  //set seed
    srand(seed);   //intialize random
    int bonused=(rand() % (max - min + 1)) + min;  //randomize
    return bonused;  //return random
}

//******************************
//check for valid account
//******************************
int checkAcct(int valid[],int check, int size)
{
    size=size-1;
    if(size<0)
        return -1;
    else if(valid[size]==check)
        return 1;
    else
        return checkAcct(valid,check,size);      
    }

//*********************************************
//Input No Max Error Catch
//**********************************************
void rcatch(int entry)
{
    string error="a";
        NegChoice e(entry);
        try
        {
            if(cin.fail())
                throw error;
            else if(entry<0)
                throw e;
        }
        catch(NegChoice e)
        {
            cout<<"Not a valid choice. Reenter\n\n";
        }
        catch(string a)
        {
            cin.clear();
            cout<<"You did not enter a number. Enter an integer.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
        }
}


//*********************************************
//Input Error Catch W/ Max
//**********************************************
void dcatch(int entry, int max)
{
    string error="a";
        NegChoice e(entry);
        try
        {
            if(cin.fail())
                throw error;
            else if(entry<=0)
                throw e;
            else if(entry>max)
                throw e;
        }
        catch(NegChoice e)
        {
            cout<<"Not a valid choice. Reenter\n\n";
        }
        catch(string a)
        {
            cin.clear();
            cout<<"You did not enter a number. Enter an integer.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
        }
}

//*********************************************
//Input With Bound Limits Error Catch
//**********************************************
void tcatch(int entry, int min, int max)
{
        string error="a";
        NegChoice e(entry);
        try
        {
            if(cin.fail())
                throw error;
            else if(entry<min)
                throw e;
            else if(entry>max)
                throw e;
        }
        catch(NegChoice e)
        {
            cout<<"Not a valid choice. Retry\n\n";
        }
        catch(string a)
        {
            cin.clear();
            cout<<"You did not enter a number. Enter an integer.\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear out the input buffer
        }
}