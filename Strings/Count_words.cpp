#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cout<<"Enter a string :  ";
    getline(cin,s);
    bool insideword=false;
    int count=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] != ' ' && insideword== false)
        {
            count++;
            insideword=true;
        }
        else if(s[i]== ' ')
        {
            insideword=false;
        }
    }
    cout<<count;
}