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

int Hash(string); 


int main() {

    srand( time( 0 ) );
    int size = 512;
    string in = " ";
    map<int, int> store;
    int array[size];
    for(int i=0; i<size; i++) 
        array[i] = 0;

    for(int i=0; i<size; i++) 
    {
        in[0] =(char)(rand( )%26+65);
        in[1] =(char)(rand( ) %26+65);
        in[2] =(char)(rand( ) %26+65);
        int hash = Hash(in);
        array[hash % size]++;
    }
    for(int i=0; i<size; i++) 
    {
        if(store.count(array[i]) <=0) 
            store[ array[i] ] = 1;
        else
            store[array[i]]++;
    }
    
    int total = 0;
    for(map<int, int>::iterator it =store.begin( ); it !=store.end( ); it++ ) 
    {
        if ( it->first != 0 )
            total += it->second;
        cout << "Collision Number: "<<it->first <<endl 
                <<"First Occurrence:"<< it->second << endl;

    }
    cout << "\n\nMax number of collisions is: " << (--store.end( ) )->first <<endl;
    cout << "All collisions: " << total << endl;

return 0;

}

int Hash(string str) 
{
    stringstream ss;
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
        ss << "" << j;
    }
    return atoi( ss.str( ).c_str( ) );
}