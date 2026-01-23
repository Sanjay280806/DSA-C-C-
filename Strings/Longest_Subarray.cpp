
/*
   LeetCode 3: Longest Substring Without Repeating Characters
   Difficulty: Medium
 
   Given a string s, find the length of the longest substring without repeating characters.

   Time Complexity: O(n)
   Space Complexity: O(n)
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); right++) {
            while (chars.count(s[right])) {
                chars.erase(s[left]);
                left++;
            }

            chars.insert(s[right]);

            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution obj;
    int result = obj.lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters: "
         << result << endl;

    return 0;
}
