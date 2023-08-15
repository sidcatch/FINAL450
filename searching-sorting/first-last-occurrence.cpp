#include <bits/stdc++.h>
using namespace std;

int findFirstOccurrence(vector<int> &a, int x)
{
    int n = a.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (a[mid] > x)
            high = mid - 1;
        else if (a[mid] < x)
            low = mid + 1;
        else if (a[mid] == x && (mid == 0 || a[mid - 1] < x))
            return mid;
        else
            high = mid - 1;
    }

    return -1;
}

int findLastOccurrence(vector<int> &a, int x)
{
    int n = a.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {

        int mid = (low + high) / 2;

        if (a[mid] > x)
            high = mid - 1;
        else if (a[mid] < x)
            low = mid + 1;
        else if (a[mid] == x && (mid == n - 1 || a[mid + 1] > x))
            return mid;
        else
            low = mid + 1;
    }

    return -1;
}

int main()
{
    vector<int> a = {1, 3, 5, 5, 5, 5, 67, 123, 125};

    int x = 5;

    cout << findFirstOccurrence(a, x) << endl;
    cout << findLastOccurrence(a, x) << endl;

    return 0;
}