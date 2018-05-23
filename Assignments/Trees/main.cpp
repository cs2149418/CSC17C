/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on May 22, 2018, 7:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;
  
struct Node
{
    int key;
    vector<Node *>child;
};
  
Node *newNode(int key)
{
    Node *temp = new Node;
    temp->key = key;
    return temp;
}
 

void print(Node * root)
{
    if (root==nullptr)
        return;
  

    queue<Node *> q;  
    q.push(root); 
    while (!q.empty())
    {
        int n = q.size();
 
        while (n > 0)
        {
            Node * p = q.front();
            q.pop();
            cout << p->key << " ";
  
            
            for (int i=0; i<p->child.size(); i++)
                q.push(p->child[i]);
            n--;
        }
  
        cout << endl; 
    }
}
  
// Driver program
int main()
{
    int leaves;
    int count=0;
    cout<<"How many leaves can a tree have at most? ";
    cin>>leaves;
    

    Node *root = newNode(10);        
    (root->child).push_back(newNode(2));
    (root->child).push_back(newNode(34));
    (root->child).push_back(newNode(56));
    (root->child).push_back(newNode(100));
    (root->child[0]->child).push_back(newNode(77));
    (root->child[0]->child).push_back(newNode(88));
    (root->child[2]->child).push_back(newNode(1));
    (root->child[3]->child).push_back(newNode(7));
    (root->child[3]->child).push_back(newNode(8));
    (root->child[3]->child).push_back(newNode(9));
  
    print(root);
   
    return 0;
} 