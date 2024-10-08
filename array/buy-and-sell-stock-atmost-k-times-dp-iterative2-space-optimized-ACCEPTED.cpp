#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();
    if (n <= 1 || k == 0)
        return 0;

    // If k is large enough, we can make as many transactions as we want
    if (2 * k >= n)
    {
        int profit = 0;
        for (int i = 1; i < n; i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }

    // Use two arrays to store the previous state
    vector<int> prevHolding(k + 1, INT_MIN);
    vector<int> prevNotHolding(k + 1, 0);

    // Initialize the base case
    prevHolding[0] = -prices[0];

    // Fill the dp table
    for (int i = 1; i < n; i++)
    {
        vector<int> currHolding(k + 1, INT_MIN);
        vector<int> currNotHolding(k + 1, 0);

        for (int j = 0; j <= k; j++)
        {
            // Not holding a stock
            currNotHolding[j] = prevNotHolding[j];
            if (j > 0 && prevHolding[j - 1] != INT_MIN)
            {
                currNotHolding[j] = max(currNotHolding[j], prevHolding[j - 1] + prices[i]);
            }

            // Holding a stock
            currHolding[j] = prevHolding[j];
            if (prevNotHolding[j] != INT_MIN)
            {
                currHolding[j] = max(currHolding[j], prevNotHolding[j] - prices[i]);
            }
        }

        prevHolding = currHolding;
        prevNotHolding = currNotHolding;
    }

    return *max_element(prevNotHolding.begin(), prevNotHolding.end());

    // return prevNotHolding[k];
}

int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;

    int ans = maxProfit(prices, k);
    cout << "Maximum profit: " << ans << endl;

    return 0;
}