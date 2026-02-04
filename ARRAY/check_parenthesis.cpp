// Check for Balanced Parenthesis in a string using Stack
#include<iostream>
#include<stack>
#include<string>
using namespace std;

class Solution {
public:
    bool isvalid(string& s){
        stack<char>st;

        for(char ch : s){
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                if(st.empty())
                    return false;

                char t = st.top();
                st.pop();

                if((ch == ')' && t != '(') || 
                   (ch == '}' && t != '{') || 
                   (ch == ']' && t != '[')){
                    return false;
            }

        }

    }
    return st.empty();
}
};

int main(){
    string s;
    cout<<"Enter the parenthesis string: ";
    cin>>s;

    Solution obj;
    if(obj.isvalid(s)){
        cout<<"The parenthesis string is valid/Balanced."<<endl;
    }
    else{
        cout<<"The parenthesis string is not valid/Not Balanced ."<<endl;
    }

    return 0;
}