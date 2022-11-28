#include <iostream>
using namespace std;
struct Node
{
int Data;
Node *Next;
};
int i,n;
int main()
{
cin>>n;
    Node *Head = NULL;
    Node *oldp = NULL;
    Node *nod = NULL;
    Node *p = NULL;
    for(i=1; i<=n; i++)
    {
        p = new Node();
        cin>>p->Data;
        p->Next = NULL;
        if(Head==NULL)
        {
            Head = p;
            oldp = Head;
        }
        else
        {
            nod = p;

            oldp ->Next = nod;
            oldp = nod;
        }
    }
    nod = Head;
          while(nod!=NULL)
        {
            cout<<nod->Data<<" ";
            nod = nod->Next;
        }
    cout<<endl;
    nod=Head;
    nod = nod ->Next->Next;
    cout<<nod->Data<<endl;
    nod->Data = nod->Next->Data;
    oldp = nod;
    nod=nod->Next;
    oldp->Next = nod->Next;
    free(nod);
    nod =Head;
    while(nod!=NULL)
    {
        cout<<nod->Data<<" ";
        nod = nod->Next;
    }
    return 0;
}
