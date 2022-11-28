 #include <iostream>
using namespace std;
struct Tree {
    int Data;
    Tree *Left;
    Tree *Right;
};

int k1,k2,n,i,x;
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

void Gasire(Tree *Root)
{
    if (Root!=NULL)
    {
        if(Root->Data>k1)
            Gasire(Root->Left);
        if(Root->Data>=k1 && Root->Data<=k2)
            cout<<Root->Data<<" ";
        Gasire(Root->Right);
    }

}

int main()
{
    Tree* Root = NULL;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        SearchInsIterativ(x,Root);
    }
    cin>>k1>>k2;
    Gasire(Root);


}
