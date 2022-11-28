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
int n,x,n1,n2;
int main()
{
    Tree* Root = NULL;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        SearchInsIterativ(x,Root);
    }
    cin>>n1>>n2;
    while(Root->Data>n1 && Root->Data>n2 || Root->Data<n1 && Root->Data<n2)
    {
        if(Root->Data>n1 && Root->Data>n2)
            Root = Root->Left;
        else if (Root->Data<n1 && Root->Data<n2)
            Root = Root->Right;
    }
    cout<<Root->Data;
    return 0;
}
