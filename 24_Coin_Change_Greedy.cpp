// Q24. Solve Coin Change using Greedy to find minimum number of coins.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, amount;
    cout << "Enter number of coin denominations: ";
    cin >> n;
    if (n <= 0)
        return 0;
    vector<int> c(n);
    cout << "Enter denominations: ";
    for (int &x : c)
        cin >> x;
    cout << "Enter amount: ";
    cin >> amount;
    if (amount < 0)
        return 0;
    sort(c.rbegin(), c.rend());
    int count = 0;
    cout << "Coins used: ";
    for (int x : c)
        if (x > 0)
        {
            int take = amount / x;
            if (take)
            {
                cout << x << " x " << take << "\n";
                count += take;
                amount %= x;
            }
        }
    if (amount)
        cout << "Greedy cannot make the remaining amount " << amount << "\n";
    else
        cout << "Total coins: " << count << "\nNote: Greedy is not optimal for every coin system.\n";
}
