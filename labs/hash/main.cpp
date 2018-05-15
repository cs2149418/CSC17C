#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

/*
 Created by Curtis Stephens for CSC 17C Hashing Lab
 
 */
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    for(int i=5;i<25;i++)
    {
        int size=pow(2,i);
        vector<int> vect(size,0);
        int collision=0;
        
        for(int j=0;j<size;j++)
        {
            int index=rand()%size;
            vect[index]++;
            if(vect[index]>=2)
            {
                collision=j;
                break;
            }
        }
        
        //output
        cout<<"\n\nVector Length is "<< size<<endl;
        cout<<"Where first collision happened: "<<collision<<endl;
    }

    return 0;
}

