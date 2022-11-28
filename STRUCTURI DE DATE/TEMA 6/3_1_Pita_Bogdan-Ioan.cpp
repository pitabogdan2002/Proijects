#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
       vector <string> output;
    void bkt(int k, vector <string> taste, string digits, string solutie)
    {
        if(k==digits.size())
            output.push_back(solutie);
        else
        {
            int poz = int(digits[k])-50;
            for(int i=0; i<taste[poz].size(); i++)
            {
                solutie.push_back(taste[poz][i]);
                bkt(k+1, taste, digits,solutie);
                solutie.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits)
    {
        if(digits.empty())
            return output;
        vector <string> taste;
        taste.push_back("abc");
        taste.push_back("def");
        taste.push_back("ghi");
        taste.push_back("jkl");
        taste.push_back("mno");
        taste.push_back("pqrs");
        taste.push_back("tuv");
        taste.push_back("wxyz");
        string solutie="";
        bkt(0,taste,digits,solutie);
        return output;
    }
};


int main()
{

}
