#include <bits/stdc++.h>
using namespace std;

int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);

    int tempmin = arr[0] + k;
    int tempmax = arr[n - 1] - k;
    int ans = arr[n - 1] - arr[0];
    // int ans = INT_MAX;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - k < 0)
            continue;

        tempmin = min(tempmin, arr[i] - k);

        tempmax = max(tempmax, arr[i - 1] + k);

        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

int main()
{
    int k = 6, n = 6;
    int arr[n] = {7, 4, 8, 8, 8, 9};
    int ans = getMinDiff(arr, n, k);
    cout << ans;
    cout << endl;
}