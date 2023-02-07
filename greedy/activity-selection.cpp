// There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
// What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?

// Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting.

#include <bits/stdc++.h>
using namespace std;

void maxActivityPrint(int s[], int f[], int n)
{
    if (n == 0)
        return;

    pair<int, int> a[n];

    for (int i = 0; i < n; i++)
    {
        a[i].first = f[i];
        a[i].second = i;
    }

    sort(a, a + n);

    vector<int> m;

    m.push_back(a[0].second + 1);

    int lastSelctedActivityFinishingTime = a[0].first;

    for (int i = 1; i < n; i++)
    {
        if (s[a[i].second] >= lastSelctedActivityFinishingTime)
        {
            m.push_back(a[i].second + 1);
            lastSelctedActivityFinishingTime = a[i].first;
        }
    }

    for (int i = 0; i < m.size(); i++)
    {
        cout << m[i] << " ";
    }
}

int main()
{

    int s[] = {1, 3, 0, 5, 8, 5};

    int f[] = {2, 4, 6, 7, 9, 9};

    int n = sizeof(s) / sizeof(s[0]);

    maxActivityPrint(s, f, n);

    return 0;
}