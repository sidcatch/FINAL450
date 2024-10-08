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

    // dp[i][j][0] represents the maximum profit on day i with j transactions remaining, not holding a stock
    // dp[i][j][1] represents the maximum profit on day i with j transactions remaining, holding a stock
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, 0)));

    // Initialize the base cases
    for (int j = 0; j <= k; j++)
    {
        dp[0][j][1] = -prices[0];
    }

    // Fill the dp table
    for (int i = 1; i < n; i++)
    {
        for (int j = k; j > 0; j--)
        {
            // Holding a stock
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);

            // Not holding a stock
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
        }
    }

    return dp[n - 1][k][0];
}

int main()
{
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2;

    int ans = maxProfit(prices, k);
    cout << "Maximum profit: " << ans << endl;

    return 0;
}