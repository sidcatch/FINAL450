#include <bits/stdc++.h>
using namespace std;

// Also see, buy-and-sell-stock-atmost-once-dp-recursive4.cpp

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][0 /* 1 stock */] = -prices[0]; // The maximum profit on day i when holding 1 stock or not sold today or earlier
    dp[0][1 /* 0 stocks */] = 0;         // The maximum profit on day i when holding 0 stocks or sold today or earlier

    for (int i = 1; i < n; i++)
    {
        dp[i][0 /* 1 stock */] = max(dp[i - 1][0 /* 1 stock */], -prices[i]);
        dp[i][1 /* 0 stocks */] = max(dp[i - 1][1], dp[i - 1][0 /* 1 stock */] + prices[i]);
    }

    return max(dp.back()[0], dp.back()[1]);
    // return dp.back()[1];
}

int main()
{

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << ans << endl;
    return 0;
}
