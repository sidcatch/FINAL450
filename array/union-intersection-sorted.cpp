#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[] = {1, 2, 2, 4, 4, 5, 5, 5, 5, 8, 8, 10, 12};
    int n = 13;

    int b[] = {2, 2, 2, 2, 3, 12};
    int m = 6;

    cout << "a: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "b: ";
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    vector<int> U;
    vector<int> I;

    int i = 0, j = 0;
    while (i < n && j < m)
    {

        if (a[i] < b[j])
        {
            if (U.empty() || U.back() != a[i])
                U.push_back(a[i]);
            i++;
        }
        else if (a[i] > b[j])
        {
            if (U.empty() || U.back() != b[j])
                U.push_back(b[j]);
            j++;
        }
        else
        {
            if (U.empty() || U.back() != a[i])
                U.push_back(a[i]);
            if (I.empty() || I.back() != a[i])
                I.push_back(a[i]);
            i++;
            j++;
        }
    }

    while (i < n)
    {
        if (U.empty() || U.back() != a[i])
            U.push_back(a[i]);
        i++;
    }

    while (j < m)
    {
        if (U.empty() || U.back() != b[j])
            U.push_back(b[j]);
        j++;
    }

    cout << "union: ";
    for (int i : U)
    {
        cout << i << " ";
    }

    cout << endl;

    cout << "intersection: ";
    for (int i : I)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}