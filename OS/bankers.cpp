#include <iostream>
#include <vector>
using namespace std;

int main() {

    int n = 5;
    int r = 3; 
    vector<vector<int>> alloc = {{0, 0, 1},
                                 {3, 0, 0}, 
                                 {1, 0, 1}, 
                                 {2, 3, 2},
                                 {0, 0, 3}}; 

    vector<vector<int>> max = {{7, 6, 3}, 
                                {3, 2, 2}, 
                                {8, 0, 2}, 
                                {2, 1, 2},
                                {5, 2, 3}}; 

    vector<int> avail = {2, 3, 2}; 

    vector<int> f(n, 0);
    vector<int> ans(n);
    int ind = 0;
    vector<vector<int>> need(n, vector<int>(r));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (int j = 0; j < r; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < r; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

if (ind == n) {
    cout << "The system is in a SAFE state.\n";
    cout << "The SAFE Sequence is as follows:\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << ans[i];
        if (i != n - 1)
            cout << " -> ";
    }
    cout << endl;
}
else {
    cout << "The system is in an UNSAFE state.\n";
    cout << "No safe sequence exists. Deadlock may occur.\n";
}
}