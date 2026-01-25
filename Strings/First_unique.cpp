#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    vector<char> freq(256,0);
    for(char ch:s)
    {
        freq[ch]++;
    }
    for(int i=0;i<freq.size();i++)
    {
        if(freq[s[i]]==1)
        {
            cout<<i;
            return 0;   
        }
    }
    cout<<-1;
    return 0;
}