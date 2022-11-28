#include <iostream>
using namespace std;
struct Node
{
int Data;
Node *Next;
};
int i,n,nr1,nr2,c;
int main()
{
    cin>>n;
    Node *Head1 = new Node();
    Node *Head2 = new Node();
    Node *pred = new Node();
    Node *nod = new Node();
    Head1=NULL;
    Head2=NULL;
    Node *p;
    for(i=1; i<=n; i++)
    {
        p = new Node();
        cin>>p->Data;
        p->Next = NULL;
        if(Head1==NULL)
        {
            Head1 = p;
            pred = Head1;
        }
        else
        {
            nod=p;
            pred->Next=nod;
            pred=nod;
        }
    }
    cin>>n;
    for(i=1; i<=n; i++)
    {
        p = new Node();
        cin>>p->Data;
        p->Next = NULL;
        if(Head2==NULL)
        {
            Head2 = p;
            pred = Head2;
        }
        else
        {
            nod = p;
            pred ->Next = nod;
            pred = nod;
        }
    }
    c=1;
    nod=Head1;
      while(nod!=NULL)
        {
            nr1=nr1+nod->Data*c;
            nod = nod->Next;
            c=c*10;
        }
    c=1;
    nod=Head2;
    while(nod!=NULL)
    {
        nr2=nr2+nod->Data*c;
        c=c*10;
        nod = nod->Next;
    }
    cout<<nr1<<endl;
    cout<<nr2<<endl;
    cout<<nr1+nr2<<endl;
}
