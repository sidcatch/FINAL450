#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<int> a = {1000, 11, 445, 1, 330, 3000};

    pair<int, int> minMax;

    int i;
    if (a.size() % 2 == 0)
    {
        if (a[0] > a[1])
        {
            minMax.first = a[1];
            minMax.second = a[0];
        }
        else
        {
            {
                minMax.first = a[0];
                minMax.second = a[1];
            }
        }

        i = 2;
    }
    else
    {
        minMax.first = a[0];
        minMax.second = a[0];

        i = 1;
    }

    while (i < a.size() - 1)
    {

        if (a[i] > a[i + 1])
        {
            if (a[i] > minMax.second)
                minMax.second = a[i];

            if (a[i + 1] < minMax.first)
                minMax.first = a[i + 1];
        }
        else
        {
            if (a[i + 1] > minMax.second)
                minMax.second = a[i + 1];

            if (a[i] < minMax.first)
                minMax.first = a[i];
        }

        i += 2;
    }

    cout << "Minimum element is "
         << minMax.first << endl;
    cout << "Maximum element is "
         << minMax.second;

    cout << endl;

    return 0;
}