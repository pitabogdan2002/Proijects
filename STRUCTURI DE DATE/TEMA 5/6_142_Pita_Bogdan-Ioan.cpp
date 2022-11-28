#include<iostream>
using namespace std;

struct Tree
{
    int Data;
    Tree *Left;
    Tree *Right;
    int Height;
};


Tree *RotatieDreapta(Tree *node)
{
    Tree *aux1 = node->Left;
    Tree *aux2 = aux1->Right;

    aux1->Right = node;
    node->Left = aux2;

    int l;
    if(node->Left!=NULL)
        l = node->Left->Height;
    else
        l=0;

    int r;
    if(node->Right!=NULL)
        r = node->Right->Height;
    else
        r=0;

    node->Height = max(l,r) + 1;

    if(aux1->Left!=NULL)
        l = aux1->Left->Height;
    else
        l=0;

    if(aux1->Right!=NULL)
        r = aux1->Right->Height;
    else
        r=0;
    aux1->Height = max(l,r) + 1;
    return aux1;
}
Tree *RotatieStanga(Tree *node)
{
    Tree *aux1 = node->Right;
    Tree *aux2 = aux1->Left;
    aux1->Left = node;
    node->Right = aux2;


    int l;
    if(node->Left!=NULL)
        l = node->Left->Height;
    else
        l=0;

    int r;
    if(node->Right!=NULL)
        r = node->Right->Height;
    else
        r=0;

    node->Height = max(l,r) + 1;

    if(aux1->Left!=NULL)
        l = aux1->Left->Height;
    else
        l=0;

    if(aux1->Right!=NULL)
        r = aux1->Right->Height;
    else
        r=0;
    aux1->Height = max(l,r) + 1;
    return aux1;
}

Tree* AVL(Tree* &nod, int x)
{
    if (nod == NULL)
    {
        Tree* node = new Tree();
        node->Data = x;
        node->Left = NULL;
        node->Right = NULL;
        node->Height = 1;
        return node;
    }

    if (x < nod->Data)
        nod->Left = AVL(nod->Left, x);
    else if (x > nod->Data)
        nod->Right = AVL(nod->Right, x);

    int l;
    if(nod->Left!=NULL)
        l = nod->Left->Height;
    else
        l=0;

    int r;
    if(nod->Right!=NULL)
        r = nod->Right->Height;
    else
        r=0;
    nod->Height = 1 + max(l,r);

    int balance = l-r;

    if (balance == 2 && x < nod->Left->Data)
        return RotatieDreapta(nod);

    if (balance == -2 && x > nod->Right->Data)
        return RotatieStanga(nod);

    if (balance == 2 && x > nod->Left->Data)
    {
        nod->Left = RotatieStanga(nod->Left);
        return RotatieDreapta(nod);
    }

    if (balance == -2 && x < nod->Right->Data)
    {
        nod->Right = RotatieDreapta(nod->Right);
        return RotatieStanga(nod);
    }

    return nod;
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
    Tree *Root = NULL;

    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>x;
        Root = AVL(Root,x);
    }
    RSD(Root);
}
