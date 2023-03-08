#include <bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int> arr, int N)
{
    if (N == 1)
        return arr[0];

    if (N == 2)
        return max(arr[0], arr[1]);

    int r[N];

    r[0] = arr[0];
    r[1] = arr[1];

    for (int i = 2; i < N; i++)
    {
        int maxSumSofar = INT_MIN;
        for (int j = i - 2; j >= 0; j--)
            if (r[j] > maxSumSofar)
                maxSumSofar = r[j];

        if (maxSumSofar != INT_MIN)
            r[i] = maxSumSofar + arr[i];
        else
            r[i] = arr[i];
    }

    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
        if (r[i] > ans)
            ans = r[i];

    // for (int i = 0; i < N; i++)
    //     cout << r[i] << " ";
    //5 5 15 105 15 10
    // cout << endl;

    return ans;
}

int findMaxSum2(vector<int> arr, int N)
{
    if (N == 1)
        return arr[0];

    if (N == 2)
        return max(arr[0], arr[1]);

    int r[N];

    r[0] = arr[0];
    r[1] = arr[1];

    int maxSumSoFarExcludingLast = arr[0];

    for (int i = 2; i < N; i++)
    {

        r[i] = maxSumSoFarExcludingLast + arr[i];

        if (r[i - 1] > maxSumSoFarExcludingLast)
            maxSumSoFarExcludingLast = r[i - 1];
    }

    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
        if (r[i] > ans)
            ans = r[i];

    // for (int i = 0; i < N; i++)
    //     cout << r[i] << " ";
    //5 5 15 105 15 10
    // cout << endl;

    return ans;
}

int findMaxSum3(vector<int> arr, int N)
{

    int dp[N][2];
    if (N == 1)
    {
        return arr[0];
    }

    dp[0][0] = 0;
    dp[0][1] = arr[0];

    for (int i = 1; i < N; i++)
    {
        dp[i][1] = dp[i - 1][0] + arr[i];
        dp[i][0] = max(dp[i - 1][1],
                       dp[i - 1][0]);
    }

    return max(dp[N - 1][0], dp[N - 1][1]);
}

int main()
{
    vector<int> arr = {5, 5, 10, 100, 10, 5};
    int N = arr.size();

    cout << findMaxSum3(arr, N) << endl;
    return 0;
}
