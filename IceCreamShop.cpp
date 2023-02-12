#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, int>
#define mp make_pair
#define lli long long int

int main()
{
    int n, m;
    cin >> n >> m;
    lli tot = 0;
    vector<int> people(n);
    vector<int> huts(n);
    vector<int> shops(m);
    vector<lli> partial_sums(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tot += x;
        partial_sums[i] = tot; // people in huts 0,1,...,i
        people[i] = x;
        huts[i] = i * 100;
    }

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        shops[i] = x;
    }

    sort(shops.begin(), shops.end());

    vector<pp> intervals;

    // Binary Search
    for (int i = 0; i < n; i++)
    {

        int mmin = 0, mmax = m - 1;
        int minDistance = INT_MAX;

        while (mmax - mmin > 1)
        {
            int mid = (mmax + mmin) / 2;
            if (abs(shops[mid] - huts[i]) < minDistance)
            {
            }
            if (shops[mid] - huts[i] > 0)
            {
                mmax = mid;
            }
            else
            {
                mmin = mid;
            }
        }

        minDistance = min(abs(shops[mmax] - huts[i]), abs(shops[mmin] - huts[i]));

        if (i == 0)
        {
            intervals.push_back(mp(0, huts[i] + minDistance));
        }
        else
        {
            intervals.push_back(mp(huts[i] - minDistance, huts[i] + minDistance));
        }
    }

    int size = intervals.size();

    vector<lli> solutions;

    for (int i = 0; i < size; i++)
    {

        if (intervals[i].first == intervals[i].second)
            continue;

        int mmin = i, mmax = size - 1, mid = 0;
        mid = (mmax + mmin) / 2;
        while (mmax - mmin > 1)
        {
            mid = (mmax + mmin) / 2;
            if (intervals[i].second > intervals[mid].first)
            {
                mmin = mid;
            }
            else
            {
                mmax = mid;
            }
        }

        int v;
        if (intervals[i].second > intervals[mmax].first)
            v = mmax;
        else
            v = mmin;

        if (i == 0)
        {
            solutions.push_back(partial_sums[v]);
        }
        else
        {
            solutions.push_back(partial_sums[v] - partial_sums[i - 1]);
        }
    }
    if (solutions.empty())
    {
        cout << "0";
    }
    else
    {
        lli max_sol = *max_element(solutions.begin(), solutions.end());
        cout << max_sol;
    }
}
