/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on April 29, 2018, 9:29 AM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

float rec(int,int);

/*
 * 
 */
int main(int argc, char** argv) 
{
    int entryX, entryN;
    cout<<"X: ";
    cin>>entryX;
    cout<<"N: ";
    cin>>entryN;
    cout<<rec(entryX,entryN);

    return 0;
}

float rec(int x,int n)
{
    float times=n/2;
    float powered=pow(x,times);
    if(n==0)
        return 1;
    else if(n%2==0)
        return powered*powered;
    else
        return x*powered*powered;
}