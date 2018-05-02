/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on April 28, 2018, 7:23 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    //declare
    int terms, data;
    int count=1;
    int currentMax=0;
    multiset<int> theSet;
    set<int> modes;
    multiset<int>::iterator it;
    multiset<int>::iterator it2;
    set<int>::iterator modeIt;
    cout<<"How many terms are you going to enter?: \n";
    cin>>terms;
    cout<<"Enter the numbers: ";
    for(int i=0;i<terms;i++)
    {
        cout<<"Number "<<i+1<<": ";
        cin>>data;
        theSet.insert(data);
    }
    //loop
    for(it=theSet.begin();it!=theSet.end();it++)
    {
        //it2=it++;
        if(*it==*std::next(it))
        {
            count++;
            if(count>currentMax)
            {
                currentMax=count;
                modes.clear();
                modes.insert(*it);
            }
            else if(count==currentMax)
            {
                modes.insert(*it);
            }    
        }
        else
            count=1;
        
    }
    //display
    if(currentMax==1)
        cout<<"There is no mode\n\n";
    else
    {
        cout<<"The max frequency is "<<currentMax<<endl;
        cout<<"The mode(s) are: ";
        for(modeIt=modes.begin();modeIt!=modes.end();modeIt++)
            cout<<*modeIt<<" ";
    }
    
    
    //map
    multimap<int, int> mapped;
    multimap<int, int>::iterator its;
    modes.clear();
    currentMax=1;
    //fill data
    for(it=theSet.begin();it!=theSet.end();it++)
    {
        mapped.insert(std::make_pair(*it,1));
    }
    //loop
    for(its=mapped.begin();its!=mapped.end();its++)
    {
        if(mapped.count(its->first)>currentMax)
        {
            currentMax=mapped.count(its->first);
            modes.clear();
            modes.insert(its->first);
        }
        else if(mapped.count(its->first)==currentMax)
        {
            modes.insert(its->first);
        }
    }
        //display
        cout<<"\n\nFor map:\n";
        if(currentMax==1)
            cout<<"There is no mode\n\n";
        else
        {
            cout<<"The max frequency is "<<currentMax<<endl;
            cout<<"The mode(s) are: ";
            for(modeIt=modes.begin();modeIt!=modes.end();modeIt++)
                cout<<*modeIt<<" ";
        }
        
    
    return 0;
}

