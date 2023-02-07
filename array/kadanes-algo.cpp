#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = 8;

    int maxSoFar = INT_MIN;
    int potentialMax = 0;

    int start = 0;
    int end = 0;

    for (int i = 0; i < n; i++)
    {
        potentialMax += a[i];

        if (potentialMax > maxSoFar)
        {
            maxSoFar = potentialMax;
            end = i;
        }

        if (potentialMax < 0)
        {
            potentialMax = 0;
            start = i + 1;
        }
    }

    cout << "Index " << start << " to " << end << " is maximum sum array with sum " << maxSoFar;

    cout << endl;

    return 0;
}