#include <iostream>
using namespace std;
struct Tree {
    int Data;
    Tree *Left;
    Tree *Right;
};


void SearchInsIterativ (int x, Tree *&Root)
{
    Tree *p1, *p;
    int d;
    p1 = NULL;
    p = Root;
    d = 1;
    while (p != NULL && d != 0)
        if (x < p -> Data)
        {
            p1 = p;
            p = p -> Left;
            d = -1;
        }
        else if( x > p -> Data)
         {
            p1 = p;
            p = p -> Right;
            d = 1;
        }
        else d = 0;
    if (p != NULL)
        cout<<"am gasit";
    else
        {
        p = new Tree;
        p -> Data = x;
        p -> Left = NULL;
        p -> Right = NULL;
        if (p1 == NULL)
            Root = p;
        else if (d < 0)
            p1 -> Left = p;
        else
            p1 -> Right = p;
        }
}

Tree* deleteNode(Tree* Root, int x)
{
    Tree* nod,*v;
    int d=-1;
    v = Root;
    if (Root != NULL)
    {
        Tree* p = NULL;
        while(v!=NULL && v->Data!=x)
        {
            p=v;
            if (x < v->Data)
            {
                v= v->Left;
                d= 1;
            }
            else if (x > v->Data)
            {
                v = v->Right;
                d = 0;
            }
        }

        if(v->Data==x)
        {
            if (v->Left==NULL && v->Right==NULL)
            {
                v==NULL;
                if(d!=-1)
                {
                    if(d==1)
                    p->Left=NULL;
                else
                    p->Right = NULL;
                }
                else Root = NULL;
            }

            else if (v->Left == NULL)
            {
                if(d!=-1)
                {
                    if(d==1)
                    p->Left = v->Right;
                else
                    p->Right = v->Right;
                }
                else
                    Root = v->Right;
            }
            else if (v->Right == NULL)
            {
                if(d!=-1)
                {
                    if(d==1)
                    p->Left = v->Left;
                else
                    p->Right = v->Left;
                free(v);
                }
                else Root = v-> Left;
            }
        else
        {
            nod = v;
            p=nod;
            nod=nod->Right;
            while(nod->Left!=NULL)
            {
                p=nod;
                nod=nod->Left;
            }
            v -> Data = nod->Data;
            v->Right = deleteNode(v->Right,nod->Data);
        }

    }
    }
    return Root;
}
void RSD(Tree* Root)
{
    if(Root!=NULL)
    {
        cout<<Root->Data<<" ";
        RSD(Root->Left);
        RSD(Root->Right);
    }
}
int n,x;
int main()
{
    Tree* Root = NULL;
    Tree* Radacina = NULL;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        SearchInsIterativ(x,Root);
    }
    Root = deleteNode(Root,50);
    RSD(Root);
}
