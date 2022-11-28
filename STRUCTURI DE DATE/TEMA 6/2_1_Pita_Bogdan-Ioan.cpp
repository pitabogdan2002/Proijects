//f(prenume) = int(prenume[0])-97
#include <iostream>
#include <cstring>
using namespace std;
struct Nod
{
    Nod* Next;
    string Data;
};
void stergere(Nod **v, string student)
{
    char c;
    for(int i=0; i<student.size(); i++)
        if(student[i]==' ')
        {
            c=student[i+1];
            break;
        }
    Nod* nod;
    nod = v[int(c)-97];
    Nod* p = NULL;
    while(nod!=NULL)
    {
        if(nod->Data==student)
            if(p==NULL)
            {
                if(nod->Next==NULL)
                    nod->Data = "gol";
                else
                v[int(c)-97] = nod->Next;
            }
            else
            {
                p->Next = nod->Next;
            }
        p=nod;
        nod=nod->Next;
    }
    for(int i=0; i<=25; i++)
    {
        nod=v[i];
        cout<<char(97+i)<<": ";
        if(nod->Data!="gol")
        {
            while(nod!=NULL)
        {
            cout<<nod->Data<<" | ";
            nod=nod->Next;
        }
        }
        cout<<endl;
    }
}
void cautare(Nod **v, string student)
{
    int ok=0;
    char c;
    for(int i=0; i<student.size(); i++)
        if(student[i]==' ')
        {
            c=student[i+1];
            break;
        }
    Nod* nod;
    nod = v[int(c)-97];
    while(nod!=NULL)
    {
        if(nod->Data==student)
        {
            ok = 1;
            break;
        }
        nod=nod->Next;
    }
    if(ok)
        cout<<"am gasit";
    else
        cout<<"nu exista acest student";
}
int i,n,nr=97;
string prenume,nume,numeComplet;
char a;
int main()
{
    string b="popa maria";
    string c="popescu dan";
    Nod* nod = NULL;
    Nod **v= new Nod*[25];
    for(i=0; i<=25; i++)
    {
        v[i]=new Nod();
        v[i]->Next = NULL;
        v[i]->Data = "gol";
        //nod = v[i];
        //nod->Data = 1;
        //cout<<nod->Data<<" ";
        //cout<<endl;
    }
    Nod* p = NULL;

    cin>>n;
    cin.get();
    for(i=1; i<=n; i++)
    {
        cin>>nume;
        cin>>prenume;
        a=prenume[0];
        numeComplet = nume+" "+prenume;
        nod = v[int(a)-97];
        if(nod->Data=="gol")
        {
            nod->Data = numeComplet;
            nod->Next = NULL;
        }
        else
        {
            while(nod->Next!=NULL)
                nod=nod->Next;
            p=new Nod();
            p->Data = numeComplet;
            p->Next = NULL;
            nod->Next = p;
        }
        cin.get();
    }
    for(i=0; i<=25; i++)
    {
        nod=v[i];
        cout<<char(97+i)<<": ";
        if(nod->Data!="gol")
        {
            while(nod!=NULL)
        {
            cout<<nod->Data<<" | ";
            nod=nod->Next;
        }
        }
        cout<<endl;
    }
    stergere(v,b);
    cautare(v,c);
    return 0;
}

