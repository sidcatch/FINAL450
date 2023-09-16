#include <algorithm>
#include <iostream>

#define N 3

using namespace std;

bool compare(int x, int y)
{
    return x > y;
}

int minimumCostOfBreaking(int x[], int y[], int m, int n)
{

    sort(x, x + m, compare);
    sort(y, y + n, compare);

    int currCost = 0;
    int i = 0;
    int j = 0;

    while (i < m && j < n)
    {
        if (x[i] > y[j])
        {
            currCost += x[i] * (j + 1);
            i++;
        }
        else
        {
            currCost += y[j] * (i + 1);
            j++;
        }
    }

    while (i < m)
    {
        currCost += x[i] * (j + 1);
        i++;
    }

    while (j < n)
    {
        currCost += y[j] * (i + 1);
        j++;
    }

    return currCost;
}

int main()
{
    int m = 6, n = 4;
    int X[m - 1] = {2, 1, 3, 1, 4};
    int Y[n - 1] = {4, 1, 2};
    cout << minimumCostOfBreaking(X, Y, m - 1, n - 1);
    return 0;
}