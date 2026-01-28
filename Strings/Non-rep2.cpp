#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){
    vector<string> arr={"apple","banana","grapes","orange","apple","orange","banana"};
    string res="NONE";
    unordered_map<string,int> freq;
    for(int i=0;i<arr.size();i++)
    {
        freq[arr[i]]++;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(freq[arr[i]]==1)
        {
            res=arr[i];
            break;
        }
    }
    cout<<res;




}