/* 
 * File:   main.cpp
 * Author: curtisstephens
 *
 * Created on May 30, 2018, 9:55 PM
 */

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <stack>

using namespace std;

//functions
//sinh
float h(float angR)
{
    float tol=1e-6;
    if(angR>-tol&&angR<tol)
        return angR+angR*angR*angR/6;
    return 2*h(angR/2)*g(angR/2);
}
//cosh
float g(float angR)
{
    float tol=1e-6;
    if(angR>-tol&&angR<tol)
        return 1+angR*angR/2;
    float b=h(angR/2);
    return 1+2*b*b;
}


/*
 * 
 */
int main(int argc, char** argv) 
{
    
    
    return 0;
}

