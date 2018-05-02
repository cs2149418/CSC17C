/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on April 29, 2018, 8:19 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

//functions
void probability();

/*
 * 
 */
int main(int argc, char** argv) 
{
    probability();

    return 0;
}

void probability()
{
    int i=0,hit=0;
    float prob=0;
    while(i<1000000)
    {
        int rand1=rand()%100+1;
        int rand2=rand()%100+1;
        int rand3=rand()%100+1;
        int rand4=rand()%100+1;
        int rand5=rand()%100+1;
        if(rand1 <=30 && rand2 <=30 && rand3<=30 && rand4<=30 && rand5<=30)
        {
            hit++;
        }
        i++;
    }
    prob=(double)hit/1000000;

cout<<"Probability of falling in the bit vector is: "<<prob;


}