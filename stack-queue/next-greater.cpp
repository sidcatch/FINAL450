#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int a[] = {3, 5, 6, 35, 2, 4, 56, 75, 3, 3, 60, 23};

    int n = sizeof(a) / sizeof(a[0]);
    int r[n];

    stack<int> s;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!s.empty() && s.top() <= a[i])
        {
            s.pop();
        }

        if (s.empty())
            r[i] = -1;
        else
            r[i] = s.top();

        s.push(a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << r[i] << " ";
    cout << endl;

    return 0;
}