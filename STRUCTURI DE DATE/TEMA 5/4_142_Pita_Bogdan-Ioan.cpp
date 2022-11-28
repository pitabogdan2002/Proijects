#include <iostream>
#include <cstring>
using namespace std;
struct Tree {
    char *Data;
    Tree *Left;
    Tree *Right;
};


void SearchInsIterativ (char* x, Tree *&Root)
{
    Tree *p1, *p;
    int d;
    p1 = NULL;
    p = Root;
    d = 1;
    while (p != NULL && d != 0)
        if (strcmp(x , p -> Data)<0)
        {
            p1 = p;
            p = p -> Left;
            d = -1;
        }
        else if( strcmp(x, p -> Data)>0)
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
void Afisare(Tree* Root)
{
    if(Root!=NULL)
    {

        Afisare(Root->Right);
        cout<<Root->Data<<" ";
        Afisare(Root->Left);
    }
}

int k1,k2,n,i,x;
char *v[100];
int main()
{
    v[0]="ana";
    v[1]= "verde";
    v[2] = "casa";
    v[3] = "albastru";
    v[4] = "mare";
    v[5] = "copac";
    Tree* Root = NULL;
    for(i=0; i<6; i++)
    {
        SearchInsIterativ(v[i],Root);
    }
    Afisare(Root);
}
