#include <bits/stdc++.h>
using namespace std;

int Max(int a, int b, int c)
{
    return max(a, max(a, b));
}

int findMaximum(int n, int x, int y, int z)
{

    int dp[n + 1];

    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {

        int p = (i >= x && dp[i - x] != -1) ? dp[i - x] + 1 : -1;
        int q = (i >= y && dp[i - y] != -1) ? dp[i - y] + 1 : -1;
        int r = (i >= z && dp[i - z] != -1) ? dp[i - z] + 1 : -1;

        dp[i] = max(p, max(q, r));
    }

    if (dp[n] == -1)
    {
        dp[n] = 0;
    }

    return dp[n];
}

// Driver Code
int main()
{
    int l = 11, p = 2, q = 3, r = 5;

    int ans = findMaximum(l, p, q, r);
    cout << ans;

    return 0;
}