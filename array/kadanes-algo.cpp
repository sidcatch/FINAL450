#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;

    int maxSumFound = INT_MIN;
    int currentMaxSum = 0;

    int start = 0;
    int end = 0;

    for (int i = 0; i < n; i++)
    {
        currentMaxSum += a[i];

        if (currentMaxSum > maxSumFound)
        {
            maxSumFound = currentMaxSum;
            end = i;
        }

        if (currentMaxSum < 0)
        {
            currentMaxSum = 0;
            start = i + 1;
        }
    }

    cout << "Index " << start << " to " << end << " is maximum sum array with sum " << maxSumFound;

    cout << endl;

    return 0;
}