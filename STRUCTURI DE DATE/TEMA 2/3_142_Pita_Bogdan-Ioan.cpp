#include <iostream>
#include <math.h>
using namespace std;
struct Node {
int Grade, Coef;
Node *Next;
};
void InmultireScalar(float x, Node* Head)
{
    Node* nod = new Node();
    nod = Head;
    while(nod!=NULL)
    {
        cout<<nod->Coef*x<<"x^"<<nod->Grade<<" ";
        nod = nod->Next;
    }
    cout<<endl;
}
int ValoarePolinom(int x, Node* Head)
{
    Node *nod = new Node();
    int sum = 0;
    nod = Head;
    while(nod!=NULL)
    {
        sum = sum + nod->Coef * pow(x,nod->Grade);
        nod = nod -> Next;
    }
    return sum;
}
void AdunarePolinoame(Node* HeadP, Node* HeadQ)
{
    Node* nod = new Node();
    Node* nod2 = new Node();
    nod=HeadP;
    nod2=HeadQ;
    while(nod->Grade>nod2->Grade)
    {
        cout<<nod->Coef<<"x^"<<nod->Grade<<" ";
        nod = nod->Next;
    }
    while(nod2->Grade>nod->Grade)
    {
        cout<<nod2->Coef<<"x^"<<nod2->Grade<<" ";
        nod2 = nod2->Next;
    }
    while(nod!=NULL)
    {
        cout<<(nod2->Coef+nod->Coef)<<"x^"<<nod2->Grade<<" ";
        nod = nod->Next;
        nod2 = nod2->Next;
    }
}



int i,n,m;
int main()
{

    cin>>n;
    Node *HeadP = new Node();
    Node *HeadQ = new Node();
    Node *pred = new Node();
    Node *nod = new Node();
    Node *p ;
    Node *nod2 = new Node();
    HeadP=NULL;
    HeadQ=NULL;
    for(i=1; i<=n+1; i++)
    {
        p = new Node();
        p->Grade = n+1-i;
        cin>>p->Coef;
        p->Next = NULL;
        if(HeadP==NULL)
        {
            HeadP = p;
            pred = HeadP;
        }
        else
        {
            nod = p;

            pred ->Next = nod;
            pred = nod;
        }
    }
    cin>>m;
    for(i=1; i<=m+1; i++)
    {
        p = new Node();
        p->Grade = m+1-i;
        cin>>p->Coef;
        p->Next = NULL;
        if(HeadQ==NULL)
        {
            HeadQ = p;
            pred = HeadQ;
        }
        else
        {
            nod = p;
            pred ->Next = nod;
            pred = nod;
        }
    }
    InmultireScalar(3,HeadP);
    cout<<ValoarePolinom(4,HeadP)<<endl;
    AdunarePolinoame(HeadP,HeadQ);
    return 0;
}
