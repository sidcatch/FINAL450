#include <bits/stdc++.h>
using namespace std;

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int i;
        vector<int> a(n);
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int start = 0;
        int end = n - 1;

        while (start < end)
        {
            int temp = a[start];
            a[start] = a[end];
            a[end] = temp;
            start++;
            end--;
        }

        /* vector<int> b(n);
        for (i = 0; i < n; i++)
        {
            b[i] = a[n - 1 - i];
        } */

        for (i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}