#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//See gfg for more methods of solving!

int findMaximumProfit(vector<int> &prices, int i, bool holding, vector<vector<int>> &v)
{

    if (i >= prices.size())
        return 0;

    if (v[i][holding] != -1)
        return v[i][holding];

    if (holding)
        return v[i][holding] = max(-prices[i] + findMaximumProfit(prices, i + 1, !holding, v),
                                   findMaximumProfit(prices, i + 1, holding, v));

    else
        return v[i][holding] = max(prices[i] + findMaximumProfit(prices, i + 2, !holding, v), //Skip one day as a cool because of cool down period!
                                   findMaximumProfit(prices, i + 1, holding, v));
}

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> v(n, vector<int>(2, -1));

    return findMaximumProfit(prices, 0, 1, v);
}

int main()
{

    vector<int> prices = {1, 2, 3, 0, 2};

    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}
