#include <bits/stdc++.h>
using namespace std;

int findMaximumProfit(int i, vector<int> &prices, bool sell, vector<vector<int>> &v)
{

    if (i == prices.size())
        return 0;

    if (v[i][sell] != -1)
        return v[i][sell];

    if (sell)
    {

        return v[i][sell] = max(prices[i],
                                findMaximumProfit(i + 1, prices, sell, v));
    }
    else
    {

        return v[i][sell] = max(-prices[i] + findMaximumProfit(i + 1, prices, true, v),
                                findMaximumProfit(i + 1, prices, sell, v));
    }
}

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> v(n, vector<int>(2, -1));

    return findMaximumProfit(0, prices, false, v);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}
