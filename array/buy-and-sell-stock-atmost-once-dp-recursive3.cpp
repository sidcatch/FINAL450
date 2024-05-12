#include <bits/stdc++.h>
using namespace std;

int findMaximumProfit(vector<int> &prices, int i, bool sell, vector<vector<int>> &v)
{

    if (i == prices.size())
        return 0;

    if (v[i][sell] != -1)
        return v[i][sell];

    if (sell)
    {

        return v[i][sell] = max(prices[i],
                                findMaximumProfit(prices, i + 1, sell, v));
    }
    else
    {

        return v[i][sell] = max(-prices[i] + findMaximumProfit(prices, i + 1, true, v),
                                findMaximumProfit(prices, i + 1, sell, v));
    }
}

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> v(n, vector<int>(2, -1));

    return findMaximumProfit(prices, 0, false, v);
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}
