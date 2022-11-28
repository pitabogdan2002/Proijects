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

void RSD(Tree* Root)
{
    if(Root!=NULL)
    {
        cout<<Root->Data<<" ";
        RSD(Root->Left);
        RSD(Root->Right);
    }
}
void SRD(Tree* Root)
{
    if(Root!=NULL)
    {
        SRD(Root->Left);
        cout<<Root->Data<<" ";
        SRD(Root->Right);
    }
}
void SDR(Tree* Root)
{
    if(Root!=NULL)
    {
        SDR(Root->Left);
        SDR(Root->Right);
        cout<<Root->Data<<" ";
    }
}
int n,x;
int main()
{
    Tree* Root = NULL;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        SearchInsIterativ(x,Root);
    }
    RSD(Root);
    SRD(Root);
    SDR(Root);
}
