// C++ program to rearrange an array such that positive and negative numbers are placed alternatively
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the no. of elements: ";
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Element "<<i+1<<": ";
        cin>>arr[i];
    }
    
    vector<int>result(n);
    int pos_index=0,neg_index=1;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>=0)
        {
            result[pos_index]=arr[i];
            pos_index+=2;
        }
        else
        {
            result[neg_index]=arr[i];
            neg_index+=2;
        }
    }

    cout<<"Rearranged array: ";
    for(int i=0;i<n;i++)
    {
        cout<<result[i]<<" ";
    }
}