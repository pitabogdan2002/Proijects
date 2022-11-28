#include <iostream>
using namespace std;

struct Node
{
    int Data;
    Node *Next;
};
    Node *pred =new Node();
    Node *nr1 =new Node();
    Node *nr2 =new Node();
    Node *nod =new Node();
    Node *Head = new Node();
    Node *oldp = new Node();
    Node *Front = new Node();
    Node *Rear = new Node();
    Node *p;
    int n ,i;
    int v[100],f[100];
    int ok =1;
int main()
{
    Rear = NULL;
    Front = NULL;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>v[i];
        Node *nod =new Node();
        nod->Data=v[i];
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
    int maxi = 0;
    int nr= 0 ;
    nod = Front;
    while(nod!=NULL)
    {
        if(nod->Data>=maxi)
        {
            nr++;
            maxi = nod->Data;
        }
        nod=nod->Next;
    }
    if(nr%2==1)
        cout<<"Valid";
    else
        cout<<"Invalid";
    return 0;

}
