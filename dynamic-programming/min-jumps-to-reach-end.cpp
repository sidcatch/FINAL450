#include <iostream>
#include <limits.h>

using namespace std;

//Can be done faster without using Dynamic programming.
int main()
{
    int a[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    int n = sizeof(a) / sizeof(a[0]);

    int m[n];

    m[0] = 0;

    for (int i = 1; i < n; i++)
    {

        int min = INT_MAX;

        for (int j = 0; j < i; j++)
        {
            if (m[j] < min && (j + a[j] >= i) && m[j] != -1)
                min = m[j];
        }

        if (min != INT_MAX)
            m[i] = min + 1;
        else
            m[i] = -1;
    }

    cout << m[n - 1] << endl;

    return 0;
}