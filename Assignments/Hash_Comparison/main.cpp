/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on May 16, 2018, 8:06 PM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include "Hash.h"

using namespace std;


static const char alpha[]=
"abcdefghijklmnopqrstuvwxyz";
static const char nums[]=
"1234567890";
int alphaL=sizeof(alpha)-1;
int numsL=sizeof(nums)-1;

char genRanAlpha()
{
    return alpha[rand() % alphaL];
}

char genRanNums()
{
    return nums[rand() % numsL];
}

int searchL (string arr[], const int n, string x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
         return i;
    return -1;
}

void sortArray(string names[], int size)
{
    int startScan, minIndex; 
    string minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = names[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (names[index] < minValue)
            {
                minValue = names[index];
                minIndex = index;
            }
        }
        names[minIndex] = names[startScan];
        names[startScan] = minValue;
    }
}

int searchB(string names[], int size, string value)
{
    int first = 0,             // First array element
        last = size - 1,       // Last array element
        middle,                // Mid point of search
        position = -1;         // Position of search value
    bool found = false;        // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2;     // Calculate mid point
        if (names[middle] == value)      // If value is found at mid
        {
            found = true;
            position = middle;
        }
        else if (names[middle] > value)  // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1;           // If value is in upper half
    }
    return position;
}

/*
 * 
 */
int main(int argc, char** argv) 
{
    srand (time(0));
    
    //declare
    const int size=10000;
    string arrayF[size]; //finable
    string arrayD[size]; //dummy vector
    string arrayS[size*2]; //complete vector
    
    //fill searchable array
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<20;j++)
            arrayF[i] += genRanAlpha();
    }
    //fill dummy searches
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<20;j++)
            arrayD[i] += genRanNums();
    }
    //fill search array
    for(int i=0;i<size;i++)
        arrayS[i]=arrayF[i];
    for(int j=size;j<size*2;j++)
        arrayS[j+size]=arrayD[j];
    
    //linear search
    int countL=0;
    int beg=time(0);
    for(int i=0;i<size*2;i++)
    {
        string search=arrayS[i];
        int searched;
        searched=searchL(arrayF, size, search);
        
        if(searched!=-1)
            countL++;
    }
    end=time(0);
    cout<<"Linear search time: "<<end-beg<<endl;

    //binary search
    int countB=0;
    int beg2=time(0);
    sortArray(arrayF,size);
    for(int i=0;i<size*2;i++)
    {
        string search=arrayS[i];
        int searched=searchB(arrayF,size,search);
        if(searched!=-1)
            countB++;
    }
    int end2=time(0);
    cout<<"Binary search time: "<<end2-beg2<<endl;
     
    
    //hash
    Hash hash(size);
    int beg3=time(0);
    for(int i=0;i<size;i++)
    {
        hash.insertItem(arrayF[i]);
    }
    for(int i;i<size*2;i++)
    {
        int search=hash.hashFunction(arrayS[i]);
        int searched=hash.HashSearch(search);
    }
    int end3=time(0);
    cout<<"Hash search time: "<<end3-beg3<<endl;
    
    return 0;
}

