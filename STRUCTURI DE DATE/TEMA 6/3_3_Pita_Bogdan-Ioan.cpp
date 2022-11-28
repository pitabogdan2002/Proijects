#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector <string> findRepeatedDnaSequences(string s)
{
   {
    vector <string> solutie;
    if(s.size()<=10)
        return solutie;
    for(int i=0; i<s.size()-10; i++)
    {
        string ten = "";
        ten = s.substr(i, 10);
        int ok = 1;
        for(int j=0; j<solutie.size(); j++)
            if(solutie[j]==ten)
                ok=0;
        if(ok)
        {
            size_t poz = s.find(ten,i+1);
            if (poz != string::npos)
                solutie.push_back(ten);
        }

    }
    return solutie;
}
}
};
int main()
{

}
