/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on May 31, 2018, 7:58 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

struct Clerk 
{
    bool busy;
    int startTime;
    int served;
};

int main() 
{
    queue<int> customers;
    vector< Clerk > clerks; //status, secs with customer
    for(int i=0; i<3; i++) 
    {
        Clerk clerk;
        clerk.busy = false;
        clerk.startTime = 0;
        clerk.served = 0;
        clerks.push_back( clerk );
    }
    int wait = 0;
    bool waiting = true;
    int runTime =60*60;
    int clerktimes[] = {60, 120, 80};
    int totalCust = 0;


    for(int sec=0; sec<=runTime; sec+=5) 
    { 
        bool free = false;
        for(int i=0; i<clerks.size( ); i++) 
        {
            int delta=(i>2 ? 60 : clerktimes[i]);
            //busy
            if ( clerks[i].busy ) 
            {
                if ( clerks[i].startTime + delta == sec ) 
                {
                    clerks[i].busy = false;
                    clerks[i].startTime = 0;
                    clerks[i].served++;
                    free = true;
                }
            }
        }
        if ( sec % 20 == 0 ) 
        {
            customers.push( 1 ); //add customer every 20 secs
            totalCust++;
        }
        waiting = true;
        if ( customers.size( ) > 0 ) 
        {
            //check for open clerk
            for ( int i = 0; i < clerks.size( ); i++ ) 
            {
                if ( !( clerks[i].busy ) && customers.size( ) > 0 ) 
                { 
                    waiting = false;
                    clerks[i].busy = true;
                    clerks[i].startTime = sec;
                    customers.pop( );
                }

            }
            //if all clerks taken add time to wait for all the customers
            wait += ( waiting ? 5 * customers.size( ) : 0 );
        }
        



        if ( customers.size( ) > 5 && !free ) 
        {
            Clerk clerk;
            clerk.busy = false;
            clerk.startTime = 0;
            clerk.served = 0;
            clerks.push_back( clerk );
        }
    if(customers.size() == 0 && clerks.size()>3)
        clerks.pop_back();

}
cout << "the number of customers is " << totalCust << endl;
for( int i = 0; i < clerks.size(); i++ )
    cout << "clerk " << i + 1 << " served " << clerks[i].served << endl;
cout << "average wait is " << ( wait / 60.0f ) / totalCust<< " minutes" << endl;




return 0;

}