#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n <= 1)
        return 0;

    int prevNotHolding = 0;
    int prevHolding = -prices[0];
    int prevPrevNotHolding = 0;

    for (int i = 1; i < n; i++)
    {
        int currNotHolding = max(prevNotHolding, prevHolding + prices[i]);
        int currHolding = max(prevHolding, prevPrevNotHolding - prices[i]);

        prevPrevNotHolding = prevNotHolding;
        prevNotHolding = currNotHolding;
        prevHolding = currHolding;
    }

    return prevNotHolding;
}

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};

    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}