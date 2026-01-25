#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    bool val=true;
    cout<<"Enter the string: ";
    getline(cin,s);
    int low=0;
    int high=s.length()-1;  
    while(low<high)
    {
        if(s[low]!=s[high])
        {
            val=false;
            break;
        }
        low++;
        high--;
    }
    if(val)
    {
        cout<<"It is a Palindrome";
    }   
    else
    {
        cout<<"It is Not a palindrome";
    }
}

