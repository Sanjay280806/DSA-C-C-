#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector <int>nums = {5,28,6,8,13,11,7,21};
    int Count=0;
    for(int i : nums)
    {
        if(i%2==0)
        {
            Count++;
        }
    }
    cout<<"No.of even numbers: "<<Count;
}