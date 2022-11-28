#include <iostream>
using namespace std;
int m,v[100][100],i,j;
struct Node
{
    int linie;
    int coloana;
    int label;
    Node *Next;
};
int main()
{
    cin>>m;
    for(i=1; i<=m; i++)
        for(j=1; j<=m; j++)
            cin>>v[i][j];
    cout<<endl;
    int nr = 1;
    for(i=1; i<=m; i++)
        for(j=1; j<=m; j++)
            if(v[i][j]==1)
                {
                    if(v[i][j-1]!=0 && v[i][j-1]!=1)
                    v[i][j]=v[i][j-1];
                else if (v[i-1][j]!=0 && v[i-1][j]!=1)
                    v[i][j]=v[i-1][j];
                else if (v[i+1][j]!=0 && v[i+1][j]!=1)
                    v[i][j]=v[i+1][j];
                else if (v[i][j+1]!=0 && v[i][j+1]!=1)
                    v[i][j]=v[i][j+1];
                else{
                    nr++;
                    v[i][j]=nr;
                }
                if(v[i+1][j]!=0)
                    v[i+1][j]=v[i][j];
                if(v[i-1][j]!=0)
                    v[i-1][j]=v[i][j];
                if(v[i][j+1]!=0)
                    v[i][j+1]=v[i][j];
                if(v[i][j-1]!=0)
                    v[i][j-1]=v[i][j];
                }
    for(i=1; i<=m; i++)
    {
        for(j=1; j<=m; j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
