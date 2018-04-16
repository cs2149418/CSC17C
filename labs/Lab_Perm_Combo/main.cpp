/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 * Purpose: Demonstrate Permutations With Or Without Replacement
 *
 * Created on March 27, 2018, 10:45 PM
 */
//Libraries
#include <cstdlib>
#include <iostream>
#include <cmath>


using namespace std;

//Functions
float PermRep(int);
float Perm(int, int);
float Combo(int,int);
float ComboRep(int,int);
/*
 * 
 */
int main(int argc, char** argv) 
{
    float perm1,perm2,combo1,combo2;
    cout<<"N   M  Permuation(N)  Permutation W/O   Combo W/O  Combo\n";
    for(int i=1;i<=5;i++)
        for(int j=1;j<=i;j++)
        {
            perm1=PermRep(i);
            perm2=Perm(i,j);
            combo1=Combo(i,j);
            combo2=ComboRep(i,j);
            cout<<i<<"  "<<j<<"     "<<perm1<<"                   "
                    <<perm2<<"           "<<combo1                   
                    <<"         "<<combo2<<endl;
        }


    return 0;
}

float PermRep(int in)
{
    int out=1;
    for(int i=1;i<=in;i++)
    {
        out*=i;
    }
    return out;
}
float Perm(int max,int choose)
{
    int chosen=max-choose;
    int top=1;
    int bottom=1;
    for(int i=1;i<=max;i++)
    {
        top*=i;
        if(i<=chosen)
        {
            bottom*=i;
        }
    }
    int final=top/bottom;
    return final;
}

float Combo(int n, int m)
{
    int count=1;
    for(int i=1;i<=n;i++)
    {
        for (int j=2;j<=m;j++) 
        {    
            if (i!=j)
                count++;
        }
    }
   return count;     
}

float ComboRep(int n, int m)
{
    int topC=n+m-1;
    int botC=m-1;
    int top=1,bot1=1,bot2=1;
    for(int i=1;i<=topC;i++)
    {
        top*=i;
        if(i<=n)
            bot1*=i;
        if(i<=botC)
            bot2*=i;
    }
    int final=top/(bot1*bot2);
    return final;
}