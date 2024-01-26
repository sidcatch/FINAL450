#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int findMaximumProfit(vector<int> &prices, int i, bool sell, vector<vector<int>> &v)
{
    if (i <= 0 && !sell)
        return -prices[0];

    if (i <= 0)
        return 0;

    if (v[i][sell] != -1)
        return v[i][sell];

    if (sell)
        return v[i][sell] = max(prices[i] + findMaximumProfit(prices, i - 1, !sell, v),
                                findMaximumProfit(prices, i - 1, sell, v));
    else
        return v[i][sell] = max(-prices[i],
                                findMaximumProfit(prices, i - 1, sell, v));
}

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> v(n, vector<int>(2, -1));

    return findMaximumProfit(prices, n - 1, 1, v);
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}
