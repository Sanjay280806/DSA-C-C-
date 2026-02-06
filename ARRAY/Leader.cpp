 /*
    C++ program to find leaders in an array
         A leader is an element which is greater than all the elements to its right side.

Time  Complexity - O(n)
Space Complexity - O(n)  
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cout << "Enter " << i + 1 << "th element: ";
        cin >> a[i];
    }
    vector<int>leader;
    int max = a[n-1];
    leader.push_back(max);
    for(int i = n-2; i >= 0; i--){
        if(a[i] > max){
            leader.push_back(a[i]);
            max = a[i];
        }
    }
    reverse(leader.begin(), leader.end());
    cout << "Leaders in the array are: ";
    for(int i = 0; i < leader.size(); i++){
        cout << leader[i] << " ";
    }
    return 0;

}