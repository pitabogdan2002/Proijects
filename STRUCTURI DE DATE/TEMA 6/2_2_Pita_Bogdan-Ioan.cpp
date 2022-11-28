#include <iostream>
using namespace std;
int v[11],n,k,i,j;
int main()
{
    for(i=1; i<=8; i++)
    {
        cin>>k;
        if(v[k%11] == 0)
            v[k%11] = k;
        else
        {
            for(j=k%11+1; j<=10; j++)
                if(v[j]==0)
                {
                    v[j]=k;
                    break;
                }
        }
    }
    for(i=0; i<=10; i++)
        cout<<v[i]<<" ";
    return 0;
}
