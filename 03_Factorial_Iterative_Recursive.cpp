// Q3. Implement factorial using iterative and recursive approaches and compare complexity.
#include <bits/stdc++.h>
using namespace std;
unsigned long long iterativeFactorial(int n)
{
    unsigned long long ans = 1;
    for (int i = 2; i <= n; ++i)
        ans *= i;
    return ans;
}
unsigned long long recursiveFactorial(int n)
{
    if (n <= 1)
        return 1;
    return n * recursiveFactorial(n - 1);
}
int main()
{
    int n;
    cout << "Enter n (0 to 20): ";
    cin >> n;
    if (n < 0 || n > 20)
    {
        cout << "Enter a value from 0 to 20.\n";
        return 0;
    }
    cout << "Iterative factorial: " << iterativeFactorial(n);
    cout << "\nRecursive factorial: " << recursiveFactorial(n);
    cout << "\nBoth time: O(n); iterative auxiliary space: O(1); recursive: O(n).\n";
}
