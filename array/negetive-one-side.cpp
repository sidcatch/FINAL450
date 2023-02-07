#include <bits/stdc++.h>
using namespace std;

// |-0|-1| | | |3|2|
//        l   h

int main()
{

    int a[] = {0, -2, 1, -2, -0};
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    int l = 0, h = n - 1;

    while (l < h)
    {
        if (a[l] < 0)
            l++;
        else if (a[l] >= 0)
            swap(a[l], a[h--]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return 0;
}