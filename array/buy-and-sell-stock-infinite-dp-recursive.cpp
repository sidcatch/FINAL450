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
        return v[i][buy] = max(prices[i] + findMaximumProfit(prices, i + 1, !buy, v), //When infinite transactions are allowed we added up max profit so far after selling previous stocks
                               findMaximumProfit(prices, i + 1, buy, v));
}

int maxProfit(vector<int> &prices)
{

    int n = prices.size();
    vector<vector<int>> v(n, vector<int>(2, -1));

    return findMaximumProfit(prices, 0, true, v);
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}
