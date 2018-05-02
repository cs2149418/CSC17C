/* 
 * File:   main.cpp
 * Author: curtisstephens
 *
 * Created on April 18, 2018, 10:11 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;
float perm(int n,int m);
float comb(int n,int m);
void roll();
/*
 * 
 */
int main(int argc, char** argv) 
{
    //simulation
    cout<<"\n\nSimulated Probabilities:\n";
    roll();
    return 0;
}

void roll()
{
    int i=0;
    int pair=0,two=0,three=0,four=0;
    while(i<10000)
    {
        int dice1=rand()%6+1;
        int dice2=rand()%6+1;
        int dice3=rand()%6+1;
        int dice4=rand()%6+1;
        
        //pair
        if(dice1==dice2)
            pair++;
        else if(dice1==dice3)
            pair++;
        else if(dice1==dice4)
            pair++;
        else if(dice2==dice3)
            pair++;
        else if(dice2==dice4)
            pair++;
        else if(dice3==dice4)
            pair++;
                
        //two pair
        if(dice1==dice2&&dice3==dice4)
            two++;
        else if(dice1==dice3&&dice2==dice4)
            two++;
        else if(dice1==dice4&&dice2==dice3)
            two++;
        
        //three of a kind
        if(dice1==dice2==dice3)
            three++;
        else if(dice2==dice3==dice4)
            three++;
        else if(dice1==dice3==dice4)
            three++;
        else if(dice1==dice2==dice4)
            three++;
        
        //four of a kind
        if(dice1==dice2==dice3==dice4)
            four++;
        
        i++;
    }
    
    //display
    cout<<"\nOne Pair: "<<((double)pair/10000)*100<<"%\n";
    cout<<"Two Pair: "<<((double)two/10000)*100<<"%\n";
    cout<<"Three of a Kind: "<<((double)three/10000)*100<<"%\n";
    cout<<"Four of a Kind: "<<((double)four/10000)*100<<"%\n";
}