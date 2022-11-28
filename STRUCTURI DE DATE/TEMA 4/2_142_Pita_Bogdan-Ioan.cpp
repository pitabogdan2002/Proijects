#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    Node *Next;
    int n;
};
struct Node2
{
    char Data;
    Node2 * Next;
};
    Node *pred =new Node();
    Node *nod =new Node();
    Node *Head = new Node();
    Node *oldp = new Node();
    Node *TopNr = new Node();
    Node2 *TopOp = new Node2();
    Node2 *p;
    Node *r;
    int i;
    int v[100],f[100],nr2,nr1,nr;
    int ok =1;
    char s[100];
int main()
{
    TopNr = NULL;
    TopOp = NULL;
    p=NULL;
    cin.getline(s,100);
    cout<<s;
    for(i=0; i<strlen(s); i++)
        if(s[i] =='+' || s[i] == '(' || (s[i]=='-' && s[i+1]==' '))
        {
            if(TopOp==NULL)
                {
                    TopOp->Data = s[i];
                    TopOp->Next = NULL;
                }
            else
            {
                p->Data = s[i];
                p->Next = TopOp;
                TopOp = p;
            }
        }
        if(s[i]=='-' && s[i+1]!=' ')
        {
            if(TopNr==NULL)
                {
                    TopNr->n = 0;
                    TopNr->Next = NULL;
                }
            else
            {
                r->n = 0;
                r->Next = TopNr;
                TopNr = r;
            }
            if(TopOp==NULL)
                {
                    TopOp->Data = s[i];
                    TopOp->Next = NULL;
                }
            else
            {
                p->Data = s[i];
                p->Next = TopOp;
                TopOp = p;
            }
        }
        if(s[i]>='0' && s[i]<='9')
        {
            int nr=0;
            while(s[i]>='0' && s[i]<='9')
            {
                nr = nr * 10 + int(s[i]);
                i++;
            }
            i--;
            if(TopNr==NULL)
                {
                    TopNr->n =nr;
                    TopNr->Next=NULL;
                }
            else
            {
                r->n = nr;
                r->Next = TopNr;
                TopNr = r;
            }
        }
        if(s[i]==')')
            {while(TopOp->Data!='(')
            {
                nr1 = TopNr->n;
                TopNr=TopNr->Next;
                nr2 = TopNr->n;
                if(TopOp->Data == '+')
                    nr = nr1+nr2;
                if(TopOp->Data == '-')
                    nr = nr2-nr1;
                TopOp=TopOp->Next;
                TopNr -> n = nr;
            }
            TopOp=TopOp->Next;
            }

}
