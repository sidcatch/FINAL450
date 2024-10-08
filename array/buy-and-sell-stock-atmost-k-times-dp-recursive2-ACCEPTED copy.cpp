#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int maxProfit(vector<int> &prices, int k)
{
    int n = prices.size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(k, vector<int>(2)));

    dp[0][0][1] = -prices[0];
    dp[0][0][0] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < k; j++)
        {
            dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] + -prices[i]);
            dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
        }
    }

    // return max(dp.back()[0], dp.back()[1]);
    return dp.back()[k - 1][0];
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
