#include <iostream>
#include <string.h>
#include<vector>
#include <list>
using namespace std;
class autor
{
private:
    char  *nume,*prenume;
    const int IDautor;
    static int contorID3;
    bool inviata;
    int nrexemplare;

public:
    autor();//constructor fara parametrii
    autor(char* nume, char *prenume);//constructor cu parametrii
	autor(char* nume, char *prenume, bool inviata); //constructor cu parametrii
	autor(char* nume, char *prenume, bool inviata, int nrexemplare); //constructor cu toti parametrii
    autor(const autor& aut); //copy-constuctor
	autor& operator=(const autor& aut); //supraincarcarea op =
    ~autor(); //destrcutor

    //getters
    char* getnume();
    char* getprenume();
    bool getinviata();
    int getnrexemplare();
    const int getIDautor();
    static int getcontorID3();

    //setters
    void setnume(char* nume);
    void setprenume(char* prenume);
    void setinviata(bool inviata);
    void setnrexemplare(int nrexemplare);


    void citire();//citire obiect
    void afisare();//afisare obiect
    friend istream& operator>>(istream& in, autor &aut);//supraincarcarea op >>
    friend ostream& operator<<(ostream& out, const autor& aut); //supraincarcarea op <<

    autor operator--(); //postdecrementare
    autor operator--(int); //predecrementare
    autor operator+=(int x); //supraincarcarea op +=
    autor operator+(int x); //supraincarcarea op +
    autor operator+(autor a); //supraincarcarea op +(adunarea intre obiecte din aceeasi clasa)
    friend autor operator+(int x, autor a) //supraincarcarea op +
    {
        a.nrexemplare = a.nrexemplare + x;
        return a;
    }
    autor operator*=(int x); //supraincarcarea op *=
    autor operator*(int x); //supraincarcarea op *
    autor operator*(autor a); //supraincarcarea op * (inmultirea intre obiecte din aceeasi clasa)
    friend autor operator*(int x, autor a) //supraincarcarea op *
    {
        a.nrexemplare = a.nrexemplare * x;
        return a;
    }
    bool operator==(const autor& a); //supraincarcarea op ==
    bool operator>=(const autor& a); //supraincarcarea op >=
    explicit operator int() //supraincarcarea op cast
    {
        return (int)this->nrexemplare;
    }
    char operator[](int index) //supraincarcarea op []
     {
    if (0 <= index && index < strlen(this->nume))
        return this->nume[index];
    cout << "Index introdus gresit";
    }
    void contemporan() //functionaliate - verificare daca autorl este contemporan
    {
        if(this->inviata==1)
            cout<<"Autorul este contemporan"<<endl;
        else
            cout<<"Autorul nu este contemporan"<<endl;
    }
    void numecomplet() //functionaliate - afisarea numelui complet al autorului
    {
        cout<<"Numele complet al autorului este "<<this->nume<<" "<<this->prenume<<endl;
    }

};
class carte
{
private:
    const int IDcarte;
    static int contorID;
    int nrpag;
    char* titlu;
    autor aut;
    char *gen;
    float garantie;
    int exemplare;
    double rating;

public:
    carte(); //constructor fara parametrii
    carte(autor aut, char* titlu); //constructor cu parametrii
    carte(autor aut, char* titlu, int nrpag); //constructor cu parametrii
    carte(autor aut, char* titlu, char *gen, int nrpag, float garantie, int exemplare, double rating); //constructor cu toti parametrii
    carte(const carte& book); //copy-constructor
    carte& operator=(const carte& book); //supraincarcarea op =
    ~carte(); //destructor

    //setters
    char* gettitlu();
    char* getgen();
    int getnrpag();
    float getgarantie();
    int getexemplare();
    double getrating();
    const int getIDcarte();
    static int getcontorID();

    //getters
    void settitlu(char* titlu);
    void setgen(char* gen);
    void setgarantie(float garantie);
    void setexemplare(int exemplare);
    void setnrpag(int nrpag);
    void setrating(double rating);

    void citire();//functie citire
    void afisare();//functie afisare
    friend istream& operator>>(istream& in, carte &book); //supraincararea operatorului >>
    friend ostream& operator<<(ostream&, const carte& book); //supraincararea operatorului <<

    carte operator++(); //
    carte operator++(int);
    carte operator+=(int x); //supraincararea operatorului +=
    carte operator+(int x); //supraincararea operatorului +
    carte operator+(carte a); //supraincararea operatorului + (intre obiecte ale aceleiasi clase)
    friend carte operator+(int x, carte a) //supraincararea operatorului + comutativitate
    {
        a.exemplare = a.exemplare + x;
        return a;
    }
    carte operator/=(int x); //supraincararea operatorului /=
    carte operator/(int x); //supraincararea operatorului /
    carte operator/(carte a); //supraincararea operatorului / (intre obiecte ale aceleiasi clase)
    friend carte operator/(int x, carte a) //supraincararea operatorului / comutativitate
        {
        a.exemplare = a.exemplare / x;
        return a;
    }
    bool operator==(const carte& a); //supraincararea operatorului ==
    bool operator<=(const carte& a); //supraincararea operatorului <=
    explicit operator int() //supraincararea operatorului cast
    {
        return (int)this->garantie;
    }
    char operator[](int index) //supraincararea operatorului []
     {
    if (0 <= index && index < strlen(this->gen))
        return this->gen[index];
    cout << "Index introdus gresit";
    }
    void aventura() //functionalitate - verificare daca cartea este de aventura
    {
        if(this->gen=="aventura")
            cout<<"Cartea este de aventura"<<endl;
        else
            cout<<"Cartea nu este de aventura"<<endl;
    }
    void cartiLungi() //functionalitate - verificare daca cartea este mai lunga de 500 de pagini
    {
        if(this->nrpag>=500)
            cout<<"Cartea are cel putin 500 de pagini"<<endl;
        else
            cout<<"Cartea are mai putin de 500 de pagini"<<endl;
    }
};
class client
{
private:
    char *nume,*prenume;
    int varsta;
    char gen;

	int luni1;
	int *imprumuturi;

	int luni2;
	float *datorii;

    const int IDclient;
    static int contorID1;

public:
    client(); //construcot fara parametrii
    client(char *nume, char *prenume, int varsta, char gen, int luni1, int *imprumuturi, int luni2, float *datorii); //construcot cu toti parametrii
    client(char *nume, char *prenume, int luni1, int *imprumuturi); //construcot cu parametrii
    client(char *nume, char *prenume, int varsta); //construcot cu parametrii
    client(const client& cl); //copy-constructor
    client& operator=(const client& cl); //supraincarcarea operatorului =
    ~client(); //destructor

    //getters
    char* getnume();
    char* getprenume();
    int getvarsta();
    char getgen();
    int getluni1();
    int* getimprumuturi();
    int getluni2();
    float* getdatorii();
    const int getIDclient();
    static int getcontorID1();

    //setters
    void setnume(char* nume);
    void setprenume(char* prenume);
    void setvarsta(int varsta);
    void setgen(char gen);
    void setluni1(int luni1);
    void setimprumuturi( int* impr, int n);
    void setluni2(int luni2);
    void setdaorii( float* datorii, int n);

    void citire(); //functie de citire obiect
    void afisare(); //functie de afisare obiect

    friend istream& operator>>(istream& in, client& cl); //supraincarcarea operatorului >>
    friend ostream& operator<<(ostream& out, const client& cl); //supraincarcarea operatorului <<


	client operator++(); //postincrementare
    client operator++(int); //preincremenatre
    client operator+=(float x); //supraincarcarea operatorului +=
    client operator+(float x); //supraincarcarea operatorului +
    client operator+(client a); //supraincarcarea operatorului + (adunare intre obiectele clasei)
    friend client operator+(float x, client a) //supraincarcarea operatorului + comutativitate
     {
         for(int i=0; i<a.luni2; i++)
            a.datorii[i] = a.datorii[i] + x;
        return a;
    }
    client operator-=(float x); //supraincarcarea operatorului -=
    client operator-(float x); //supraincarcarea operatorului -
    client operator-(client a); //supraincarcarea operatorului - (intre obiectele aceleiasi clase)
    friend client operator-(float x, client a) //supraincarcarea operatorului - comutativitate
     {
         for(int i=0; i<a.luni2; i++)
            a.datorii[i] = a.datorii[i] - x;
        return a;
    }
    bool operator==(const client& a); //supraincarcarea operatorului ==
    bool operator>=(const client& a); //supraincarcarea operatorului >=
    explicit operator int() //supraincarcarea operatorului cast
    {
        for(int i=0; i<this->luni2; i++)
            return (int)this->datorii[i];
    }
    float operator[](int index); //supraincarcarea operatorului []
    float sumadatorii() //functionalitate - suma totala a datoriilor unui client
    {
        float s=0;
        for(int i=0; i<this->luni2; i++)
            s+=datorii[i];
        return s;
    }
    bool peste50() //functionalitate - verificare daca clientul are peste 50 de ani
    {
        if(this->varsta>=50)
            return true;
        return false;
    }

};
class imprumut
{
private:
    static int contorID2;
    const int IDimprumut;
    bool returnat;
    client persoana;
	int nrcarti;
    int ziLuat,lunaLuat,anLuat;
    int ziScadent,lunaScadent,anScadent;
    carte* listaCarti;

public:
    imprumut(); //constructor
    imprumut(client persoana, bool returnat,  int ziLuat, int lunaLuat, int anLuat, int ziScadent, int lunaScadent, int anScadent, int nrcarti,carte* listaCarti); //constructor cu toti parametrii
	imprumut(int ziLuat, int lunaLuat, int anLuat, int ziScadent, int lunaScadent, int anScadent); //constructor cu parametrii
	imprumut(client persoana, bool returnat); //constructor cu parametrii
    imprumut(const imprumut& imp); //copy-constructor
    ~imprumut(); //destructor
    imprumut& operator=(const imprumut& imp); //supraincarcarea operatorului =

    //getters
    bool getreturnat();
    int getziScadent();
    int getlunaScadent();
    int getanScadent();
    int getziLuat();
    int getlunaLuat();
    int getanLuat();
    int getnrcarti();
    const int getIDimprumut();
    static int getcontorID2();

    //setters
    void setziLuat(int ziLuat);
    void setlunaLuat(int lunaLuat);
    void setanLuat(int anLuat);
    void setziScadent(int ziScadent);
    void setlunaScadent(int lunaScadent);
    void setanScadent(int anScadent);
    void setnrcarti(int nrcarti);
    void setreturnat(bool returnat);

    void citire();//functie citire obiect
    void afisare();//functie afisare obiect
    friend istream& operator>>(istream& in, imprumut& imp); //supraincarcarea operatorului >>
    friend ostream& operator<<(ostream& out, const imprumut& imp); //supraincarcarea operatorului <<

    imprumut operator++(); //postincrementare
    imprumut operator++(int); //preincrementare
    imprumut operator+=(int x); //supraincarcarea operatorului +=
    imprumut operator+(int x); //supraincarcarea operatorului +
    imprumut operator+(imprumut a); //supraincarcarea operatorului + (intre obiecte ale aceleiasi clase)
    friend imprumut operator+(int x, imprumut a) //supraincarcarea operatorului + comutativitate
    {
        a.nrcarti = a.nrcarti + x;
        return a;
    }
    imprumut operator*=(int x); //supraincarcarea operatorului *=
    imprumut operator*(int x); //supraincarcarea operatorului *
    imprumut operator*(imprumut a); //supraincarcarea operatorului * (intre obiecte ale aceleiasi clase)
    friend imprumut operator*(int x, imprumut a) //supraincarcarea operatorului * comutativitate
        {
        a.nrcarti = a.nrcarti * x;
        return a;
    }
    bool operator==(const imprumut& a); //supraincarcarea operatorului ==
	bool operator>=(const imprumut& a); //supraincarcarea operatorului >=
    explicit operator int() //supraincarcarea operatorului cast
    {
        return (int)this->nrcarti;
    }
    carte operator[](int index) //supraincarcarea operatorului []
    {
        if (0 <= index && index < this->nrcarti)
        return this->listaCarti[index];
    cout << "Index introdus gresit";
    }
    carte LungimeMaxima() //functionalitate - afisare cea mai lunga carte a unui imprumut
    {
        carte maxi = listaCarti[0];
        for(int i=1; i<this->nrcarti; i++)
            if(listaCarti[i].getnrpag()>maxi.getnrpag())
                maxi = listaCarti[i];
        return maxi;
    }
    bool imprumutMare() //functionalitate - verificare daca imprumutul este unul mare
    {
        if(this->nrcarti>10)
            return true;
        return false;
    }

    friend imprumut operator+=(imprumut m, const carte& a) //adunare intre obiecte ale clasei imprumut si clasei carte
    {
        carte* aux;
        aux = new carte[m.nrcarti];
        for(int i=0; i<m.nrcarti; i++)
            aux[i]=m.listaCarti[i];
        if(m.listaCarti != NULL)
            delete[] m.listaCarti;
        m.nrcarti++;
        m.listaCarti = new carte[m.nrcarti];
        for(int i=0; i<m.nrcarti-1; i++)
            m.listaCarti[i]=aux[i];
        m.listaCarti[m.nrcarti-1] = a;
        if(aux!=NULL)
            delete[] aux;
        return m;
    }
        friend imprumut operator+(const carte& a, imprumut m) //adunare intre obiecte ale clasei imprumut si clasei carte + comutativitate
    {
        carte* aux;
        aux = new carte[m.nrcarti];
        for(int i=0; i<m.nrcarti; i++)
            aux[i]=m.listaCarti[i];
        if(m.listaCarti != NULL)
            delete[] m.listaCarti;
        m.nrcarti++;
        m.listaCarti = new carte[m.nrcarti];
        for(int i=0; i<m.nrcarti-1; i++)
            m.listaCarti[i]=aux[i];
        m.listaCarti[m.nrcarti-1] = a;
        if(aux!=NULL)
            delete[] aux;
        return m;
    }

};
    autor::autor():IDautor(contorID3++)
    {
        this->nume=new char[strlen("nume anonim")+1]; //alocare memorie in mod dinamic
        strcpy(this->nume,"nume anonim");
        this->prenume=new char[strlen("prenume anonim")+1];
        strcpy(this->prenume,"prenume anonim");

        this->inviata=0;
        this->nrexemplare=0;
    }
    autor::autor(char* nume, char *prenume):IDautor(contorID3++)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=new char[strlen(prenume)+1];
        strcpy(this->prenume,prenume);

        this->inviata=0;
        this->nrexemplare=0;

    }
    autor::autor(char* nume, char *prenume, bool inviata):IDautor(contorID3++)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=new char[strlen(prenume)+1];
        strcpy(this->prenume,prenume);

        this->inviata=inviata;
        this->nrexemplare=0;

    }
    autor::autor(char* nume, char *prenume, bool inviata, int nrexemplare):IDautor(contorID3++)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=new char[strlen(prenume)+1];
        strcpy(this->prenume,prenume);

        this->inviata=inviata;
        this->nrexemplare=nrexemplare;

    }
    autor::autor(const autor& aut):IDautor(aut.IDautor)
    {
        this->nume=new char[strlen(aut.nume)+1];
        strcpy(this->nume,aut.nume);
        this->prenume=new char[strlen(aut.prenume)+1];
        strcpy(this->prenume,aut.prenume);

        this->inviata=aut.inviata;
        this->nrexemplare=aut.nrexemplare;

    }
    autor& autor::operator=(const autor& aut)
	{
	    if(this!=&aut)
        {
            if(this->nume!=NULL) //dezalocare memorie alocata dinamic
                delete[] this->nume;

            if(this->prenume!=NULL)
                delete[] this->prenume;

            this->nume=new char[strlen(aut.nume)+1];
            strcpy(this->nume,aut.nume);

            this->prenume=new char[strlen(aut.prenume)+1];
            strcpy(this->prenume,aut.prenume);

            this->inviata=aut.inviata;
            this->nrexemplare=aut.nrexemplare;
        }
        return *this;

	}
    autor::~autor()
    {
        if(this->nume!=NULL)
            delete [] this->nume;
        if(this->prenume!=NULL)
            delete [] this->prenume;
    }
    char* autor::getnume()
    {
        return this -> nume;
    }
    char* autor::getprenume()
    {
    return this -> prenume;
    }
    bool autor::getinviata()
    {
    return this -> inviata;
    }
    int autor::getnrexemplare()
    {
    return this -> nrexemplare;
    }
    const int autor::getIDautor()
    {
        return this -> IDautor;
    }
    int autor::getcontorID3()
    {
        return contorID3;
    }
    void autor::setnume(char* nume)
    {
        if(this->nume!=NULL)
            delete[] this->nume;
        this->nume = new char[strlen(nume)+1];
        strcpy(this->nume,nume);
    }
    void autor::setprenume(char* prenume)
    {
        if(this->prenume!=NULL)
            delete[] this->prenume;
        this->prenume = new char[strlen(prenume)+1];
        strcpy(this->prenume,prenume);
    }
    void autor::setinviata(bool inviata)
    {
        this->inviata=inviata;
    }
    void autor::setnrexemplare(int nrexemplare)
    {
        this->nrexemplare=nrexemplare;
    }
    void autor::citire()
    {
        cout<<"Numele este ";
        char s[101],t[101];
        cin>>s;
        if(this->nume!=NULL)
            delete [] this->nume;
        this->nume=new char[strlen(s)+1];
        strcpy(this->nume,s);

        cout<<"Prenumele este: ";
        cin>>t;
        if(this->prenume!=NULL)
            delete [] this->prenume;
        this->prenume=new char[strlen(t)+1];
        strcpy(this->prenume,t);

        cout<<"Este in viata: ";
        cin>>this->inviata;
        cout<<"Numarul de carti ale autorului in biblioteca: ";
        cin>>this->nrexemplare;
    }

    void autor::afisare()
    {
        cout<<"Numele este: ";
        cout<<this->nume<<endl;
        cout<<"Prenumele este: ";
        cout<<this->prenume<<endl;
        cout<<"Este in viata: ";
        cout<<this->inviata<<endl;
        cout<<"Numarul de carti ale autorului in biblioteca: ";
        cout<<this->nrexemplare<<endl;
        cout<<"ID-ul unic al autorului este: ";
        cout<<this->IDautor<<endl;
    }
    istream& operator>>(istream& in, autor &aut)
    {
        cout<<"Numele este ";
        char s[101],t[101];
        cin>>s;
        if(aut.nume!=NULL)
            delete [] aut.nume;
        aut.nume=new char[strlen(s)+1];
        strcpy(aut.nume,s);

        cout<<"Preumele este ";
        cin>>t;
        if(aut.prenume!=NULL)
            delete [] aut.prenume;
        aut.prenume=new char[strlen(t)+1];
        strcpy(aut.prenume,t);

        cout<<"Este autorul contemporan? ";
        cin>>aut.inviata;
        cout<<"Numarul de carti ale autorului in biblioteca: ";
        cin>>aut.nrexemplare;
        return in;
    }
    ostream& operator<<(ostream& out, const autor& aut)
    {
        out<<"Numele este: ";
        out<<aut.nume<<endl;
        out<<"Prenumele este: ";
        out<<aut.prenume<<endl;
        out<<"Este in viata: ";
        out<<aut.inviata<<endl;
        out<<"Numarul de carti ale autorului in biblioteca: ";
        out<<aut.nrexemplare<<endl;
        out<<"ID-ul unic al autorului este: ";
        out<<aut.IDautor<<endl;
        return out;
    }
    autor autor::operator--()
    {
        this->nrexemplare--;
        return *this;
    }
    autor autor::operator--(int)
    {
        autor aux = *this;
        this->nrexemplare--;
        return aux;
    }
    autor autor::operator+=(int x)
    {
        this->nrexemplare += x;
        return *this;
    }
    autor autor::operator+(int x)
    {
        autor aux = *this;
        aux.nrexemplare = aux.nrexemplare + x;
        return aux;
    }
    autor autor::operator+(autor a)
     {
        a.nrexemplare = a.nrexemplare + this->nrexemplare;
        return a;
    }
        autor autor::operator*=(int x)
    {
        this->nrexemplare *= x;
        return *this;
    }
        autor autor::operator*(int x)
    {
        autor aux = *this;
        aux.nrexemplare = aux.nrexemplare * x;
        return aux;
    }
    autor autor::operator*(autor a)
     {
        a.nrexemplare = a.nrexemplare * this->nrexemplare;
        return a;
    }

    bool autor::operator==(const autor& a)
    {
        if (this->nrexemplare == a.nrexemplare)
            return true;
        return false;
    }
    bool autor::operator>=(const autor& a)
    {
        if (this->nrexemplare >= a.nrexemplare)
            return true;
        return false;
    }


    carte::carte():IDcarte(contorID++)
    {
        this->aut;

        this->titlu=new char[strlen("carte noua")+1];
        strcpy(this->titlu,"carte noua");

        this->gen= new char[strlen("fara gen")+1];
        strcpy(this->gen,"fara gen");

        this->nrpag=0;
        this->garantie=0;
        this->exemplare=0;
        this->rating=0;

    }
    carte::carte(autor aut, char* titlu):IDcarte(contorID++)
    {
        this->aut=aut;

        this->titlu=new char[strlen(titlu)+1];
        strcpy(this->titlu,titlu);

        this->gen= new char[strlen("fara gen")+1];
        strcpy(this->gen,"fara gen");

        this->nrpag=0;
        this->garantie=0;
        this->exemplare=0;
        this->rating=0;

    }
    carte::carte(autor aut, char* titlu, int nrpag):IDcarte(contorID++)
    {
        this->aut=aut;

        this->titlu=new char[strlen(titlu)+1];
        strcpy(this->titlu,titlu);

        this->gen= new char[strlen("fara gen")+1];
        strcpy(this->gen,"fara gen");

        this->nrpag=nrpag;
        this->garantie=0;
        this->exemplare=0;
        this->rating=0;
    }
    carte::carte(autor aut, char* titlu, char *gen, int nrpag, float garantie, int exemplare, double rating):IDcarte(contorID++)
    {
        this->aut=aut;

        this->titlu=new char[strlen(titlu)+1];
        strcpy(this->titlu,titlu);

        this->gen= new char[strlen(gen)+1];
        strcpy(this->gen,gen);

        this->nrpag=nrpag;
        this->garantie=garantie;
        this->exemplare=exemplare;
        this->rating=rating;

    }
    carte::carte(const carte& book):IDcarte(book.IDcarte)
    {
        this->aut=book.aut;

        this->titlu=new char[strlen(book.titlu)+1];
        strcpy(this->titlu,book.titlu);

        this->gen=new char[strlen(book.gen)+1];
        strcpy(this->gen,book.gen);

        this->nrpag=book.nrpag;
        this->garantie=book.garantie;
        this->exemplare=book.exemplare;
        this->rating=book.rating;
    }
    carte& carte::operator=(const carte& book)
    {
        if(this!=&book)
        {

            if(this->titlu!=NULL)
                delete[] this->titlu;

            if(this->gen!=NULL)
                delete[] this->gen;

            this->aut=book.aut;

            this->titlu=new char[strlen(book.titlu)+1];
            strcpy(this->titlu,book.titlu);

            this->gen=new char[strlen(book.gen)+1];
            strcpy(this->gen,book.gen);

            this->nrpag=book.nrpag;
            this->garantie=book.garantie;
            this->exemplare=book.exemplare;
            this->rating=book.rating;
        }
        return *this;
    }
    carte::~carte()
    {

        if(this->titlu!=NULL)
            delete [] this->titlu;

        if(this->gen!=NULL)
            delete[] this->gen;
    }
    char* carte::gettitlu()
    {
        return this -> titlu;
    }
    char* carte::getgen()
    {
        return this -> gen;
    }
    int carte::getnrpag()
    {
        return this -> nrpag;
    }
    float carte::getgarantie()
    {
        return this -> garantie;
    }
    int carte::getexemplare()
    {
        return this -> exemplare;
    }
    double carte::getrating()
    {
        return this->rating;
    }
    const int carte::getIDcarte()
    {
        return this->IDcarte;
    }
    int carte::getcontorID()
    {
        return contorID;
    }

    void carte::settitlu(char* titlu)
    {
        if(this->titlu!=NULL)
            delete[] this->titlu;
        this->titlu = new char[strlen(titlu)+1];
        strcpy(this->titlu,titlu);
    }
    void carte::setgen(char* gen)
    {
        if(this->gen!=NULL)
            delete[] this->gen;
        this->gen= new char[strlen(gen)+1];
        strcpy(this->gen,gen);
    }
    void carte::setgarantie(float garantie)
    {
        this->garantie=garantie;
    }
    void carte::setexemplare(int exemplare)
    {
        this->exemplare=exemplare;
    }
        void carte::setnrpag(int nrpag)
    {
        this->nrpag=nrpag;
    }
    void carte::setrating(double rating)
    {
        this->rating=rating;
    }
    void carte::citire()
    {
        cout<<"Autorul este:"<<endl;
        char s[101],t[101],g[101];
        cin>>aut;
        cin.get();

        cout<<"Titlul este: ";
        cin.getline(t,101);
        if(this->titlu!=NULL)
            delete [] this->titlu;
        this->titlu=new char[strlen(t)+1];
        strcpy(titlu,t);

        cout<<"Genul cartii este: ";
        cin.getline(s,101);
        if(this->gen!=NULL)
            delete [] this->gen;
        this->gen=new char[strlen(g)+1];
        strcpy(gen,g);
        cout<<"Numarul de pagini este: ";
        cin>>this->nrpag;
        cout<<"garantia in caz de accidente este: ";
        cin>>this->garantie;
        cout<<"Numarul de exemplare este: ";
        cin>>this->exemplare;
        cout<<"Cartea are urmatoarea nota din 10 maxim: ";
        cin>>this->rating;
    }
    void carte::afisare()
    {

        cout<<"Autorul are urmatoarele date:"<<endl;
        cout<<this->aut<<endl;
        cout<<"Titlul cartii este: "<<this->titlu<<endl;
        cout<<"Genul cartii este: "<<this->gen<<endl;
        cout<<"Cartea are "<<this->nrpag<<" de pagini."<<endl;
        cout<<"In caz de accident se plateste: "<<this->garantie<<" de lei."<<endl;
        cout<<"Cartea se gaseste in "<<this->exemplare<<" exemplare."<<endl;
        cout<<"Cartea are nota "<<this->rating<<" /10"<<endl;
        cout<<"Cartea are ID-ul unic: "<<this->IDcarte<<endl;
    }
    istream& operator>>(istream& in, carte &book)
    {
		cout<<"Autorul este:";
        char s[101],t[101],g[101];
        in>>book.aut;
        in.get();
        cout<<"Titlul este: ";
        in.getline(t,101);
        if(book.titlu!=NULL)
            delete [] book.titlu;
        book.titlu=new char[strlen(t)+1];
        strcpy(book.titlu,t);

        cout<<"Genul este: ";
        in.getline(g,101);
        if(book.gen!=NULL)
            delete [] book.gen;
        book.gen=new char[strlen(g)+1];
        strcpy(book.gen,g);
        cout<<"Numarul de pagini este: ";
        in>>book.nrpag;
        cout<<"garantia in caz de accidente este: ";
        in>>book.garantie;
        cout<<"Numarul de exemplare este: ";
        in>>book.exemplare;
        cout<<"Cartea are urmatoarea nota din 10 maxim: ";
        in>>book.rating;
        return in;
    }
    ostream& operator<<(ostream& out, const carte& book)
    {
        out<<"Autorul are urmatoarele date:"<<endl;
        out<<book.aut<<endl;
        out<<"Titlul cartii este: "<<book.titlu<<endl;
        out<<"Genul cartii este: "<<book.gen<<endl;
        out<<"Cartea are "<<book.nrpag<<" de pagini."<<endl;
        out<<"In caz de accident se plateste: "<<book.garantie<<" de lei."<<endl;
        out<<"Cartea se gaseste in "<<book.exemplare<<" exemplare."<<endl;
        out<<"Cartea are nota "<<book.rating<<" /10"<<endl;
        out<<"Cartea are ID-ul unic: "<<book.IDcarte<<endl;
        return out;
    }
    carte carte::operator++()
    {
        this->exemplare++;
        return *this;
    }
    carte carte::operator++(int)
    {
        carte aux = *this;
        this->exemplare++;
        return aux;
    }
     carte carte::operator+=(int x)
    {
        this->exemplare += x;
        return *this;
    }
    carte carte::operator+(int x)
     {
        carte aux = *this;
        aux.exemplare = aux.exemplare + x;
        return aux;
    }
        carte carte::operator+(carte a)
     {
        a.exemplare = a.exemplare + this->exemplare;
        return a;
    }
    carte carte::operator/=(int x)
    {
        this->exemplare /= x;
        return *this;
    }
    carte carte::operator/(int x)
    {
        carte aux = *this;
        aux.exemplare = aux.exemplare / x;
        return aux;
    }
          carte carte::operator/(carte a)
     {
        a.exemplare = a.exemplare / this->exemplare;
        return a;
    }
    bool carte::operator==(const carte& a)
    {
        if (this->exemplare == a.exemplare)
            return true;
        return false;
    }
    bool carte::operator<=(const carte& a)
     {
        if (this->exemplare <= a.exemplare)
            return true;
        return false;
    }



int carte::contorID=1000;
int autor::contorID3=1000;


int client::contorID1=1000;
client::client():IDclient(contorID1++)
    {
        this->nume=new char[strlen("nume anonim")+1];
        strcpy(this->nume,"nume anonim");
        this->prenume=new char[strlen("prenume anonim")+1];
        strcpy(this->prenume,"prenume anonim");
        this->varsta=0;
        this->gen='/';
        this->luni1=0;
        this->imprumuturi=NULL;
        this->luni2=0;
        this->datorii=NULL;
    }
client::client(char *nume, char *prenume, int varsta, char gen, int luni1, int *imprumuturi, int luni2, float *datorii):IDclient(contorID1++)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=new char[strlen(prenume)+1];
        strcpy(this->prenume,prenume);
        this->varsta=varsta;
        this->gen=gen;
        this->luni1=luni1;
        this->imprumuturi=new int[this->luni1];
        for(int i=0; i<this->luni1; i++)
            this->imprumuturi[i]=imprumuturi[i];
        this->luni2=luni2;
        this->datorii=new float[this->luni2];
            for(int i=0; i<this->luni2; i++)
		this->datorii[i]=datorii[i];
    }
    client::client(char *nume, char *prenume, int luni1, int *imprumuturi):IDclient(contorID1++)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=new char[strlen(prenume)+1];
        strcpy(this->prenume,prenume);
        this->varsta=0;
        this->gen='/';

        this->luni1=luni1;
        this->imprumuturi=new int[this->luni1];
        for(int i=0; i<this->luni1; i++)
		this->imprumuturi[i]=imprumuturi[i];

        this->luni2=0;
        this->datorii=NULL;
    }
    client::client(char *nume, char *prenume, int varsta):IDclient(contorID1++)
    {
        this->nume=new char[strlen(nume)+1];
        strcpy(this->nume,nume);
        this->prenume=new char[strlen(prenume)+1];
        strcpy(this->prenume,prenume);
        this->varsta=varsta;
        this->gen='/';
        this->luni1=0;
        this->imprumuturi=NULL;
        this->luni2=0;
        this->datorii=NULL;
    }
    client::client(const client& cl):IDclient(cl.contorID1)
    {
        this->nume=new char[strlen(cl.nume)+1];
        strcpy(this->nume,cl.nume);
        this->prenume=new char[strlen(cl.prenume)+1];
        strcpy(this->prenume,cl.prenume);
        this->varsta=cl.varsta;
        this->gen=cl.gen;
        this->luni1=cl.luni1;
        this->imprumuturi=new int[this->luni1];
        for(int i=0; i<this->luni1; i++)
		this->imprumuturi[i]=cl.imprumuturi[i];
        this->luni2=cl.luni2;
        this->datorii=new float[this->luni2];
        for(int i=0; i<this->luni2; i++)
		this->datorii[i]=cl.datorii[i];
    }
    client& client::operator=(const client& cl)
    {
    if(this!=&cl)
	{
        if(this->nume!=NULL)
            delete[] this->nume;

        if(this->prenume!=NULL)
            delete[] this->prenume;

        if(this->imprumuturi!=NULL)
            delete[] this->imprumuturi;

        if(this->datorii!=NULL)
            delete[] this->datorii;

        this->nume=new char[strlen(cl.nume)+1];
        strcpy(this->nume,cl.nume);

        this->prenume=new char[strlen(cl.prenume)+1];
        strcpy(this->prenume,cl.prenume);

        this->gen=cl.gen;
        this->varsta=cl.varsta;
        this->luni1=cl.luni1;
        this->luni2=cl.luni2;

        this->imprumuturi=new int[cl.luni1];
        for(int i=0; i<cl.luni1; i++)
            this->imprumuturi[i]=cl.imprumuturi[i];

        this->datorii=new float[cl.luni2];
        for(int i=0; i<cl.luni2; i++)
            this->datorii[i]=cl.datorii[i];
	}
	return *this;
    }
    client::~client()
    {
        if(this->nume!=NULL)
            delete [] this->nume;
        if(this->prenume!=NULL)
            delete [] this->prenume;
        if(this->imprumuturi!=NULL)
        	delete[] this->imprumuturi;
        if(this->datorii!=NULL)
        	delete[] this->datorii;
    }
    char* client::getnume()
{
 return this -> nume;
}
char* client::getprenume()
{
 return this -> prenume;
}
int client::getvarsta()
{
 return this -> varsta;
}
char client::getgen()
{
 return this -> gen;
}
int client::getluni1()
{
 return this -> luni1;
}
int* client::getimprumuturi()
{
  return this-> imprumuturi;
}
int client::getluni2()
{
 return this -> luni2;
}
float* client::getdatorii()
{
  return this-> datorii;
}
const int client::getIDclient()
{
return this->IDclient;
}
int client::getcontorID1()
{
    return contorID1;
}

void client::setnume(char* nume)
{
if(this->nume!=NULL)
	delete[] this->nume;
this->nume = new char[strlen(nume)+1];
strcpy(this->nume,nume);
}
void client::setprenume(char* prenume)
{
if(this->prenume!=NULL)
	delete[] this->prenume;
this->prenume = new char[strlen(prenume)+1];
strcpy(this->prenume,prenume);
}
void client::setvarsta(int varsta)
{
this->varsta=varsta;
}
void client::setgen(char gen)
{
this->gen=gen;
}
void client::setluni1(int luni1)
{
this->luni1=luni1;
}

void client::setimprumuturi( int* impr, int n)
{
    this->luni1=n;
    if(this->imprumuturi!=NULL)
        delete[] imprumuturi;
    this->imprumuturi=new int[n];
    for(int i=0; i<n; i++)
        this->imprumuturi[i]=impr[i];

}
void client::setluni2(int luni2)
{
this->luni2=luni2;
}
void client::setdaorii( float* datorii, int n)
{
    this->luni2=n;
    if(this->datorii!=NULL)
        delete[] datorii;
    this->datorii=new float[n];
    for(int i=0; i<n; i++)
        this->datorii[i]=datorii[i];

}
 void client::citire()
{
	cout<<"Numele clientului este"<<endl;
    char s[101];
    cin>>s;
    if(this->nume!=NULL)
        delete [] this->nume;
    this->nume=new char[strlen(s)+1];
    strcpy(this->nume,s);

    cout<<"Prenumele este: ";
	char t[101];
    cin>>t;
    if(this->prenume!=NULL)
        delete [] this->prenume;
    this->prenume=new char[strlen(t)+1];
    strcpy(this->prenume,t);
    cout<<"Varsta clientului este: ";
    cin>>this->varsta;
    cout<<"Genul clientului este(M/F): ";
    cin>>this->gen;
    cout<<"Numarul de luni pentru imprumuturi: ";
    cin>>this->luni1;

	if(this->imprumuturi!=NULL)
        	delete []this->imprumuturi;

   	this->imprumuturi=new int[this->luni1];
    for(int i=0; i<this->luni1; i++)
    {
        cout<<"In luna "<<i+1<<" ati imprumutat numarul de carti: ";
        cin>>this->imprumuturi[i];
    }

    cout<<"Numarul de luni pentru datorii: ";
	 cin>>this->luni2;

	if(this->datorii!=NULL)
        	delete []this->datorii;

   	this->datorii=new float[this->luni2];
    	for(int i=0; i<this->luni2; i++)
    	{
        	cout<<"In luna "<<i+1<<" datorati urmatoarea suma: ";
        	cin>>this->datorii[i];
    	}
}
void client::afisare()
{
	cout<<"Numele clientului este: "<<this->nume<<endl;
	cout<<"Prenumele clientului este: "<<this->prenume<<endl;
	cout<<"Varsta clientului este:"<<this->varsta<<endl;
	cout<<"Genul clientului este:"<<this->gen<<endl;
	cout<<"Numarul de luni pentru imprumuturi este: "<<this->luni1<<endl;
	for(int i=0; i<this->luni1; i++)
    {
        cout<<"In luna "<<i+1<<" ati imprumutat: ";
        cout<<this->imprumuturi[i];
        cout<<" carti"<<endl;
    }
	cout<<"Numarul de luni pentru datorii este: "<<this->luni2<<endl;
	for(int i=0; i<this->luni2; i++)
    {
        cout<<"In luna "<<i+1<<" datorati: ";
        cout<<this->datorii[i];
        cout<<" de lei"<<endl;
    }
    cout<<"Cleintul are ID-ul unic: "<<this->IDclient<<endl;
}
istream& operator>>(istream& in, client& cl)
{
    cout<<"Numele clientului este: ";
    char s[101];
    in>>s;
    if(cl.nume!=NULL)
        delete [] cl.nume;
    cl.nume=new char[strlen(s)+1];
    strcpy(cl.nume,s);

    cout<<"Prenumele clientului este: ";
	char t[101];
    in>>t;
    if(cl.prenume!=NULL)
        delete [] cl.prenume;
    cl.prenume=new char[strlen(t)+1];
    strcpy(cl.prenume,t);
    cout<<"Varsta clientului este: ";

    in>>cl.varsta;
    cout<<"Genul clientului este(M/F): ";
    in>>cl.gen;
    cout<<"Numarul de luni pentru imprumuturi: ";
    in>>cl.luni1;
	    if(cl.imprumuturi!=NULL)
        delete []cl.imprumuturi;

   cl.imprumuturi=new int[cl.luni1];
    for(int i=0; i<cl.luni1; i++)
    {
        cout<<"In luna "<<i+1<<" ati imprumutat numarul de carti: ";
        in>>cl.imprumuturi[i];
    }
    cout<<"Numarul de luni pentru datorii: ";
	    in>>cl.luni2;
	    if(cl.datorii!=NULL)
        delete []cl.datorii;

   cl.datorii=new float[cl.luni2];
    for(int i=0; i<cl.luni2; i++)
    {
        cout<<"In luna "<<i+1<<" datorati urmatoarea suma: ";
        in>>cl.datorii[i];
    }
    return in;
}

    bool client::operator==(const client& a)
    {
        if (this->nume == a.nume)
            return true;
        return false;
    }

ostream& operator<<(ostream& out, const client& cl)
{
    out<<"Numele clientului este ";
	out<<cl.nume<<endl;
    out<<"Prenumele clientului este ";
	out<<cl.prenume<<endl;
    out<<"Clientul are "<<cl.varsta<<" de ani"<<endl;
    out<<"Genul clientului este ";
	out<<cl.gen<<endl;
	out<<"Numarul de luni pentru imprumutri: ";
	out<<cl.luni1<<endl;
	for(int i=0; i<cl.luni1; i++)
    {
        out<<"In luna "<<i+1<<" ati imprumutat ";
        out<<cl.imprumuturi[i]<<" carti";
        out<<endl;
    }
    out<<"Numarul de luni pentru datorii: ";
	out<<cl.luni2<<endl;
	for(int i=0; i<cl.luni2; i++)
    {
        out<<"In luna "<<i+1<<" datorati bibliotecii ";
        out<<cl.datorii[i]<<" lei";
        out<<endl;
    }
    out<<"Cleintul are ID-ul unic: "<<cl.IDclient<<endl;
    return out;
}
	client client::operator++()
	{
        for(int i=0; i<this->luni1; i++)
		this->imprumuturi[i]++;
        return *this;
    	}
    client client::operator++(int)
	{
        client aux = *this;
        for(int i=0; i<this->luni1; i++)
		this->imprumuturi[i]++;
        return aux;
    }
    client client::operator+=(float x)
    {
        for(int i=0; i<this->luni1; i++)
        this->imprumuturi[i] += x;
        return *this;
    }
    client client::operator+(float x)
    {
        client aux = *this;
        for(int i=0; i<this->luni2; i++)
            aux.datorii[i]=aux.datorii[i]+x;
        return aux;
    }
    client client::operator+(client a)
	{
	for(int i=0; i<this->luni2; i++)
        	a.datorii[i]= a.datorii[i] + this->datorii[i];
        return a;
    }
    client client::operator-=(float x)
    {
        for(int i=0; i<this->luni1; i++)
        this->imprumuturi[i] -= x;
        return *this;
    }
        client client::operator-(float x)
    {
        client aux = *this;
        for(int i=0; i<this->luni2; i++)
            aux.datorii[i]=aux.datorii[i]-x;
        return aux;
    }
    client client::operator-(client a)
	{
	for(int i=0; i<this->luni2; i++)
        	a.datorii[i]= a.datorii[i] - this->datorii[i];
        return a;
    }
    bool client::operator>=(const client& a)
    {
        if (this->luni1 >= a.luni1)
            return true;
        return false;
    }
    float client::operator[](int index)
     {
    if (0 <= index && index < this->luni2)
        return this->datorii[index];
    cout << "Index introdus gresit";
    }



imprumut::imprumut():IDimprumut(contorID2++)
    {
        this->persoana;

        this->returnat=0;
        this->ziScadent=0;
        this->lunaScadent=0;
        this->anScadent=0;
        this->ziLuat=0;
        this->lunaLuat=0;
        this->anLuat=0;
        this->nrcarti=0;
        this->listaCarti=NULL;
    }
    imprumut::imprumut(client persoana, bool returnat,  int ziLuat, int lunaLuat, int anLuat, int ziScadent, int lunaScadent, int anScadent, int nrcarti, carte* listaCarti):IDimprumut(contorID2++)
    {
        this->persoana=persoana;

        this->returnat=0;
        this->ziScadent=ziScadent;
        this->lunaScadent=lunaScadent;
        this->anScadent=anScadent;
        this->ziLuat=ziLuat;
        this->lunaLuat=lunaLuat;
        this->anLuat=anLuat;
        this->nrcarti=nrcarti;

        this->listaCarti=new carte[this->nrcarti];
        for(int i=0; i<this->nrcarti; i++)
            this->listaCarti[i]=listaCarti[i];


    }
    imprumut::imprumut(int ziLuat, int lunaLuat, int anLuat, int ziScadent, int lunaScadent, int anScadent):IDimprumut(contorID2++)
    {
        this->persoana;

        this->returnat=0;
        this->ziScadent=ziScadent;
        this->lunaScadent=lunaScadent;
        this->anScadent=anScadent;
        this->ziLuat=ziLuat;
        this->lunaLuat=lunaLuat;
        this->anLuat=anLuat;
        this->nrcarti=0;
        this->listaCarti=NULL;

    }
    imprumut::imprumut(client persoana, bool returnat):IDimprumut(contorID2++)
    {
        this->persoana=persoana;

        this->returnat=returnat;
        this->ziScadent=0;
        this->lunaScadent=0;
        this->anScadent=0;
        this->ziLuat=0;
        this->lunaLuat=0;
        this->anLuat=0;
        this->nrcarti=0;
        this->listaCarti=NULL;

    }
    imprumut::imprumut(const imprumut& imp):IDimprumut(imp.IDimprumut)
    {
        this->persoana=imp.persoana;

        this->returnat=imp.returnat;
        this->ziScadent=imp.ziScadent;
        this->lunaScadent=imp.lunaScadent;
        this->anScadent=imp.anScadent;
        this->ziLuat=imp.ziLuat;
        this->lunaLuat=imp.lunaLuat;
        this->anLuat=imp.anLuat;
        this->nrcarti=imp.nrcarti;

        this->listaCarti=new carte[this->nrcarti];
        for(int i=0; i<this->nrcarti; i++)
        this->listaCarti[i]=imp.listaCarti[i];
    }
    imprumut& imprumut::operator=(const imprumut& imp)
{
        if (this != &imp)
         {

        this->persoana=imp.persoana;
        this->returnat=imp.returnat;
        this->ziScadent=imp.ziScadent;
        this->lunaScadent=imp.lunaScadent;
        this->anScadent=imp.anScadent;
        this->ziLuat=imp.ziLuat;
        this->lunaLuat=imp.lunaLuat;
        this->anLuat=imp.anLuat;
        this->nrcarti=imp.nrcarti;

		if(listaCarti!=NULL)
            delete[] listaCarti;
            this->listaCarti=new carte[this->nrcarti];
            for(int i=0; i<this->nrcarti; i++)
		this->listaCarti[i]=imp.listaCarti[i];
        }
        return *this;
    }
        imprumut::~imprumut()
    {
        if(listaCarti!=NULL)
            delete[] listaCarti;
    }

bool imprumut::getreturnat()
{
 return this -> returnat;
}
int imprumut::getziScadent()
{
 return this -> ziScadent;
}
int imprumut::getlunaScadent()
{
 return this -> lunaScadent;
}
int imprumut::getanScadent()
{
 return this -> anScadent;
}
int imprumut::getziLuat()
{
 return this -> ziLuat;
}
int imprumut::getlunaLuat()
{
 return this -> lunaLuat;
}
int imprumut::getanLuat()
{
 return this -> anLuat;
}
int imprumut::getnrcarti()
{
 return this -> nrcarti;
}
const int imprumut::getIDimprumut()
{
    return this -> IDimprumut;
}
int imprumut::getcontorID2()
{
    return contorID2;
}

void imprumut::setreturnat(bool returnat)
{
    this->returnat=returnat;
}
void imprumut::setziLuat(int ziLuat)
{
this->ziLuat=ziLuat;
}
void imprumut::setlunaLuat(int lunaLuat)
{
this->lunaLuat=lunaLuat;
}
void imprumut::setanLuat(int anLuat)
{
this->anLuat=anLuat;
}
void imprumut::setziScadent(int ziScadent)
{
this->ziScadent=ziScadent;
}
void imprumut::setlunaScadent(int lunaScadent)
{
this->lunaScadent=lunaScadent;
}
void imprumut::setanScadent(int anScadent)
{
this->anScadent=anScadent;
}
void imprumut::setnrcarti(int nrcarti)
{
this->nrcarti=nrcarti;
}

void imprumut::citire()
{
        cout<<"Clientul are urmatoarele date:"<<endl;
        cin>>this->persoana;
        cout<<"Cartile au fost returntate(1/0): ";
        cin>>this->returnat;
        cout<<"Cartile au fost imprumutate in ziua: ";
        cin>>this->ziScadent;
        cout<<"Cartile au fost imprumutate in luna: ";
        cin>>this->lunaScadent;
        cout<<"Cartile au fost imprumutate in anul: ";
        cin>>this->anScadent;
        cout<<"Cartile trebuie returnate pana in ziua: ";
        cin>>this->ziLuat;
        cout<<"Cartile trebuie returnate pana in luna: ";
        cin>>this->lunaLuat;
        cout<<"Cartile trebuie returnate pana in anul: ";
        cin>>this->anLuat;
        cout<<"Numarul de carti imprumutate este: ";
        cin>>this->nrcarti;
    if(this->listaCarti!=NULL)
        	delete []this->listaCarti;

   	this->listaCarti=new carte[this->nrcarti];
    for(int i=0; i<this->nrcarti; i++)
    {
        cout<<"Pentru cartea "<<i+1<<" avem datele urmatoare:"<<endl;
        cin>>this->listaCarti[i];
    }
}
void imprumut::afisare()
{
        cout<<"Clientul are urmatoarele date: "<<endl;
        cout<<this->persoana<<endl;
        cout<<"Cartile au fost returnate "<<this->returnat<<endl;
        cout<<"Cartile au fost imprumutate pe date de "<<this->ziLuat<<"/"<<this->lunaLuat<<"/"<<this->anLuat<<endl;
        cout<<"Cartile trebuie returnate pana pe date de "<<this->ziScadent<<"/"<<this->lunaScadent<<"/"<<this->anScadent<<endl;
        cout<<"A imprumutat "<<this->nrcarti<<" carti."<<endl;
        for(int i=0; i<this->nrcarti; i++)
    {
        cout<<"Pentru cartea "<<i+1<<" avem urmatoarele date:"<<endl;
        cout<<this->listaCarti[i];
        cout<<endl;
    }
        cout<<"Imprumutul are ID-ul unic "<<this->IDimprumut<<endl;


}
istream& operator>>(istream& in, imprumut& imp)
{
    cout<<"Clientul are urmatoarele date:"<<endl;
    in>>imp.persoana;
    cout<<"Cartile au fost returntate(1/0): ";
	in>>imp.returnat;
	cout<<"Cartile au fost imprumutate in ziua: ";
    in>>imp.ziLuat;
    cout<<"Cartile au fost imprumutate in luna: ";
    in>>imp.lunaLuat;
    cout<<"Cartile au fost imprumutate in anul: ";
    in>>imp.anLuat;
    cout<<"Cartile trebuie returnate pana in ziua: ";
    in>>imp.ziScadent;
    cout<<"Cartile trebuie returnate pana in luna: ";
    in>>imp.lunaScadent;
    cout<<"Cartile trebuie returnate pana in anul: ";
    in>>imp.anScadent;
    cout<<"Numarul de carti imprumutate este: ";
	in>>imp.nrcarti;

    imp.listaCarti=new carte[imp.nrcarti];
    for(int i=0; i<imp.nrcarti; i++)
    {
        cout<<"Pentru cartea "<<i+1<<" avem urmatoarele date:"<<endl;
        in>>imp.listaCarti[i];
    }
}
ostream& operator<<(ostream& out, const imprumut& imp)
{
    out<<"Clientul are urmatoarele date: "<<endl;
	out<<imp.persoana<<endl;
	out<<"Cartile au fost returnate "<<imp.returnat<<endl;

    out<<"Cartile au fost imprumutate pe date de "<<imp.ziLuat<<"/"<<imp.lunaLuat<<"/"<<imp.anLuat<<endl;
    out<<"Cartile trebuie returnate pana pe date de "<<imp.ziScadent<<"/"<<imp.lunaScadent<<"/"<<imp.anScadent<<endl;
	out<<"A imprumutat "<<imp.nrcarti<<" carti."<<endl;
        for(int i=0; i<imp.nrcarti; i++)
    {
        cout<<"Pentru cartea "<<i+1<<" avem urmatoarele date: ";
        out<<imp.listaCarti[i];
        cout<<endl;
    }
    out<<"Imprumutul are ID-ul unic "<<imp.IDimprumut<<endl;
    return out;
}
    imprumut imprumut::operator++()
    {
        this->nrcarti++;
        return *this;
    }
    imprumut imprumut::operator++(int)
{
        imprumut aux = *this;
        this->nrcarti++;
        return aux;
    }
    imprumut imprumut::operator+=(int x)
    {
        this->nrcarti+= x;
        return *this;
    }
    imprumut imprumut::operator+(int x)
    {
        imprumut aux = *this;
        aux.nrcarti = aux.nrcarti + x;
        return aux;
    }
    imprumut imprumut::operator+(imprumut a)
    {
        a.nrcarti = a.nrcarti + this->nrcarti;
        return a;
    }
    imprumut imprumut::operator*=(int x)
    {
        this->nrcarti*= x;
        return *this;
    }
    imprumut imprumut::operator*(int x)
    {
        imprumut aux = *this;
        aux.nrcarti = aux.nrcarti * x;
        return aux;
    }
    imprumut imprumut::operator*(imprumut a)
    {
        a.nrcarti = a.nrcarti * this->nrcarti;
        return a;
    }
    bool imprumut::operator==(const imprumut& a)
    {
        if (this->nrcarti == a.nrcarti)
            return true;
        return false;
    }
	bool imprumut::operator>=(const imprumut& a)
    {
        if (this->nrcarti == a.nrcarti)
            return true;
        return false;
    }
int imprumut::contorID2=1000;
int main()
{

    vector <imprumut> listaImprumuturi;
    vector <autor> listaAutori;
    vector <client> listaClienti;
    vector <carte> listaCarti;
    int k=1,comanada;
    while(k==1)
    {
        cout<<"1-add imprumut\n";
        cout<<"2-add autor\n";
        cout<<"3-add carte\n";
        cout<<"4-add client\n";
        cout<<"5-afisam imprumut\n";
        cout<<"6-afisam autor\n";
        cout<<"7-afisam carte\n";
        cout<<"8-afisam client\n";
        cout<<"9-stergem imprumuturile\n";
        cout<<"10-stergem autorii\n";
        cout<<"11-stergem cartile\n";
        cout<<"12-stergem clientii\n";
        cout<<"13-schimbare nume autor\n";
        cout<<"14-decrementare numar carti autor\n";
        cout<<"15-setare - autorul nu mai este contemporan\n";
        cout<<"16-verificare autorul este contemporan\n";
        cout<<"17-afisarea numelui complet al autoruli\n";
        cout<<"18-modificare garantie carte\n";
        cout<<"19-reducere numar exemplare carte de x ori\n";
        cout<<"20-verificare daca cartea are peste 500 de pagini sau nu\n";
        cout<<"21-verificare daca cartea este de aventura sau nu\n";
        cout<<"22-afisare suma totala datorii client\n";
        cout<<"23-verificare daca clientul are cel puti 50 de ani\n";
        cout<<"24-actualizare varsta client\n";
        cout<<"25-modificare nume client\n";
        cout<<"26-afisare date despre cea mai lunga carte imprumutata\n";
        cout<<"27-verificare daca imprumutul este unul mare sau nu\n";
        cout<<"28-actualizare data de retur imprumut\n";
        cout<<"29-actulizare imprumut din nereturnat in returnat\n";
        cout<<"30-adunare intre clasa carte si clasa imprumut\n";
        cout<<"31-stop\n";
        cin>>comanada;
        switch(comanada)
        {
        case 1:
        {
            imprumut imp;
            cin>>imp;
            listaImprumuturi.push_back(imp);
            break;
        }
        case 2:
        {
            autor aut;
            cin>>aut;
            listaAutori.push_back(aut);
            break;
        }
        case 3:
        {
            carte c;
            cin>>c;
            listaCarti.push_back(c);
            break;
        }
        case 4:
        {
            client cl;
            cin>>cl;
            listaClienti.push_back(cl);
            break;
        }
        case 5:
        {
            for(int i=0; i<listaImprumuturi.size(); i++)
                cout<<listaImprumuturi[i]<<endl;
            break;
        }
        case 6:
        {
            for(int i=0; i<listaAutori.size(); i++)
                cout<<listaAutori[i]<<endl;
            break;
        }
        case 7:
        {
            for(int i=0; i<listaCarti.size(); i++)
                cout<<listaCarti[i]<<endl;
            break;
        }
        case 8:
        {
            for(int i=0; i<listaClienti.size(); i++)
                cout<<listaClienti[i]<<endl;
            break;
        }
        case 9:
        {
            while (!listaImprumuturi.empty())
                listaImprumuturi.pop_back();
            break;
        }
        case 10:
        {
             while (!listaAutori.empty())
                listaAutori.pop_back();
            break;
        }
        case 11:
        {
             while (!listaCarti.empty())
                listaCarti.pop_back();
            break;
        }
        case 12:
        {
             while (!listaClienti.empty())
                listaClienti.pop_back();
            break;
        }
        case 13:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            cin.get();
            char nume[100];
            cout<<"noul nume este: ";
            cin.getline(nume,100);
            listaAutori[index].setnume(nume);
            cout<<listaAutori[index];
            break;
        }
        case 14:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            listaAutori[index]--;
            cout<<listaAutori[index];
            break;
        }
        case 15:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            listaAutori[index].setinviata(0);
            cout<<listaAutori[index];
            break;
        }
        case 16:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            listaAutori[index].contemporan();
            break;
        }
        case 17:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            listaAutori[index].numecomplet();
            break;
        }
        case 18:
        {
            int index;
            float x;
            cout<<"index existent: ";
            cin>>index;
            cout<<"noua garantie este: ";
            cin>>x;
            listaCarti[index].setgarantie(x);
            cout<<listaCarti[index];
            break;
        }
        case 19:
        {
            int index,x;
            cout<<"index existent: ";
            cin>>index;
            cout<<"numarul cartilor se reduce de cate ori ";
            cin>>x;
            listaCarti[index] = listaCarti[index]/x;
            cout<<listaCarti[index];
            break;
        }
        case 20:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            listaCarti[index].cartiLungi();
            break;
        }
        case 21:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            listaCarti[index].aventura();
            break;
        }
        case 22:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            cout<<"Suma datorata este "<<listaClienti[index].sumadatorii()<<endl;
            break;
        }
        case 23:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            cout<<listaClienti[index].peste50()<<endl;
            break;
        }
        case 24:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            listaClienti[index].setvarsta(listaClienti[index].getvarsta()+1);
            cout<<listaClienti[index];
            break;
        }
        case 25:
        {
            int index;
            char s[100];
            cout<<"index existent: ";
            cin>>index;
            cin.get();
            cout<<"noul nume este: ";
            cin.getline(s,100);
            listaClienti[index].setnume(s);
            cout<<listaClienti[index];
            break;
        }
        case 26:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            cout<<listaImprumuturi[index].LungimeMaxima();
            break;
        }
        case 27:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            cout<<listaImprumuturi[index].imprumutMare()<<endl;
            break;
        }
        case 28:
        {
            int index,an,luna,zi;
            cout<<"index existent: ";
            cin>>index;
            cout<<"Noua zi de retur este: ";
            cin>>zi;
            cout<<"Noua luna de retur este: ";
            cin>>luna;
            cout<<"Noul an de retur este: ";
            cin>>an;
            listaImprumuturi[index].setziScadent(zi);
            listaImprumuturi[index].setlunaScadent(luna);
            listaImprumuturi[index].setanScadent(an);
            cout<<listaImprumuturi[index];
            break;
        }
        case 29:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            listaImprumuturi[index].setreturnat(1);
            cout<<listaImprumuturi[index];
            break;
        }
        case 30:
        {
            int index;
            cout<<"index existent: ";
            cin>>index;
            carte a,b;
            cout<<"cisteste prima carte"<<endl;
            cin>>a;
            cout<<"citeste a doua carte"<<endl;
            cin>>b;
            listaImprumuturi[index]=b+listaImprumuturi[index]+a;
            break;
        }
        case 31:
        {
            k=0;
            break;
        }
        default:
        {
            cout<<"Ati introdus o valoare gresita"<<endl;
            break;
        }
        }
    }
    return 0;
}

