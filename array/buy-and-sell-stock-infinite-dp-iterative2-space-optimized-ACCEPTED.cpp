#include <bits/stdc++.h>
using namespace std;

// Also see, buy-and-sell-stock-infinite-dp-iterative2-ACCEPTED.cpp

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2));

    int prevHolding = -prices[0]; // The maximum profit on day i when holding 1 stock or bought today or earlier
    int prevNotHolding = 0;       // The maximum profit on day i when holding 0 stocks or not bought/sold today or earlier

    int currHolding = 0;
    int currNotHolding = 0;

    for (int i = 1; i < n; i++)
    {
        currHolding = max(prevHolding, prevNotHolding + -prices[i]);
        currNotHolding = max(prevNotHolding, prevHolding + prices[i]);

        prevHolding = currHolding;
        prevNotHolding = currNotHolding;
    }

    return currNotHolding;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << ans << endl;
    return 0;
}
