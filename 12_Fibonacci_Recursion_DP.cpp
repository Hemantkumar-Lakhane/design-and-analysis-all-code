// Q12. Implement Fibonacci using recursion and Dynamic Programming; compare time and space.
#include <bits/stdc++.h>
using namespace std;
long long fibRec(int n)
{
    if (n <= 1)
        return n;
    return fibRec(n - 1) + fibRec(n - 2);
}
long long fibDP(int n)
{
    if (n <= 1)
        return n;
    long long a = 0, b = 1;
    for (int i = 2; i <= n; i++)
    {
        long long c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int main()
{
    int n;
    cout << "Enter n (0 to 90): ";
    cin >> n;
    if (n < 0 || n > 90)
        return 0;
    auto s = chrono::high_resolution_clock::now();
    long long x = fibRec(n);
    auto m = chrono::high_resolution_clock::now();
    long long y = fibDP(n);
    auto e = chrono::high_resolution_clock::now();
    cout << "Recursive: " << x << " time(us): " << chrono::duration_cast<chrono::microseconds>(m - s).count() << "\nDP: " << y << " time(us): " << chrono::duration_cast<chrono::microseconds>(e - m).count() << "\nNaive recursion O(2^n) time/O(n) stack; iterative DP O(n) time/O(1) space.\n";
}
