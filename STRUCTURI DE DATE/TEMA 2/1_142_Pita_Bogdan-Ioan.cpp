#include <iostream>
using namespace std;
struct Node
{
int Data;
Node *Next;
};
    Node *pred =new Node();
    Node *nod =new Node();
    Node *Head = new Node();
    Node *oldp = new Node();
    Node *p;
    int n ,i;
void creareListaOrdonata()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        p = new Node();
        cin>>p->Data;
        p->Next = NULL;
        if(i==1)
            Head = p;
        else
        {
            if(Head->Data>p->Data)
            {
                p->Next = Head;
                Head = p;
            }
            else
            {
                nod = Head->Next;
                pred = Head;
                while(nod!=NULL)
                {
                    if(p->Data<nod->Data)
                    {
                        pred->Next = p;
                        p->Next = nod;
                        break;
                    }
                    pred = nod;
                    nod = nod->Next;
                }
                if(nod==NULL)
                    pred->Next=p;
            }
        }
    }
    nod=Head;
    while(nod!=NULL)
    {
        cout<<nod->Data<<" ";
        nod = nod->Next;
    }
    cout<<endl;
}
void stergereValoare(int val, Node *Head)
{
    p = new Node();
    p=Head;
     while (p!=NULL && val!=p->Data)
    {
        oldp=p;
        p = p -> Next;
    }
    if (p==NULL)
        cout<<"nu exista";
    else
        oldp -> Next = p-> Next;
        free(p);

    nod = Head;
    while(nod!=NULL)
    {
        cout<<nod->Data<<" ";
        nod = nod->Next;
    }
    cout<<endl;
}
void stergereLista(Node* Head)
{
     while(Head!=NULL)
    {
        cout<<"pozitie existenta: ";
        cin>>i;
        if(i==1)
            Head = Head ->Next;
        else
        {
            nod = Head;
            for(int j=1; j<i; j++)
            {
                oldp = nod;
                nod = nod->Next;
            }
            oldp -> Next = nod -> Next;
            free(nod);
        }
        nod = Head;
            while(nod!=NULL)
            {
                cout<<nod->Data<<" ";
                nod = nod->Next;
            }
            cout<<endl;
    }
}

int val;
int main()
{
    creareListaOrdonata();
    cin>>val;
    stergereValoare(val,Head);
    stergereLista(Head);
    return 0;
}
