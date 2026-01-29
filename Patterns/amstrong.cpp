#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int original=n;
    int res=0;
    int ans=0;
    while(n>0)
    {
        res=n%10;
        ans=ans+pow(res,3);
        n=n/10;
    }
    if(ans==original)
        cout<<original<<" is an Armstrong number.";
    else
        cout<<original<<" is not an Armstrong number.";
}