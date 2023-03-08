#include <bits/stdc++.h>
using namespace std;

int findMaxSum(vector<int> arr, int N)
{

    int dp[N][3];
    if (N == 1)
        return arr[0];

    if (N == 2)
        return arr[0] + arr[1];

    dp[0][0] = 0;
    dp[0][1] = arr[0];
    dp[0][2] = arr[0];

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = max(
            dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));

        dp[i][1] = dp[i - 1][0] + arr[i];

        dp[i][2] = dp[i - 1][1] + arr[i];
    }

    return max(dp[N - 1][0], max(dp[N - 1][1], dp[N - 1][2]));
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int N = arr.size();

    cout << findMaxSum(arr, N) << endl;
    return 0;
}
