#include <bits/stdc++.h>
using namespace std;

int findMaximum(int n, int x, int y, int z)
{

    int dp[n + 1];

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

int main()
{
    int l = 11, x = 2, y = 3, z = 5;

    int ans = findMaximum(l, x, y, z);
    cout << ans;

    return 0;
}