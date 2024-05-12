#include <bits/stdc++.h>
#include <iostream>
using namespace std;

//See gfg for more methods of solving!

int findMaximumProfit(vector<int> &prices, int i, bool buy, vector<vector<int>> &v)
{

    if (i >= prices.size())
        return 0;

    if (v[i][buy] != -1)
        return v[i][buy];

    if (buy)
        return v[i][buy] = max(-prices[i] + findMaximumProfit(prices, i + 1, !buy, v),
                               findMaximumProfit(prices, i + 1, buy, v));

    else
        return v[i][buy] = max(prices[i] + findMaximumProfit(prices, i + 2, !buy, v), //Skip one day as a cool because of cool down period!
                               findMaximumProfit(prices, i + 1, buy, v));
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
