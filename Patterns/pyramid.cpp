/*
        *
      * * *
    * * * * *
  * * * * * * *
* * * * * * * * *

*/
#include <iostream>
using namespace std;
int main()
{
    int n ;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << endl;
    for (int i = 1; i <= n; i++)
{
    for (int s = n - i; s > 0; s--)
        cout << "  ";
    for (int j = 1; j <= (2 * i - 1); j++)
        cout << "* ";
    cout << endl;
}
    return 0;

    
}
