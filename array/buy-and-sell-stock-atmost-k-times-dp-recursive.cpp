#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//See gfg for more methods of solving!

int findMaximumProfit(vector<int> &prices, int i, int k, bool holding, vector<vector<int>> &v)
{

    if (i >= prices.size() || k <= 0)
        return 0;

    if (v[i][holding] != -1)
        return v[i][holding];

    if (holding)
        return v[i][holding] = max(-prices[i] + findMaximumProfit(prices, i + 1, k, !holding, v),
                                   findMaximumProfit(prices, i + 1, k, holding, v));

    else
        return v[i][holding] = max(prices[i] + findMaximumProfit(prices, i + 1, k - 1, !holding, v), //Here one transaction is complete so we subtract k.
                                   findMaximumProfit(prices, i + 1, k, holding, v));
}

int maxProfit(vector<int> &prices, int k)
{

    // If transactions are greater than number of prices, then solve same as when infinite transactions are allowed

    if (2 * k > prices.size())
    {
        int res = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }

    int n = prices.size();
    vector<vector<int>> v(n, vector<int>(2, -1));

    return findMaximumProfit(prices, 0, k, 1, v);
}

int main()
{

    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;

    // vector<int> prices = {2, 4, 1};
    // int k = 2;

    int ans = maxProfit(prices, k);

    cout << ans << endl;

    return 0;
}
