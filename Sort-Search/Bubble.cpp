// Bubble Sort Algorithm in C++
/*
    Time Complexity - O(n^2)
    Space Complexity - O(1)
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cout<< "Enter " << i + 1 << "th element: ";
        cin >> arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        int swapped = 0;
        for(int j =0; j<=i-1;j++)
        {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = 1;
            }
        }
        if(swapped == 0){
                break;
        }  
    }
    cout<<"After Bubble Sort : ";
    for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }

}