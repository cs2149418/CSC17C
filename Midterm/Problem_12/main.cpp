/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on April 29, 2018, 4:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <cmath>

using namespace std;

float cee(float);
float see(float);
/*
 * 
 */
int main(int argc, char** argv) 
{
    //declare
    float x=(3.14/4);
    cout<<"When entering x into C(x): "
        <<cee(x)<<endl;
    cout<<"When entering x into S(x): "
        <<see(x)<<endl;
    return 0;
}

float cee(float x)
{
    if(std::abs(x)<.000001)
        return ((1/x)+(x/6));
    else
    {
        float c=cee(x/2);
        float s=see(x/2);
        return (.5*c*s);
    }
}

float see(float x)
{
    if(std::abs(x)<.000001)
        return 1+((x*x*x)/2);
    else
    {
        float c=cee(x/2);
        float s=see(x/2);
        c=c*c;
        s=s*s;
        return ((c*s)/(c-s)); 
    }
}

