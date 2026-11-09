// Q18. Implement Job Sequencing with Deadlines to maximize total profit.
#include <bits/stdc++.h>
using namespace std;
struct Job
{
    string id;
    int deadline, profit;
};
int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    if (n < 0)
        return 0;
    vector<Job> a(n);
    cout << "Enter job-id deadline profit:\n";
    for (auto &j : a)
        cin >> j.id >> j.deadline >> j.profit;
    sort(a.begin(), a.end(), [](auto x, auto y)
         { return x.profit > y.profit; });
    int maxD = 0;
    for (auto j : a)
        maxD = max(maxD, j.deadline);
    vector<string> slot(maxD + 1, "");
    int total = 0;
    for (auto j : a)
        for (int t = min(maxD, j.deadline); t >= 1; t--)
            if (slot[t].empty())
            {
                slot[t] = j.id;
                total += j.profit;
                break;
            }
    cout << "Scheduled jobs: ";
    for (int t = 1; t <= maxD; t++)
        if (!slot[t].empty())
            cout << slot[t] << " ";
    cout << "\nMaximum profit: " << total << "\n";
}
