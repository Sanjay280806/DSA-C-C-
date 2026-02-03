// to find if there exists a pair with a given Target sum in an array
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    bool value;
    cout << "Enter the number of elements: ";
    cin >> n;   
    vector<int> arr(n);
    cout << "Enter array elements: "<<endl;   
    for (int i = 0; i < n; i++) {
        cout<<"Enter element "<<i+1<<": ";
        cin >> arr[i];
    }
    int target; 
    cout << "Enter the target sum: ";
    cin >> target;
    sort(arr.begin(), arr.end());
    int low = 0;
    int high = n - 1;
    while(low<high)
    {
        int sum = arr[low] + arr[high];
        if(sum==target)
        {
            value=true;
            break;
        }
        else if(sum<target)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    if(value)
    {
        cout<<"Pair with the given target sum exists in the array.";
    }
    else
    {
        cout<<"No such pair exists in the array.";
    }

    
}