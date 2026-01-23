/*
 * LeetCode 387: First Unique Character in a String
 * Difficulty: Easy
 *
 * Given a string s, find the first non-repeating character and return its index.
 * If it does not exist, return -1.
 */
    
#include <bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {
    vector<int> freq(256, 0);

    for (char c : s) {
        freq[c]++;
    }

    for (int i = 0; i < s.size(); i++) {
        if (freq[s[i]] == 1) {
            return i;
        }
    }
    return -1;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int index = firstUniqChar(s);

    if (index != -1) {
        cout << "First non-repeating character is '" 
             << s[index] << "' at index " << index << endl;
    } else {
        cout << "No non-repeating character found." << endl;
    }

    return 0;
}
