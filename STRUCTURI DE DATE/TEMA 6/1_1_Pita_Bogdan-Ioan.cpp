#include <iostream>
using namespace std;

struct Node
{
    string Data;
    Node *Next;
    int frecventa;
    Node* dreapta;
    Node* stanga;
};
void RSD(Node* Root)
{
    if(Root!=NULL)
    {
        cout<<Root->Data<<" ";
        RSD(Root->stanga);
        RSD(Root->dreapta);
    }
}
void Inserare(Node* &Front, Node* &Rear, Node* nod)
{
    Node *pred =new Node();
    Node *p = new Node();
    p = Front;
    if(Front==NULL)
    {
        Front=nod;
        Rear = nod;
    }
    else if(nod->frecventa<Front->frecventa)
    {
        p = Front;
        nod->Next = p;
        Front = nod;
    }
    else
    {
        while(p!=NULL && nod->frecventa>p->frecventa)
        {
            pred=p;
            p=p->Next;
        }
        if(p!=NULL)
        {
            pred->Next=nod;
            nod->Next = p;
        }
        else if(p==NULL )
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
void Stergere(Node* &Front, Node* &Rear)
{
    Front=Front->Next;
}
string codificare(string c, Node* Root)
{
    string solutie = "";
    Node* nod = new Node();
    for(int i=0; i<c.size(); i++)
    {
        string s ="";
        s= s+c[i];
        nod = Root;
        while(nod->Data!=s)
        {
            int ok = 0;
            for(int  j=0; j<nod->stanga->Data.size(); j++)
                if(nod->stanga->Data[j]==c[i])
                    ok=1;

            if(ok)
            {
                solutie+="0";
                nod=nod->stanga;
            }
            else
            {
                solutie+="1";
                nod=nod->dreapta;
            }
        }
    }
    return solutie;
}
string decodificare(string c, Node* Root)
{
    string solutie = "";
    Node* nod = new Node();
    nod = Root;
    for (int i=0;i<c.size();i++)
    {
        if (c[i] == '0')
           nod= nod->stanga;
        else
           nod = nod->dreapta;
        if (nod->stanga==NULL and nod->dreapta==NULL)
        {
            solutie+=nod->Data;
            nod = Root;
        }
    }
    return solutie;
}
    Node *pred =new Node();
    Node *nod =new Node();
    Node *Head = new Node();
    Node *oldp = new Node();
    Node *Front = new Node();
    Node *Rear = new Node();
    Node *z;
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
        cin>>nod->frecventa;
        nod->Next=NULL;
        Inserare(Front,Rear,nod);
    }
    nod=Front;
    while(nod!=NULL)
    {
        cout<<nod->Data<<" "<<nod->frecventa<<endl;
        nod = nod->Next;
    }

    for(i=1; i<n; i++)
    {
        Node* z = new Node();
        nod = Front;
        cout<<nod->Data;
        z->dreapta = new Node();
        z->dreapta = nod;
        cout<<z->dreapta->Data;
        z->frecventa = nod->frecventa;
        cout<<z->frecventa;
        z->Data = nod->Data;
        Stergere(Front,Rear);
        nod = Front;
        z->stanga = new Node();
        z->stanga = nod;
        z-> frecventa += nod->frecventa;
        z->Data += nod->Data;
        cout<<z->Data<<" "<<z->frecventa<<endl;
        Stergere(Front,Rear);
        Inserare(Front,Rear,z);
    }
    nod = Front;
    cout<<nod->Data<<" "<<nod->frecventa;
    RSD(Front);
    cout<< codificare("aba",Front)<<endl;
    cout<<decodificare("0100",Front)<<endl;
    return 0;

}
