#include <iostream>
#include <stack>
#include <utility>

using namespace std;

int main()
{
    int a[] = {6, 2, 5, 4, 5, 1, 6};

    int n = sizeof(a) / sizeof(a[0]);
    // int widths[n];

    stack<int> s; // indexes

    int i = 0;
    while (i < n)
    {
        if (s.empty() || a[i] >= a[s.top()])
            s.push(i++);
        else
        {
            int pos = s.top();
            s.pop();

            // widths[pos] = s.empty() ? i : i - s.top() - 1;

            int width = s.empty() ? i : i - s.top() - 1;
            // Calculate Area here!
        }
    }

    while (!s.empty())
    {
        int pos = s.top();
        s.pop();

        // widths[pos] = s.empty() ? i : i - s.top() - 1;
        int width = s.empty() ? i : i - s.top() - 1;

        //Calculate Area here!
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    // for (int i = 0; i < n; i++)
    //     cout << widths[i] << " ";
    // cout << endl;

    return 0;
}