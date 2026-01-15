/*
    Find the missing number in the Array
    SUM METHOD:
      Actual(Sumation)
      Expected=n(n+1)/2
      Missing=Expected-Actual
    
    Time Complexity: O(n)
    Space Complexity: O(1)
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> arr(100);
    int n,missing;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the array elements : ";
    int exp=0,act=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        act+=arr[i];
    }
    exp= (n*(n+1))/2;
    missing = exp-act;
    cout<<"Missing number: "<<missing;

}