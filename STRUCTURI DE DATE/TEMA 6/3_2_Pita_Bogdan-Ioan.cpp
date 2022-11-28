#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
string intToRoman(int num)
{
    string solutie;
    map <int,string> taste;
    taste[1]="I";
    taste[4]="IV";
    taste[5]="V";
    taste[9]="IX";
    taste[10]="X";
    taste[40]="XL";
    taste[50]="L";
    taste[90]="XC";
    taste[100]="C";
    taste[400]="CD";
    taste[500]="D";
    taste[900]="CM";
    taste[1000]="M";
    for (auto it=taste.rbegin(); it!=taste.rend(); ++it)
    {
        while(num-it->first >= 0)
        {
            solutie = solutie + it->second;
            num = num-it->first;
        }
    }
    return solutie;
}
};
int main()
{

}
