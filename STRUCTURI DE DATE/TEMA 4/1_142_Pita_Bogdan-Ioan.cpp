#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
    int prioritate;
};

void Inserare(Node* Front, Node* Rear, Node* nod)
{
    Node *pred =new Node();
    Node *p = new Node();
    p = Front;
    if(Front==NULL)
    {
        Front=nod;
        Rear = nod;
    }
    else
    {
        while(p!=NULL && nod->prioritate>p->prioritate )
        {
            pred=p;
            p=p->Next;
        }
        if(p!=NULL)
        {
            pred->Next=nod;
            nod->Next = p;
        }
        else
        {
            Rear->Next=nod;
            Rear=nod;
        }
    }
    p=Front;
    while(p!=NULL)
    {
        cout<<p->Data<<" ";
        p = p->Next;
    }
    cout<<endl;
}
void Stergere(Node* Front, Node* Rear)
{
    Node *p = new Node();
    while(Front!=NULL)
    {
        Front=Front->Next;
        p=Front;
        while(p!=NULL)
        {
            cout<<p->Data<<" ";
            p = p->Next;
        }
        cout<<endl;
    }
}
    Node *pred =new Node();
    Node *nod =new Node();
    Node *Head = new Node();
    Node *oldp = new Node();
    Node *Front = new Node();
    Node *Rear = new Node();
    Node *p;
    int n ,i;
int main()
{
    Rear = NULL;
    Front = NULL;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        Node *nod =new Node();
        cin>>nod->Data;
        cin>>nod->prioritate;
        nod->Next=NULL;
        if(Rear==NULL)
            Front=nod;
        else
            Rear->Next=nod;
        Rear = nod;
    }
    nod=Front;
    while(nod!=NULL)
    {
        cout<<nod->Data<<" ";
        nod = nod->Next;
    }
    cout<<endl;
    cin>>Head->Data;
    cin>>Head->prioritate;
    Head->Next=NULL;
    Inserare(Front,Rear, Head);
    Stergere(Front, Rear);
}

