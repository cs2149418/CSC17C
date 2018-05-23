/* 
 * File:   main.cpp
 * Author: Curtis Stephens
 *
 * Created on May 22, 2018, 10:29 PM
 */

# include <iostream>
# include <cstdlib>

using namespace std;

struct node
{
    int linf;
    struct node *lft1;
    struct node *rgt1;
}*rot1;

//Define class

class Treee

{
    public:
    void Srch(int, node **, node **);   
    void Insrt(node*, node*);
    void Delte(int);
    void CseA(node *,node *);
    void CseB(node *,node *);
    void CseC(node *,node *);
    void prordr(node *);
    void inordr(node *);
    void pstordr(node *);
    void Dsply(node *, int);

    Treee()
    {
        rot1 = nullptr;
    }
};

  

//Define main

int main()
{
    int chce, nm;
    Treee bst;
    node *temp;
    while (chce!=7)
    {
        cout<<"-----------------"<<endl;
        cout<<"Tree Operations "<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        cout<<"2.Delete Element "<<endl;
        cout<<"3.Inorder Traversal"<<endl;
        cout<<"4.Preorder Traversal"<<endl;
        cout<<"5.Postorder Traversal"<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>chce;
        
        if(chce==1)
        {
            temp = new node;
            cout<<"Enter insertion number: ";
            cin>>temp->linf;
            bst.Insrt(rot1, temp);
        }
        
        else if(chce==2)
        {
            if (rot1 == nullptr)
            {
                cout<<"Empty tree"<<endl;
                continue;
            }
            cout<<"Enter deletion number : ";
            cin>>nm;
            bst.Delte(nm);
        }
        
        else if(chce==3)
        {
            cout<<"Inorder Traversal :"<<endl;
            bst.inordr(rot1);
            cout<<endl;
        }
        
        else if(chce==4)
        {
            cout<<"Preorder Traversal:"<<endl;
            bst.prordr(rot1);
            cout<<endl;  
        }
        
        else if(chce==5)
        {
            cout<<"Postorder Traversal:"<<endl;
            bst.pstordr(rot1);
            cout<<endl;
        }
        
        else if(chce==6)
        {
            cout<<"Display Treee:"<<endl;
            bst.Dsply(rot1,1);
            cout<<endl;
        }
    }
}


void Treee::Srch(int Itm, node **lpr1, node **lc1)
{
    node *lpr, *prsve;
    if (rot1 = nullptr)
    {
        *lc1 = nullptr;
        *lpr1 = nullptr;
        return;
    }
    if (Itm == rot1->linf)
    {
        *lc1 = rot1;
        *lpr1 = nullptr;
        return;
    }
    if (Itm < rot1->linf)
    lpr = rot1->lft1;
    else
    lpr = rot1->rgt1;
    prsve = rot1;

    while (lpr != nullptr)
    {
        if (Itm == lpr->linf)
        {
            *lc1 = lpr;
            *lpr1 = prsve;
            return;
        }
        prsve = lpr;
        if (Itm < lpr->linf)
            lpr = lpr->lft1;
        else
            lpr = lpr->rgt1;
    }

    *lc1 = nullptr;
    *lpr1 = prsve;
}


void Treee::Insrt(node *tree, node *nwnde)
{
    if (rot1 == nullptr)
    {
        rot1 = new node;
        rot1->linf = nwnde->linf;
        rot1->lft1 = nullptr;
        rot1->rgt1 = nullptr;
        cout<<"Root Node is Added"<<endl;
        return;
    }

    if (tree->linf == nwnde->linf)
    {
        cout<<"Element present in tree"<<endl;
        return;
    }

    if (tree->linf > nwnde->linf)
    {
        if (tree->lft1 != nullptr)
        {
            Insrt(tree->lft1, nwnde);
        }
        else
        {
            tree->lft1 = nwnde;
            (tree->lft1)->lft1 = nullptr;
            (tree->lft1)->rgt1 = nullptr;
            cout<<"Node is inserted To Left"<<endl;
            return;
        }
    }
    
    else
    {
        if (tree->rgt1 != nullptr)
        {
            Insrt(tree->rgt1, nwnde);
        }
        else
        {
            tree->rgt1 = nwnde;
            (tree->rgt1)->lft1 = nullptr;
            (tree->rgt1)->rgt1 = nullptr;
            cout<<"Node is inserted to Right"<<endl;
            return;
        }
    }
}

void Treee::Delte(int Itm)
{
    node *prnt, *lctn;
    if (rot1 == nullptr)
    {
        cout<<"Tree empty"<<endl;
        return;
    }

    Srch(Itm, &prnt, &lctn);
    if (lctn == nullptr)
    {
        cout<<"Item not in tree"<<endl;
        return;
    }

    if (lctn->lft1 == nullptr && lctn->rgt1 == nullptr)
        CseA(prnt, lctn);
    if (lctn->lft1 != nullptr && lctn->rgt1 == nullptr)
        CseB(prnt, lctn);
    if (lctn->lft1 == nullptr && lctn->rgt1 != nullptr)
        CseB(prnt, lctn);
    if (lctn->lft1 != nullptr && lctn->rgt1 !=nullptr)
        CseC(prnt, lctn);
    free(lctn);
}

void Treee::CseA(node *lpr1, node *lc1 )
{
    if (lpr1 == nullptr)
    {
        rot1 = nullptr;
    }
    else
    {
        if (lc1 == lpr1->lft1)
            lpr1->lft1 = nullptr;

        else
            lpr1->rgt1 = nullptr;
    }
}

void Treee::CseB(node *lpr1, node *lc1)
{
    node *child;
    if (lc1->lft1 != nullptr)
        child = lc1->lft1;
    else
        child = lc1->rgt1;
    if (lpr1 == nullptr)
    {
        rot1 = child;
    }
    else
    {
        if (lc1 == lpr1->lft1)
            lpr1->lft1 = child;
        else
            lpr1->rgt1 = child;
    }
}

void Treee::CseC(node *lpr1, node *lc1)
{
    node *lpr, *prsve, *sc1, *parsuc;
    prsve = lc1;
    lpr = lc1->rgt1;
    while (lpr->lft1 != nullptr)
    {
        prsve = lpr;
        lpr = lpr->lft1;
    }
    sc1 = lpr;
    parsuc = prsve;
    if (sc1->lft1 == nullptr && sc1->rgt1 == nullptr)
        CseA(parsuc, sc1);

    else
        CseB(parsuc, sc1);
    
    if (lpr1 == nullptr)
        rot1 = sc1;
    
    else
    {
        if (lc1 == lpr1->lft1)
            lpr1->lft1 = sc1;
        else
            lpr1->rgt1 = sc1;
    }
    sc1->lft1 = lc1->lft1;
    sc1->rgt1 = lc1->rgt1;
}

void Treee::prordr(node *lpr)
{
    if (rot1 == nullptr)
    {
        cout<<"Empty tree"<<endl;
        return;
    }

    if (lpr != nullptr)
    {
        cout<<lpr->linf<<" ";
        prordr(lpr->lft1);
        prordr(lpr->rgt1);
    }
}

void Treee::inordr(node *lpr)
{
    if (rot1 == nullptr)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (lpr != nullptr)
    {
        inordr(lpr->lft1);
        cout<<lpr->linf<<" ";
        inordr(lpr->rgt1);
    }
}

void Treee::pstordr(node *lpr)
{
    if (rot1 == nullptr)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (lpr != nullptr)
    {
        pstordr(lpr->lft1);
        pstordr(lpr->rgt1);
        cout<<lpr->linf<<" ";
    }
}

void Treee::Dsply(node *lpr, int lvl)
{
    int li;
    if (lpr != nullptr)
    {
        Dsply(lpr->rgt1, lvl+1);
        cout<<endl;
        if (lpr == rot1)
        cout<<"Root->: ";
        else
        {
            for (li = 0;li < lvl;li++)
            cout<<"       ";
        }
        cout<<lpr->linf;
        Dsply(lpr->lft1, lvl+1);
    }
}