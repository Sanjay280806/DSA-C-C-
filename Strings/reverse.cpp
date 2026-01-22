#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    int low=0;
    int high=s.length()-1;
    while(low<high)
    {
        char temp=s[low];
        s[low]=s[high];
        s[high]=temp;
        low++;
        high--;
    }
    cout<<"Reversed string: "<<s;

}