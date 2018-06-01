/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on May 31, 2018, 7:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <string>
#include <sstream>
#include <map>


using namespace std;

static const char alpha[]=
"ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int alphaL=sizeof(alpha)-1;
char genRanAlpha()
{
    return alpha[rand() % alphaL];
}

int Hash(string); 


int main() {

    srand( time( 0 ) );
    int size = 20;
    string in[size];
    int array[size];
    for(int i=0; i<size; i++) 
        array[i] = 0;

    for(int i=0; i<size; i++) 
    {
        for(int i=0;i<3;i++)
            in[i]+=genRanAlpha();
        int hash = Hash(in[i]);
        array[i]=hash;
    }
    
    for(int i=0;i<size;i++)
        cout<<array[i];

return 0;

}

int Hash(string str) 
{
    int hashed[3];
    for(int i=0; i<3;i++) 
    {
        int j = 0;
        char c = str[i];
        if(c >=65 && c <=67) 
            j = 2;
        else if(c>=68 && c<=70) 
            j = 3;
        else if(c>=71 && c<=73) 
            j = 4;
        else if(c>=74 && c<=76) 
            j = 5;
        else if(c>=77 && c<=79) 
            j = 6;
        else if(c>=80 && c<=83)
            j = 7;
        else if(c>=84 && c<=86) 
            j = 8;
        else if(c>=85 && c<=90)
            j = 9;
        hashed[i]
        
    }
    return atoi( ss.str( ).c_str( ) );
}