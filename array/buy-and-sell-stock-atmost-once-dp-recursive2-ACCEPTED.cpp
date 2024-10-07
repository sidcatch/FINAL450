#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int findMaximumProfit(vector<int> &prices, int i, bool buy, vector<vector<int>> &v)
{

    if (i < 0)
        return 0;

    if (i == 0 && buy)
        return v[i][buy] = -prices[0];
    if (i == 0 && !buy)
        return v[i][buy] = 0;

    if (v[i][buy] != -1)
        return v[i][buy];

    if (buy)
        return v[i][true] = max(-prices[i],
                                findMaximumProfit(prices, i - 1, true, v));
    else
        return v[i][false] = max(prices[i] + findMaximumProfit(
                                                 prices, i - 1, true, v),
                                 findMaximumProfit(prices, i - 1, false, v));
}

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> v(n, vector<int>(2, -1));

    return findMaximumProfit(prices, n - 1, false, v);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}
