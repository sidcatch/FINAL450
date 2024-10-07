#include <bits/stdc++.h>
using namespace std;

// Also see, buy-and-sell-stock-atmost-once-dp-recursive2.cpp

void printVector(vector<int> &v);
void printDP(vector<vector<int>> &dp);

int maxProfit(vector<int> &prices)
{
    int n = prices.size();

    vector<vector<int>> dp(n, vector<int>(2));

    dp[0][1] = -prices[0]; // The maximum profit on day i when holding 1 stock or bought today or earlier
    dp[0][0] = 0;          // The maximum profit on day i when holding 0 stocks or not bought/sold today or earlier

    for (int i = 1; i < n; i++)
    {
        dp[i][1] = max(dp[i - 1][1], -prices[i]); // Locks to minimum price.
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
    }

    printVector(prices);
    printDP(dp);

    // return max(dp.back()[0], dp.back()[1]);
    return dp.back()[0];
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int ans = maxProfit(prices);

    cout << ans << endl;
    return 0;
}

void printDP(vector<vector<int>> &dp)
{
    for (int i = 0; i < dp.size(); i++)
    {
        // Truncate numbers if they are greater than 9999 or smaller than -999
        int value0 = min(max(dp[i][0], -999), 9999);
        int value1 = min(max(dp[i][1], -999), 9999);

        // Output each number with exactly 4 spaces
        cout << setw(4) << value0 << " ";
    }
    cout << endl;
    for (int i = 0; i < dp.size(); i++)
    {
        // Truncate numbers if they are greater than 9999 or smaller than -999
        int value1 = min(max(dp[i][1], -999), 9999);

        // Output each number with exactly 4 spaces
        cout << setw(4) << value1 << " ";
    }
    cout << endl;
}

void printVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        // Truncate numbers if they are greater than 9999 or smaller than -999
        int value0 = min(max(v[i], -999), 9999);
        int value1 = min(max(v[i], -999), 9999);

        // Output each number with exactly 4 spaces
        cout << setw(4) << value0 << " ";
    }
    cout << endl;
}
