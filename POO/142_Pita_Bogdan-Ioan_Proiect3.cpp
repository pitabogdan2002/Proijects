#include <iostream>
#include <map>
#include <list>
#include <set>
#include <cstring>
#include<vector>
using namespace std;


template <class C=int>
class Comparare
{
private:
    C a,b;
public:
    Comparare(C var1, C var2)
    {
        a=var1;
        b=var2;
    }
    void Compare()
    {
        try{
        if(a<b)
            cout<<a;
        else if(b<a)
            cout<<b;
        else
        {
            throw(a);
        }
        }
            catch(C v)
        {
            cout<<"Elemente Egale"<<endl;
        }
    }

};


template<class C1>
void interschimbare(C1 &a, C1 &b)
{

    C1 aux;
    aux= a;
    a=b;
    b=aux;
}
template<>
void interschimbare(char* &a, char* &b)
{
     char* aux=new char[strlen(a)+1];
     strcpy(aux,a);
     delete[] a;
     a= new char[strlen(b)+1];
     strcpy(a,b);
     delete[] b;
     b= new char[strlen(aux)+1];
    strcpy(b,aux);
}
template<class C1,class C2>
void interschimbare(C1 &a, C2 &b)
{
    C1 aux;
    aux= a;
    a=b;
    b=aux;
}





template <class C1>
C1 Inmultire(C1 a, C1 b)
{

return a*b;

}


template<>
char* Inmultire(char* a, char*b){

    char* aux=new char[strlen(a)*strlen(b)+1];
    strcpy(aux,"");
    for(int i=0; i<strlen(b); i++)
        strcat(aux,a);
    return aux;
}
template<>
const char* Inmultire(const char* a, const char*b){

    char* aux=new char[strlen(a)*strlen(b)+1];
    strcpy(aux,"");
    for(int i=0; i<strlen(b); i++)
        strcat(aux,a);
    return aux;

}
template<>
string Inmultire(string a, string b){

    string aux="";
    for(int i=0; i<b.length(); i++)
        aux=aux+a;
    return aux;

}
template<class C1, class C2>
C1 Inmultire(C1 a, C2 b){

    return a*b;

}
template<>
int Inmultire(int a, char* b){

    int c=strlen(b);
    return a*c;

}
int Inmultire(int a, const char* b){

    int c=strlen(b);
    return a*c;

}
int Inmultire(int a, string b){

    int c=b.length();
    return a*c;

}




class IOInterface {
public:
    virtual istream& read(istream& in) = 0;
    virtual ostream& write(ostream& out) const = 0;
    // clasa abstracta + metoda constanta
};
class Abstract
{
public:
    virtual void Verificare() const = 0; // clasa abstracta + metoda constanta
};
class Cont: public IOInterface, public Abstract
{
protected:
    int varstaTitular;
    string titular;
    string dataInfiintare;
    string moneda;
    bool persoanaFizica;
public:
    Cont(); //Constructor fara parametrii
    Cont(int varstaTitular, string titular, string dataInfiintare,string moneda,bool persoanaFizica); //constructor cu toti parametrii
    Cont(const Cont& account); //copy-constructor
    friend istream& operator>>(istream& in, Cont& account); // supraincarcarea op >>
    friend ostream& operator<<(ostream& out, const Cont& account); //supraincarcarea op <<
    Cont& operator=(const Cont& account); //operatorul egal
    bool operator<(const Cont& Account)
    {
        if(this->titular<Account.titular)
            return true;
        return false;
    }
    Cont operator*(Cont Account)
     {
        Account.varstaTitular = Account.varstaTitular * this->varstaTitular;
        return Account;
    }
      Cont operator+(int x)
    {
        Cont aux = *this;
        aux.varstaTitular= aux.varstaTitular + x;
        return aux;
    }

    ~Cont();  //destructor

    istream& read(istream& in);
    ostream& write(ostream& out) const;

    virtual void Detalii(); //metoda virtuala + polimorfism
    void Verificare()const;

    string getmoneda(); //getter

};
Cont::Cont(): varstaTitular(0),titular("Titular anonim"), dataInfiintare("0/0/0"),moneda("Fara moneda"),persoanaFizica(0){}
Cont::Cont(int varstaTitular,string titular, string dataInfiintare,string moneda, bool persoanaFizica): varstaTitular(varstaTitular),titular(titular),dataInfiintare(dataInfiintare),moneda(moneda),persoanaFizica(persoanaFizica){}
Cont::Cont(const Cont& account): varstaTitular(account.varstaTitular),titular(account.titular),dataInfiintare(account.dataInfiintare),moneda(account.moneda),persoanaFizica(account.persoanaFizica){}
Cont::~Cont()
{
      cout << "~Cont" << endl;
}
Cont& Cont::operator=(const Cont& account)
{
    if(this!=&account)
    {
        this->varstaTitular=account.varstaTitular;
        this->titular=account.titular;
        this->dataInfiintare=account.dataInfiintare;
        this->moneda=account.moneda;
        this->persoanaFizica=account.persoanaFizica;
    }
    return *this;
}
istream& Cont::read(istream& in)
{
    cout<<"Scrieti varsta titularului: ";
    in>>this->varstaTitular;
    try{
    if(this->varstaTitular<18)
        throw(this->varstaTitular);
    }
    catch(int a)
    {
        cout<<"cititi alta varsta peste 18: ";
        int var;
        cin>>var;
        this->varstaTitular = var;
    }

    in.get();
    cout << "Scrieti numele titularului: ";
    char s[100];
    in.getline(s,100);
    this->titular=s;
    cout << "Scrieti data infiintari contului: ";
    in >> this->dataInfiintare;
    cout << "Scrieti moneda in care functioneaza contul: ";
    in >> this->moneda;
    cout << "Scrieti 1 pentru persoana fizica, 0 pentru persoana juridica: ";
    in >> this->persoanaFizica;
    return in;
}
istream& operator>>(istream& in, Cont& account)
{
    return account.read(in);
}
ostream& Cont::write(ostream& out)const
{
    out << "Varsta titularului este: ";
    out << this->varstaTitular<<endl;
    out << "Numele titularului este: ";
    out << this->titular<<endl;
    out << "Contul a fost infiintat la data de: ";
    out << this->dataInfiintare<<endl;
    out << "Moneda contului este: ";
    out << this->moneda<<endl;
    out << "Titularul este persoana fizica (1-A/0-F): ";
    out<<this->persoanaFizica<<endl;
    return out;
}
ostream& operator<<(ostream& out, const Cont& account)
{
    return account.write(out);
}
void Cont::Detalii()
{
    try
    {
        if(this->titular=="Titular anonim")
            throw(this->titular);
        else
            cout<<"Clientul se numeste "<<this->titular<<" si are "<<this->varstaTitular<<" de ani"<<endl;
    }
    catch(string nume)
    {
        cout<<"Nu se cunoaste numele titularului contului"<<endl;
    }
}
void Cont::Verificare()const
{
    try
    {
        if(dataInfiintare[0]=='0')
            throw(dataInfiintare[0]);
        else
        {

            int an=0;
            for(int i=6; i<=9; i++)
                an = an * 10 + int(dataInfiintare[i])-48;
            try
            {
                if(an>=2012)
                    throw(an);
                else
                    cout<<"Contul este mai vechi de 10 ani"<<endl;
            }
            catch(int an)
            {
                cout<<"Contul nu este mai vechi de 10 ani, ci a fost deschis in anul "<<an<<endl;
            }
        }
    }
    catch(char a)
    {
        cout<<"Obiectul doar a fost creat, nu se cunoaste anul deschiderii contului"<<endl;
    }
}
    string Cont::getmoneda()
    {
    return this -> moneda;
    }


class Banca: public IOInterface
{
protected:
    string nume;
    string tara;
    int nrSucursale;
    const int IDbanca;
    static int contorID;
    list <Cont> listaConturi;
public:
    Banca(); //Constructor fara parametrii
    Banca(string nume, string tara, int nrSucursale, list <Cont> listaConturi); //Constructor cu toti parametrii
    Banca(const Banca& bank); //Copy-constructor
    Banca& operator=(const Banca& bank); //supraincarcarea operatorului egal
    friend istream& operator>>(istream& in, Banca& bank); // supraincarcarea operatorului >>
    friend ostream& operator<<(ostream& out, const Banca bank); // supraincarcarea operatorului <<
    ~Banca(); //Destructor

    istream& read(istream& in);
    ostream& write(ostream& out)const;

    void AfisareConturiRON(); //functionalitate
};
Banca::Banca():nume("banca anonima"),tara("fara locatie"),nrSucursale(0),IDbanca(contorID++),listaConturi({}){}
Banca::Banca(string nume, string tara, int nrSucursale, list <Cont> listaConturi): nume(nume),tara(tara),nrSucursale(nrSucursale),IDbanca(IDbanca)
{
        this->listaConturi=listaConturi;
}
Banca::Banca(const Banca& bank):  nume(bank.nume),tara(bank.tara),nrSucursale(bank.nrSucursale),IDbanca(bank.IDbanca)
    {
    this->listaConturi=bank.listaConturi;
}
Banca& Banca::operator=(const Banca& bank)
{
    if(this!=&bank)
    {
        if(this->listaConturi.empty()==0)
            this->listaConturi.clear();
        this->nume=bank.nume;
        this->tara=bank.tara;
        this->nrSucursale=bank.nrSucursale;
        this->listaConturi=bank.listaConturi;
    }
    return *this;
}
Banca::~Banca()
{
    if(this->listaConturi.empty()==0)
        this->listaConturi.clear();
    cout<<"~Banca"<<endl;
}
istream& Banca::read(istream& in)
{
    if(this->listaConturi.empty()==0)
        this->listaConturi.clear();
    cout << "Scrieti numarul de sucursale ale bancii: ";
    in >> this->nrSucursale;
    in.get();
    cout << "Scrieti numele bancii: ";
    char s[100];
    in.getline(s,100);
    this->nume=s;
    cout << "Scrieti tara de origine a bancii: ";
    in >> this->tara;
    cout << "Cititi conturi: "<<endl;
    int k = 1, comanda;
    while (k == 1)
    {
        cout << "1 - Add\n";
        cout << "2 - Stop\n";
        in >> comanda;
        switch(comanda)
        {
            case 1:
            {
                Cont Account;
                in >> Account;
                this->listaConturi.push_back(Account);
                break;
            }
            case 2:
            {
                k = 0;
                break;
            }
            default:
            {
                cout << "Comanda incorecta\n";
                break;
            }
        }
    }
    return in;
}
istream& operator>>(istream& in,Banca& bank)
{
    return bank.read(in);
}
ostream& Banca::write(ostream& out)const
{
    out << "Numele bancii este: ";
    out << this->nume<<endl;
    out << "Tara de origine a bancii este: ";
    out << this->tara<<endl;
    out << "Numarul de sucursale ale bancii este: ";
    out << this->nrSucursale<<endl;
    out << "Codul unic al bancii este: ";
    out << this->IDbanca<<endl;
    out<<"Exista urmatoarele conturi:"<<endl;
    out<<endl;
    list <Cont>::iterator it;
    for(auto it = this->listaConturi.begin(); it != this->listaConturi.end(); ++it)
    {
        out << *it << endl;
    }
    return out;
}
ostream& operator<<(ostream& out,Banca bank)
{
    return bank.write(out);
}
void Banca::AfisareConturiRON()
{
     list<Cont>::iterator it;
     for(auto it = this->listaConturi.begin(); it != this->listaConturi.end(); ++it)
    {
        if((*it).getmoneda()=="RON")
            cout<<*it<<endl;
    }
}

class ContEconomii: public virtual Cont
{
protected:
    float depozitMaxim;
    int nrLuni;
    float* depoziteLunare;
public:
    ContEconomii(); //Constructor fara parametrii
    ContEconomii(int varstaTitular,string titular,string dataInfiintare,string moneda,bool persoanaFizica,float depozitMaxim,int nrLuni,float* depoziteLunare); //Constructor cu toti parametrii
    ContEconomii(const ContEconomii& accountEc); //Copy-Constructor
    ContEconomii& operator=(const ContEconomii& accountEc); //supraincarcarea operatorului egal
    friend istream& operator>>(istream& in, ContEconomii& accountEc); //supraincarcarea operatorului >>
    friend ostream& operator<<(ostream& out, const ContEconomii& accountEc); //supraincarcarea operatorului <<
    ~ContEconomii(); //destructor
    bool operator<(const ContEconomii& AccountE)
    {
        if(this->titular<AccountE.titular)
            return true;
        return false;
    }
    ContEconomii operator*(ContEconomii AccountE)
     {
        int aux;
        if(this->nrLuni>AccountE.nrLuni)
            aux=this->nrLuni;
        else
            aux=AccountE.nrLuni;
        for(int i=0; i<aux; i++)
            AccountE.depoziteLunare[i] = AccountE.depoziteLunare[i]*this->depoziteLunare[i];
        return AccountE;
    }
        ContEconomii operator*(int x)
    {
        ContEconomii aux = *this;
        for(int i=0; i<aux.nrLuni; i++)
            aux.depoziteLunare[i] = aux.depoziteLunare[i]*x;
        return aux;
    }

    istream& read(istream& in);
    ostream& write(ostream& out)const;

    void Detalii();
    void Verificare()const;

};
ContEconomii::ContEconomii()
{
  this->depozitMaxim=0;
  this->nrLuni=0;
  this->depoziteLunare=NULL;
}
ContEconomii::ContEconomii(int varstaTitular,string titular,string dataInfiintare,string moneda,bool persoanaFizica,float depozitMaxim,int nrLuni,float* depoziteLunare):Cont(varstaTitular, titular, dataInfiintare, moneda, persoanaFizica)
{
    this->depozitMaxim=depozitMaxim;
    this->nrLuni=nrLuni;
    this->depoziteLunare = new float[this->nrLuni];
    for(int i=0; i<nrLuni; i++)
        this->depoziteLunare[i]=depoziteLunare[i];
}
ContEconomii::ContEconomii(const ContEconomii& accountEc): Cont(accountEc)
{
    this->depozitMaxim=accountEc.depozitMaxim;
    this->nrLuni=accountEc.nrLuni;
    this->depoziteLunare = new float[this->nrLuni];
    for(int i=0; i<accountEc.nrLuni; i++)
        this->depoziteLunare[i]=accountEc.depoziteLunare[i];
}
ContEconomii& ContEconomii::operator=(const ContEconomii& accountEc)
{
    if(this!=&accountEc)
    {
        Cont::operator=(accountEc);
        if(this->depoziteLunare!=NULL)
            delete[] this->depoziteLunare;
        this->depozitMaxim=accountEc.depozitMaxim;
        this->nrLuni=accountEc.nrLuni;
        this->depoziteLunare = new float[this->nrLuni];
        for(int i=0; i<accountEc.nrLuni; i++)
            this->depoziteLunare[i]=accountEc.depoziteLunare[i];
    }
    return *this;
}
ContEconomii::~ContEconomii()
{
    if(this->depoziteLunare!=NULL)
        delete[] this->depoziteLunare;
    cout<<"~ContEconomii"<<endl;
}
istream& ContEconomii::read(istream& in)
{
    Cont::read(in);
    if(this->depoziteLunare!=NULL)
        delete[] this->depoziteLunare;
    cout << "Scrieti suma maxima ce poate fi depozitata: ";
    in >> this->depozitMaxim;
    cout << "Scrieti numarul de luni in care au fost adaugate sume in contul de economii: ";
    in >> this->nrLuni;
    this->depoziteLunare=new float[this->nrLuni];
    for(int i=0; i<this->nrLuni; i++)
    {
        cout << "Scrieti suma care s-a depozitat in luna "<<i+1<<": ";
        in >> this->depoziteLunare[i];
    }
    return in;
}
istream& operator>>(istream& in, ContEconomii& accountEc)
{
    return accountEc.read(in);
}
ostream& ContEconomii::write(ostream& out)const
{
    Cont::write(out);
    out << "Suma maxima ce poate fi depozitata este: ";
    out << this->depozitMaxim<<endl;
    out << "Numarul de luni in care au fost adaugate sume in contul de economii este: ";
    out << this->nrLuni<<endl;
    for(int i=0; i<this->nrLuni; i++)
    {
        out <<"In luna "<<i+1<<" s-a depozitat urmatoarea suma: ";
        out <<this->depoziteLunare[i]<<endl;
    }
    return out;
}
ostream& operator<<(ostream& out, ContEconomii& accountEc)
{
    return accountEc.write(out);
}
void ContEconomii::Detalii()
{
    try
    {
        if(this->nrLuni==0)
            throw(this->nrLuni);
        else
        {
            float suma=0;
            for(int i=0; i<this->nrLuni; i++)
                suma += this->depoziteLunare[i];
            cout<<"In total s-au depozitat "<<suma<<" de "<<this->moneda<<endl;
        }
    }
    catch(int luna)
    {
        cout<<"Nu s-a depozitat nimic in contul de economii"<<endl;
    }
}

void ContEconomii::Verificare()const
{
    try
    {
        if(depozitMaxim==0)
            throw(depozitMaxim);
        else
        {
            float suma=0;
            for(int i=0; i<this->nrLuni; i++)
                suma += this->depoziteLunare[i];
            cout<<"In contul de economii mai pot fi depozitati "<<this->depozitMaxim-suma<<" de "<<this->moneda<<endl;
        }
    }
    catch(float d)
    {
        cout<<"Obiectul a fost creat, depozitul maxim este 0"<<endl;
    }

}

class ContDebit: public virtual Cont
{
protected:
    double DepozitMaximDebit;
    int nrLuniPlati;
    float* plati;
public:
    ContDebit();//Constructor fara parametrii
    ContDebit(int varstaTitular,string titular,string dataInfiintare,string moneda,bool persoanaFizica,double DepozitMaximDebit,int nrLuniPlati,float* plati); //Constructor cu toti parametrii
    ContDebit(const ContDebit& AccountD); //Copy-Constructor
    ContDebit& operator=(const ContDebit& AccountD); //Supraincarcarea operatorului =
    friend istream& operator>>(istream& in, ContDebit& AccountD); //supraincarcarea operatorului >>
    friend ostream& operator<<(ostream& out, const ContDebit* AccountD); //supraincarcarea operatorului <<
    ~ContDebit(); //Destructor
    bool operator<(const ContDebit& AccountD)
    {
        if(this->titular<AccountD.titular)
            return true;
        return false;
    }
    ContDebit operator*(ContDebit AccountD)
     {
        int aux;
        if(this->nrLuniPlati>AccountD.nrLuniPlati)
            aux=this->nrLuniPlati;
        else
            aux=AccountD.nrLuniPlati;
        for(int i=0; i<aux; i++)
            AccountD.plati[i] = AccountD.plati[i]*this->plati[i];
        return AccountD;
    }
    ContDebit operator*(int x)
    {
        ContDebit aux = *this;
        for(int i=0; i<aux.nrLuniPlati; i++)
            aux.plati[i] = aux.plati[i]*x;
        return aux;
    }

    istream& read(istream& in);
    ostream& write(ostream& out)const;

    void Detalii();
    void Verificare()const;

};
ContDebit::ContDebit():Cont()
{
    this->DepozitMaximDebit =0;
    this->nrLuniPlati=0;
    this->plati=NULL;
}
ContDebit::ContDebit(int varstaTitular,string titular,string dataInfiintare,string moneda,bool persoanaFizica,double DepozitMaximDebit,int nrLuniPlati,float* plati):Cont(varstaTitular, titular, dataInfiintare, moneda, persoanaFizica)
{
    this->DepozitMaximDebit=DepozitMaximDebit;
    this->nrLuniPlati=nrLuniPlati;
    this->plati = new float[nrLuniPlati];
    for(int i=0; i<nrLuniPlati; i++)
        this->plati[i]=plati[i];
}
ContDebit::ContDebit(const ContDebit& AccountD):Cont(AccountD)
{
    this->DepozitMaximDebit=AccountD.DepozitMaximDebit;
    this->nrLuniPlati=AccountD.nrLuniPlati;
    this->plati = new float[nrLuniPlati];
    for(int i=0; i<this->nrLuniPlati; i++)
        this->plati[i]=AccountD.plati[i];
}
ContDebit& ContDebit::operator=(const ContDebit& AccountD)
{
    if(this!=&AccountD)
    {
        Cont::operator=(AccountD);
        if(this->plati!=NULL)
            delete[] this->plati;
        this->DepozitMaximDebit=AccountD.DepozitMaximDebit;
        this->nrLuniPlati=AccountD.nrLuniPlati;
        this->plati = new float[this->nrLuniPlati];
        for(int i=0; i<this->nrLuniPlati; i++)
            this->plati[i]=AccountD.plati[i];
    }
    return* this;
}
ContDebit::~ContDebit()
{
    if(this->plati!=NULL)
        delete[] this->plati;
    cout<<"~ContDebit"<<endl;
}
istream& ContDebit::read(istream& in)
{
    if(this->plati!=NULL)
        delete[] this->plati;
    Cont::read(in);
    cout << "Scrieti suma maxima ce poate fi depozitata in contul de Debit: ";
    in >> this->DepozitMaximDebit;
    cout << "Scrieti numarul de luni in care au fost cheltuite sume din contul de debit: ";
    in >> this->nrLuniPlati;
    this->plati=new float[this->nrLuniPlati];
    for(int i=0; i<this->nrLuniPlati; i++)
    {
        cout << "Scrieti suma care s-a cheltuit in luna "<<i+1<<": ";
        in >> this->plati[i];
    }
    return in;
}
istream& operator>>(istream& in, ContDebit& AccountD)
{
    return AccountD.read(in);
}
ostream& ContDebit::write(ostream& out)const
{
    Cont::write(out);
    out << "Suma maxima ce poate fi depozitata in contul de debit este: ";
    out << this->DepozitMaximDebit<<endl;
    out << "Numarul de luni in care au fost cheltuite sume din contul de debit este: ";
    out << this->nrLuniPlati<<endl;
    for(int i=0; i<this->nrLuniPlati; i++)
    {
        out <<"In luna "<<i+1<<" s-a cheltuit urmatoarea suma: ";
        out <<this->plati[i]<<endl;
    }
    return out;
}
ostream& operator>>(ostream& out, ContDebit& AccountD)
{
    return AccountD.write(out);
}
void ContDebit::Detalii()
{
    float suma=0;
    for(int i=0; i<this->nrLuniPlati; i++)
        suma += this->plati[i];
    cout<<"In total s-au cheltuit din contul de debit "<<suma<<" de "<<this->moneda<<endl;
}
void ContDebit::Verificare()const
{
    try
    {
        if(this->nrLuniPlati==0)
            throw(false);
        int ok=1;
        for(int i=0; i<this->nrLuniPlati; i++)
            if(this->plati[i]==0)
                throw(false);
        cout<<"Contul a inregistrat debitari in fiecare luna"<<endl;
    }
    catch(bool raspuns)
    {
        cout<<"Contul fie nu a inregistrat debitari in fiecare luna, fie deloc"<<endl;
    }
}


class ContMixt: public virtual ContEconomii,
                public virtual ContDebit
{
protected:
    int nrLuniTranzactii;
    float* TranzactiiEconomiiDebit;
    float* TranzactiiDebitEconomii;
public:
    ContMixt(); //Constructor fara parametrii
    ContMixt(int varstaTitular,string titular,string dataInfiintare,string moneda,bool persoanaFizica,double DepozitMaximDebit,int nrLuniPlati,float* plati,float depozitMaxim,int nrLuni,float* depoziteLunare,int nrLuniTranzactii, float* TranzactiiEconomiiDebit, float* TranzactiiDebitEconomii); //Constructor cu toti parametrii
    ContMixt(const ContMixt& AccountM); //Copy-Constructor
    ContMixt& operator=(const ContMixt& AccountM); //Supraincarcarea operatorului =
    friend istream& operator>>(istream& in, ContMixt& AccountM); //Supraincarcarea operatorului >>
    friend ostream& operator<<(ostream& out, const ContMixt& AccountM); //Supraincarcarea operatorului <<
    ~ContMixt(); //Destructor
    bool operator<(const ContMixt& AccountM)
    {
        if(this->titular<AccountM.titular)
            return true;
        return false;
    }
    ContMixt operator*(ContMixt AccountM)
     {
        int aux;
        if(this->nrLuniTranzactii>AccountM.nrLuniTranzactii)
            aux=this->nrLuniTranzactii;
        else
            aux=AccountM.nrLuniTranzactii;
        for(int i=0; i<aux; i++)
            AccountM.TranzactiiDebitEconomii[i] = AccountM.TranzactiiDebitEconomii[i]*this->TranzactiiDebitEconomii[i];
        return AccountM;
    }
        ContMixt operator*(int x)
    {
        ContMixt aux = *this;
        for(int i=0; i<aux.nrLuniTranzactii; i++)
            aux.TranzactiiDebitEconomii[i] = aux.TranzactiiDebitEconomii[i]*x;
        return aux;
    }

    istream& read(istream& in);
    ostream& write(ostream& out)const;

    void Detalii();
    void Verificare()const;

};
ContMixt::ContMixt():Cont(),ContEconomii(),ContDebit()
{
    this->nrLuniTranzactii=0;
    this->TranzactiiEconomiiDebit=NULL;
    this->TranzactiiDebitEconomii=NULL;
}
ContMixt::ContMixt(int varstaTitular,string titular,string dataInfiintare,string moneda,bool persoanaFizica,double DepozitMaximDebit,int nrLuniPlati,float* plati,float depozitMaxim,int nrLuni,float* depoziteLunare,int nrLuniTranzactii, float* TranzactiiEconomiiDebit, float* TranzactiiDebitEconomii): Cont(varstaTitular, titular, dataInfiintare, moneda, persoanaFizica),ContEconomii(varstaTitular, titular, dataInfiintare, moneda, persoanaFizica, depozitMaxim,nrLuni,depoziteLunare),ContDebit(varstaTitular, titular, dataInfiintare, moneda, persoanaFizica, DepozitMaximDebit,nrLuniPlati,plati)
{
    this->nrLuniTranzactii=nrLuniTranzactii;
    this->TranzactiiEconomiiDebit = new float[this->nrLuniTranzactii];
    for(int i=0; i<nrLuniTranzactii; i++)
        this->TranzactiiEconomiiDebit[i]=TranzactiiEconomiiDebit[i];
    this->TranzactiiDebitEconomii= new float[this->nrLuniTranzactii];
    for(int i=0; i<nrLuniTranzactii; i++)
        this->TranzactiiDebitEconomii[i]=TranzactiiDebitEconomii[i];
}
ContMixt::ContMixt(const ContMixt& AccountM): Cont(AccountM),ContEconomii(AccountM),ContDebit(AccountM)
{
    this->nrLuniTranzactii=AccountM.nrLuniTranzactii;
    this->TranzactiiEconomiiDebit=new float[this->nrLuniTranzactii];
    for(int i=0; i<this->nrLuniTranzactii; i++)
        this->TranzactiiEconomiiDebit[i]=AccountM.TranzactiiEconomiiDebit[i];
    this->TranzactiiDebitEconomii=new float[this->nrLuniTranzactii];
    for(int i=0; i<this->nrLuniTranzactii; i++)
        this->TranzactiiDebitEconomii[i]=AccountM.TranzactiiDebitEconomii[i];
}
ContMixt& ContMixt::operator=(const ContMixt& AccountM)
{
    if(this!=&AccountM)
    {
        Cont::operator=(AccountM);
        ContEconomii::operator=(AccountM);
        ContDebit::operator=(AccountM);
        if(this->TranzactiiEconomiiDebit!=NULL)
            delete[] this->TranzactiiEconomiiDebit;
        if(this->TranzactiiDebitEconomii!=NULL)
            delete[] this->TranzactiiDebitEconomii;
        this->nrLuniTranzactii=AccountM.nrLuniTranzactii;
        this->TranzactiiEconomiiDebit=new float[this->nrLuniTranzactii];
        for(int i=0; i<this->nrLuniTranzactii; i++)
            this->TranzactiiEconomiiDebit[i]=AccountM.TranzactiiEconomiiDebit[i];
        this->TranzactiiDebitEconomii=new float[this->nrLuniTranzactii];
        for(int i=0; i<this->nrLuniTranzactii; i++)
            this->TranzactiiDebitEconomii[i]=AccountM.TranzactiiDebitEconomii[i];
    }
    return *this;
}
ContMixt::~ContMixt()
{
    if(this->TranzactiiEconomiiDebit!=NULL)
        delete[] this->TranzactiiEconomiiDebit;
    if(this->TranzactiiDebitEconomii!=NULL)
        delete[] this->TranzactiiDebitEconomii;
    cout<<"~ContMixt"<<endl;
}
istream& ContMixt::read(istream& in)
{
    ContEconomii::read(in);
    if(this->TranzactiiEconomiiDebit!=NULL)
        delete[] this->TranzactiiEconomiiDebit;
    if(this->TranzactiiDebitEconomii!=NULL)
        delete[] this->TranzactiiDebitEconomii;
     cout << "Scrieti suma maxima ce poate fi depozitata in contul de Debit: ";
    in >> this->DepozitMaximDebit;
    cout << "Scrieti numarul de luni in care au fost cheltuite sume din contul de debit: ";
    in >> this->nrLuniPlati;
    this->plati=new float[this->nrLuniPlati];
    for(int i=0; i<this->nrLuniPlati; i++)
    {
        cout << "Scrieti suma care s-a cheltuit in luna "<<i+1<<": ";
        in >> this->plati[i];
    }
    cout << "Scrieti numarul de luni in care au fost efectuate tranzactii intre cele 2 depozite: ";
    in >> this->nrLuniTranzactii;
    this->TranzactiiEconomiiDebit=new float[this->nrLuniTranzactii];
    for(int i=0; i<this->nrLuniTranzactii; i++)
    {
        cout << "Scrieti suma care s-a transferat in luna "<<i+1<<" din contul de Economii in cel de Debit: ";
        in >> this->TranzactiiEconomiiDebit[i];
    }
    this->TranzactiiDebitEconomii=new float[this->nrLuniTranzactii];
    for(int i=0; i<this->nrLuniTranzactii; i++)
    {
        cout << "Scrieti suma care s-a transferat in luna "<<i+1<<" din contul de Debit in cel de Economii: ";
        in >> this->TranzactiiDebitEconomii[i];
    }
    return in;
}
istream& operator>>(istream& in, ContMixt& AccountM)
{
    return AccountM.read(in);
}
ostream& ContMixt::write(ostream& out)const
{
    ContEconomii::write(out);
    out << "Suma maxima ce poate fi depozitata in contul de debit este: ";
    out << this->DepozitMaximDebit<<endl;
    out << "Numarul de luni in care au fost cheltuite sume din contul de debit este: ";
    out << this->nrLuniPlati<<endl;
    for(int i=0; i<this->nrLuniPlati; i++)
    {
        out <<"In luna "<<i+1<<" s-a cheltuit urmatoarea suma: ";
        out <<this->plati[i]<<endl;
    }
    out << "Numarul de luni in care au fost efectuate tranzactii intre cele 2 depozite este: ";
    out << this->nrLuniTranzactii<<endl;
    for(int i=0; i<this->nrLuniTranzactii; i++)
    {
        out <<"In luna "<<i+1<<" s-a transferat din contul de Economii in cel de Debit urmatoarea suma: ";
        out <<this->TranzactiiEconomiiDebit[i]<<endl;
    }
    for(int i=0; i<this->nrLuniTranzactii; i++)
    {
        out <<"In luna "<<i+1<<" s-a transferat din contul de Debit in cel de Economii urmatoarea suma: ";
        out <<this->TranzactiiDebitEconomii[i]<<endl;
    }
    return out;
}
ostream& operator<<(ostream& out, ContMixt& AccountM)
{
    return AccountM.write(out);
}

void ContMixt::Detalii()
{
    set<float, greater<float> > sumaMaxima;
    for(int i=0; i<this->nrLuniTranzactii; i++)
        sumaMaxima.insert(this->TranzactiiEconomiiDebit[i]);
    set<float,greater<float>>::iterator itr;
    itr = sumaMaxima.begin();
    cout<<"Suma maxima transferata din contul de Economii in cel de Debit "<<*itr<<" de "<<this->moneda<<endl;
}
void ContMixt::Verificare()const
{
    float suma1=0,suma2=0;
    for(int i=0; i<this->nrLuniTranzactii; i++)
    {
        suma1 += this->TranzactiiEconomiiDebit[i];
        suma2 += this->TranzactiiDebitEconomii[i];
    }

    cout<<"Bilantul transferuruilor intre cele 2 depozite este "<<abs(suma2-suma1)<<endl;
}
int Banca::contorID=1;

class MeniuInteractiv{
private:
    static MeniuInteractiv *obiect;
    int index;

    MeniuInteractiv()
    {
        index=0;
    }
public:
    static MeniuInteractiv* getInstance()
    {
        if(!obiect)
            obiect=new MeniuInteractiv();
        return obiect;
    }
    int getindex(){return this->index;}
    void setindex(int a) {this->index=a;}
    void meniu()
    {
        vector <Cont*> listaConturi;
        map <int,Banca> listaBanci;
        int indexBanca = 1;
        int i=1;
        int k=1;
        while(k==1)
    {
        cout<<" 1 Pentru Diamantul de clase";
        cout<<"\n 2 Pentru Clasa Banca";
        cout<<"\n 3 Functionalitati";
        cout<<"\n 4 Stop"<<endl;
        int comanda;
        cin>>comanda;
        switch(comanda)
        {
            case 1:
            {
                system("CLS");
                int l=1;
                while(l!=0)
                {
                    cout<<" 1 Pentru a adauga un cont de debit";
                    cout<<"\n 2 Pentru a adauga un cont de economii";
                    cout<<"\n 3 Pentru a adauga un cont mixt";
                    cout<<"\n 4 Pentru a afisa lista de conturi bancare";
                    cout<<"\n 5 Pentru a sterge conturile din lista";
                    cout<<"\n 6 Pentru Upcasting";
                    cout<<"\n 7 Pentru Downcasting";
                    cout<<"\n 8 Pentru a ne intoarce\n";
                    int comanda2;
                    cin>>comanda2;
                    switch(comanda2)
                    {
                   case 1:
                    {
                        Cont* ContD =new ContDebit();
                        cin>>*ContD;
                        listaConturi.push_back(ContD);
                        break;
                    }
                    case 2:
                    {
                        Cont* ContE = new ContEconomii();
                        cin>>*ContE;
                        listaConturi.push_back(ContE);
                        break;
                    }
                    case 3:
                    {
                        Cont* ContM = new ContMixt();
                        cin>>*ContM;
                        listaConturi.push_back(ContM);
                        break;
                    }
                    case 4:
                    {
                        for(int i=0; i<listaConturi.size(); i++)
                        cout<<*listaConturi[i]<<endl;
                        break;
                    }
                    case 5:
                    {
                        while (!listaConturi.empty())
                        listaConturi.pop_back();
                        break;
                    }
                    case 6:
                    {
                        ContEconomii AccountE;
                        ContDebit AccountD;
                        ContMixt AccountM;
                        Cont* *lista_upcasting = new Cont*[3];
                        lista_upcasting[0]=&AccountE;
                        lista_upcasting[1]=&AccountD;
                        lista_upcasting[2]=&AccountM;
                        for(int i=0; i<3; i++)
                        {
                            lista_upcasting[i]->Detalii();
                        }
                        break;
                    }
                    case 7:
                        {
                            ContEconomii* AccountE;
                            ContDebit* AccountD;
                            ContMixt* AccountM;
                            Cont* Account1 = new ContEconomii;
                            Cont* Account2 = new ContDebit;
                            Cont* Account3 = new ContMixt;
                            AccountE=dynamic_cast<ContEconomii*> (Account1);
                            AccountD=dynamic_cast<ContDebit*> (Account2);
                            AccountM=dynamic_cast<ContMixt*> (Account3);
                            AccountE->Detalii();
                            AccountD->Detalii();
                            AccountM->Detalii();
                            break;
                        }
                    case 8:
                    {
                        l=0;
                        break;
                    }
                    }
               }
               break;
            }
            case 2:
            {
                system("CLS");
                int m=1;
                while(m!=0)
                {
                    cout<<" 1 Pentru a adauga o banca in lista";
                    cout<<"\n 2 Pentru a exemplifica functionalitatea clasei banca";
                    cout<<"\n 3 Pentru afisarea listei de banci";
                    cout<<"\n 4 Pentru a sterge bancile din lista";
                    cout<<"\n 5 Pentru a ne intoarce inapoi \n";
                    int comanda3;
                    cin>>comanda3;
                    switch(comanda3)
                    {
                        case 1:
                        {
                            Banca bank;
                            cin>>bank;
                            listaBanci.insert(pair<int, Banca>(indexBanca++, bank));
                            break;
                        }
                        case 2:
                        {
                            map<int, Banca>::iterator it;
                            for (it = listaBanci.begin(); it != listaBanci.end(); it++)
                            {
                                cout<<"La banca "<<it->first<<" avem urmatoarele conturi deschise in RON:"<<endl;
                                (it->second).AfisareConturiRON();
                                cout<<endl;
                            }
                            break;
                        }
                        case 3:
                        {
                            map<int, Banca>::iterator it;
                            for (it = listaBanci.begin(); it != listaBanci.end(); it++)
                            {
                                cout << it->second;
                            }

                        }
                        case 4:
                        {
                            auto it1 = listaBanci.find(1);
                            auto it2 = listaBanci.find(listaBanci.size());
                            listaBanci.erase(it1, it2);
                        }
                        case 5:
                        {

                           m=0;
                           break;
                        }
                    }
                }
                system("CLS");
                break;
            }

            case 3:
            {
                system("CLS");
                int p=1;
                while(p!=0)
                {
                    cout<<" 1 Pentru clasa template";
                    cout<<"\n 2 Pentru a exemplifica o exceptie";
                    cout<<"\n 3 Pentru functia template Interschimbare";
                    cout<<"\n 4 Pentru functia template Inmultire";
                    cout<<"\n 5 Pentru a ne intoarce \n";
                    int comanda4;
                    cin>>comanda4;
                    switch(comanda4)
                    {
                        case 1:
                        {
                            Cont c1,c2;
                            cin>>c1>>c2;
                            Comparare <Cont> a(c1,c2);
                            a.Compare();
                            break;
                        }
                        case 2:
                        {
                            cout<<"daca cititi o varsta mai mica de 18 ani, programul arunca o exceptie"<<endl;
                            Cont account;
                            cin>>account;
                            cout<<account;
                            break;
                        }
                        case 3:
                        {
                             system("CLS");
                            int r=1;
                            while(r!=0)
                            {
                                cout<<" 1 Pentru a interschimba 2 char*";
                                cout<<"\n 2 Pentru a interschimba 2 Conturi";
                                cout<<"\n 3 Pentru a interschimba 2 Conturi de Debit";
                                cout<<"\n 4 Pentru a interschimba 2 stringuri";
                                cout<<"\n 5 Pentru a ne intoarce \n";
                                int comanda5;
                                cin>>comanda5;
                                switch(comanda5)
                                {
                                    case 1:
                                    {
                                        char *a,*b;
                                        a=new char[strlen("ana")+1];
                                        strcpy(a,"ana");
                                        cout<<"a="<<a<<endl;
                                        b=new char[strlen("mere")+1];
                                        strcpy(b,"mere");
                                        cout<<"b="<<b<<endl;
                                        interschimbare(a,b);
                                        cout<<"Dupa interschimbare a="<<a<<" b="<<b<<endl;
                                        break;
                                    }
                                    case 2:
                                    {
                                        Cont a,b;
                                        cin>>a;
                                        cin>>b;
                                        interschimbare(a,b);
                                        cout<<a<<endl;
                                        cout<<b<<endl;
                                        break;
                                    }
                                    case 3:
                                    {
                                        ContDebit a,b;
                                        cin>>a;
                                        cin>>b;
                                        interschimbare(a,b);
                                        cout<<a<<endl;
                                        cout<<b<<endl;
                                        break;
                                    }
                                    case 4:
                                    {
                                        string a,b;
                                        cout<<"a=";
                                        cin>>a;
                                        cout<<"b=";
                                        cin>>b;
                                        interschimbare(a,b);
                                        cout<<"Dupa interschimbare a="<<a<<" b="<<b<<endl;
                                        break;
                                    }
                                    case 5:
                                    {
                                        r=0;
                                        break;
                                    }
                                }
                            }
                            system("CLS");
                            break;
                        }

                        case 4:
                        {

                            system("CLS");
                            int t=1;
                            while(t!=0)
                            {
                                cout<<" 1 Pentru inmutlire dintre 2 inturi";
                                cout<<"\n 2 Pentru inmutlire dintre 2 stringuri";
                                cout<<"\n 3 Pentru inmutlire dintre 2 const charuri";
                                cout<<"\n 4 Pentru inmutlire dintre 1 string si 1 int";
                                cout<<"\n 5 Pentru inmutlire dintre 2 conturi";
                                cout<<"\n 6 Pentru a ne intoarce"<<endl;
                                int comanda6;
                                cin>>comanda6;
                                switch(comanda6)
                                {
                                    case 1:
                                    {
                                        int a,b;
                                        cout<<"a=";
                                        cin>>a;
                                        cout<<"b=";
                                        cin>>b;
                                        cout<<Inmultire(a,b)<<endl;
                                        break;
                                    }
                                    case 2:
                                    {
                                        string a = "ana";
                                        string b = "pere";
                                        cout<<"a="<<a<<endl;
                                        cout<<"b="<<b<<endl;
                                        cout<<Inmultire(a,b)<<endl;
                                        break;
                                    }
                                    case 3:
                                    {

                                        cout<<Inmultire("ana","tata")<<endl;
                                        break;

                                    }
                                    case 4:
                                    {
                                        int a;
                                        string b;
                                        cout<<"a(int)=";
                                        cin>>a;
                                        cout<<"b(string)=";
                                        cin>>b;
                                        cout<<Inmultire(a,b)<<endl;
                                        break;
                                    }
                                    case 5:
                                    {
                                        Cont a;
                                        Cont b;
                                        cin>>a;
                                        cin>>b;
                                        cout<<Inmultire(a,b)<<endl;
                                    }
                                    case 6:
                                    {
                                        t=0;
                                        break;
                                    }

                                }
                            }
                            system("CLS");
                            break;


                        }
                        case 5:
                        {
                            p=0;
                            break;
                        }

                    }

            }
            system("CLS");
            break;

        }
        case 4:
        {
            k=0;
            break;
        }
    }
    }
    }
};
MeniuInteractiv* MeniuInteractiv::obiect=0;
int main()
{

    MeniuInteractiv *meniulMeu=meniulMeu->getInstance();
    meniulMeu->setindex(1);
    meniulMeu->meniu();
    return 0;
}
