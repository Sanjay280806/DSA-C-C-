#include <iostream>
#include <vector>
using namespace std;

// Calculate Need Matrix
void calculateNeed(
    const vector<vector<int>>& maximum,
    const vector<vector<int>>& allocation,
    vector<vector<int>>& need,
    int n,
    int m
) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

// Display Matrix
void displayMatrix(
    const vector<vector<int>>& matrix,
    int n,
    int m,
    string name
) {
    cout << "\n" << name << " Matrix:\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i << " : ";

        for (int j = 0; j < m; j++) {
            cout << matrix[i][j] << " ";
        }



        cout << endl;
    }
}

// Safety Algorithm
bool findSafeSequence(
    const vector<vector<int>>& allocation,
    const vector<vector<int>>& need,
    const vector<int>& available,
    vector<int>& safeSequence,
    int n,
    int m
) {
    vector<int> work = available;
    vector<bool> finish(n, false);

    int count = 0;

    while (count < n) {

        bool found = false;

        for (int i = 0; i < n; i++) {

            if (!finish[i]) {

                bool canExecute = true;

                // Check Need <= Work
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > work[j]) {
                        canExecute = false;
                        break;
                    }
                }

                if (canExecute) {

                    // Release allocated resources
                    for (int j = 0; j < m; j++) {
                        work[j] += allocation[i][j];
                    }

                    safeSequence.push_back(i);
                    finish[i] = true;
                    count++;
                    found = true;
                }
            }
        }



        if (!found) {
            return false;
        }
    }

    return true;
}

// Resource Request Algorithm
bool requestResources(
    int process,
    const vector<int>& request,
    vector<vector<int>>& allocation,
    vector<vector<int>>& need,
    vector<int>& available,
    int n,
    int m
) {
    cout << "\nChecking Resource Request for P" << process << "...\n";

    // Step 1: Request <= Need
    for (int j = 0; j < m; j++) {

        if (request[j] > need[process][j]) {

            cout << "Request is greater than the process Need.\n";
            cout << "Request CANNOT be granted.\n";

            return false;
        }
    }

    // Step 2: Request <= Available
    for (int j = 0; j < m; j++) {

        if (request[j] > available[j]) {

            cout << "Requested resources are not currently available.\n";
            cout << "Request CANNOT be granted.\n";

            return false;
        }
    }

    // Step 3: Temporarily allocate resources
    for (int j = 0; j < m; j++) {

        available[j] -= request[j];
        allocation[process][j] += request[j];
        need[process][j] -= request[j];
    }


    // Step 4: Check safety
    vector<int> safeSequence;

    bool safe = findSafeSequence(
        allocation,
        need,
        available,
        safeSequence,
        n,
        m
    );

    if (safe) {

        cout << "\nRequest CAN be GRANTED.\n";

        cout << "New Safe Sequence: ";

        for (int i = 0; i < safeSequence.size(); i++) {

            cout << "P" << safeSequence[i];

            if (i != safeSequence.size() - 1) {
                cout << " -> ";
            }
        }

        cout << endl;

        cout << "System remains SAFE.\n";

        return true;
    }

    // Step 5: Rollback if unsafe
    for (int j = 0; j < m; j++) {

        available[j] += request[j];
        allocation[process][j] -= request[j];
        need[process][j] += request[j];
    }

    cout << "\nRequest CANNOT be granted.\n";
    cout << "Granting this request would make the system UNSAFE.\n";

    return false;
}

int main() {

    int n, m;


    // Input number of processes
    cout << "Enter number of processes: ";
    cin >> n;

    // Input number of resources
    cout << "Enter number of resource types: ";
    cin >> m;

    vector<vector<int>> allocation(n, vector<int>(m));
    vector<vector<int>> maximum(n, vector<int>(m));
    vector<vector<int>> need(n, vector<int>(m));
    vector<int> available(m);

    // Input Allocation Matrix
    cout << "\nEnter Allocation Matrix:\n";

    for (int i = 0; i < n; i++) {

        cout << "P" << i << ": ";

        for (int j = 0; j < m; j++) {
            cin >> allocation[i][j];
        }
    }

    // Input Maximum Matrix
    cout << "\nEnter Maximum Matrix:\n";

    for (int i = 0; i < n; i++) {

        cout << "P" << i << ": ";

        for (int j = 0; j < m; j++) {
            cin >> maximum[i][j];
        }
    }

    // Input Available Resources
    cout << "\nEnter Available Resources: ";

    for (int j = 0; j < m; j++) {
        cin >> available[j];
    }

    // Calculate Need Matrix
    calculateNeed(
        maximum,
        allocation,
        need,
        n,
        m
    );

    // Display matrices
    displayMatrix(
        allocation,
        n,
        m,
        "Allocation"
    );

    displayMatrix(
        maximum,
        n,
        m,
        "Maximum"
    );

    displayMatrix(
        need,
        n,
        m,
        "Need"
    );

    cout << "\nAvailable Resources: ";

    for (int j = 0; j < m; j++) {
        cout << available[j] << " ";
    }

    cout << endl;

    // Check initial system safety
    vector<int> safeSequence;

    bool safe = findSafeSequence(
        allocation,
        need,
        available,
        safeSequence,
        n,
        m
    );

    if (safe) {

        cout << "\nSystem State: SAFE\n";

        cout << "Safe Sequence: ";

        for (int i = 0; i < safeSequence.size(); i++) {

            cout << "P" << safeSequence[i];


            if (i != safeSequence.size() - 1) {
                cout << " -> ";
            }
        }

        cout << endl;

    } else {

        cout << "\nSystem State: UNSAFE\n";
        cout << "No safe sequence exists.\n";
    }

    // Q4 - Resource Request
    char choice;

    cout << "\nDo you want to make a new resource request? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {

        int process;

        cout << "Enter process number: ";
        cin >> process;

        vector<int> request(m);

        cout << "Enter resource request for P"
             << process << ": ";

        for (int j = 0; j < m; j++) {
            cin >> request[j];
        }

        requestResources(
            process,
            request,
            allocation,
            need,
            available,
            n,
            m
        );
    }

    return 0;
}

