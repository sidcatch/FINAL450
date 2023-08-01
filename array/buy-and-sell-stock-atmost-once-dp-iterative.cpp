#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    // 2D DP array to store max profit with 0 and 1 stocks
    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0] = -prices[0];
    dp[0][1] = 0;

    for (int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], -prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
    }

    return max(dp.back()[0], dp.back()[1]);
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << ans << endl;
    return 0;
}
