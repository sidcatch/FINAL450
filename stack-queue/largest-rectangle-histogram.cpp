#include <iostream>
#include <limits>
#include <stack>
#include <utility>

using namespace std;

long long getMaxArea(long long a[], int n)
{

    long long maxArea = -1;

    // int widths[n];
    stack<int> s; // indexes

    int i = 0;
    for (i = 0; i < n; i++)
    {
        // if (s.empty() || a[i] >= a[s.top()])
        //     s.push(i++);
        while (!s.empty() && a[i] < a[s.top()])
        {
            int pos = s.top();
            s.pop();

            // widths[pos] = s.empty() ? i : i - s.top() - 1;

            int width = s.empty() ? i : i - s.top() - 1;
            // Calculate Area here!
            const long long area = width * a[pos];

            if (maxArea < area)
                maxArea = area;
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int pos = s.top();
        s.pop();

        // widths[pos] = s.empty() ? i : i - s.top() - 1;
        int width = s.empty() ? i : i - s.top() - 1;
        const long long area = width * a[pos];

        if (maxArea < area)
            maxArea = area;
        //Calculate Area here!
    }

    // for (int i = 0; i < n; i++)
    //     cout << a[i] << " ";
    // cout << endl;

    // for (int i = 0; i < n; i++)
    //     cout << widths[i] << " ";
    // cout << endl;

    return maxArea;
}

int main()
{
    long long a[] = {6, 2, 5, 4, 5, 1, 6};

    int n = sizeof(a) / sizeof(a[0]);

    cout << getMaxArea(a, n) << endl;

    return 0;
}