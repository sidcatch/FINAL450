#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    if (n <= 1)
        return 0;

    vector<vector<int>> dp(n, vector<int>(2, 0));

    // Base cases
    dp[0][1] = -prices[0]; // Holding on day 0
    dp[0][0] = 0;          // Not holding on day 0

    for (int i = 1; i < n; i++)
    {
        // Holding
        dp[i][1] = max(dp[i - 1][1], (i >= 2 ? dp[i - 2][0] : 0) - prices[i]);

        // Not holding
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    }

    return dp[n - 1][0]; // Maximum profit is when not holding on the last day
}

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};

    int ans = maxProfit(prices);

    cout << ans << endl;

    return 0;
}