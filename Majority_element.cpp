#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int>& nums) {
    int n = nums.size();

    int el1 = -1, el2 = -1;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (cnt1 == 0 && nums[i] != el2) {
            el1 = nums[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0 && nums[i] != el1) {
            el2 = nums[i];
            cnt2 = 1;
        }
        else if (nums[i] == el1) {
            cnt1++;
        }
        else if (nums[i] == el2) {
            cnt2++;
        }
        else {
            cnt1--;
            cnt2--;
        }
    }

    
    cnt1 = 0;
    cnt2 = 0;

    for (int i = 0; i < n; i++) {
        if (nums[i] == el1) cnt1++;
        if (nums[i] == el2) cnt2++;
    }

    vector<int> ans;
    if (cnt1 > n / 3) ans.push_back(el1);
    if (cnt2 > n / 3) ans.push_back(el2);

    return ans;
}

int main() {
    vector<int> nums = {1, 1, 1, 3, 3, 2, 2, 2};   

    vector<int> result = majorityElement(nums);

    cout << "Majority elements : ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
