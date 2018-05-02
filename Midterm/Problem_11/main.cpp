/* 
 * File:   Midterm Problem 11
 * Author: Curtis Stephens
 *
 * Created on April 18, 2018, 10:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//constants
const float base=.000001;

//functions
float gee(float);
/*
 * 
 */
int main(int argc, char** argv) 
{
    float result;
    float entry;
    
    cout<<"Enter a number between -1 and 1: ";
    cin>>entry;
    while(entry<-1||entry>1)
    {
        cout<<"Not a valid entry. Please reenter: ";
        cin>>entry;
    }
    result=gee(entry);
    cout<<"The result is "<<result<<endl;

    return 0;
}

float gee(float x)
{
    if(std::abs(x)<base)
    {
        return x-((x*x*x)/6);
    }
    else
    {
        float temp=gee(x/2);
        return (2*temp)/(1+(temp*temp));
    }
}
