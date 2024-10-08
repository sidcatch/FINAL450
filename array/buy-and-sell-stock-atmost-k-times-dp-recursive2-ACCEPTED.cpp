#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//See gfg for more methods of solving!

int findMaximumProfit(vector<int> &prices, int i, int k, bool holding, vector<vector<vector<int>>> &v)
{

    if (i < 0 || k <= 0)
        return 0;

    if (i == 0 && holding)
        return v[i][k][holding] = -prices[0];
    if (i == 0 && !holding)
        return v[i][k][holding] = 0;

    if (v[i][k][holding] != -1)
        return v[i][k][holding];

    if (holding)
        return v[i][k][true] = max(-prices[i] + findMaximumProfit(prices, i - 1, k - 1, false, v), //Here one transaction was completed so we subtract k.
                                   findMaximumProfit(prices, i - 1, k, true, v));

    else
        return v[i][k][false] = max(prices[i] + findMaximumProfit(prices, i - 1, k, true, v),
                                    findMaximumProfit(prices, i - 1, k, false, v));
}

int maxProfit(vector<int> &prices, int k)
{

    // // If transactions are greater than number of prices, then solve same as when infinite transactions are allowed

    // if (2 * k > prices.size())
    // {
    //     int res = 0;
    //     for (int i = 1; i < prices.size(); i++)
    //     {
    //         res += max(0, prices[i] - prices[i - 1]);
    //     }
    //     return res;
    // }

    int n = prices.size();
    vector<vector<vector<int>>> v(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));

    return findMaximumProfit(prices, n - 1, k, false, v);
}

int main()
{

    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;

    // vector<int> prices = {2, 4, 1};
    // int k = 2;

    // vector<int> prices = {10, 22, 5, 75, 65, 80};
    // int k = 2;

    int ans = maxProfit(prices, k);

    cout << ans << endl;

    return 0;
}
