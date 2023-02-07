#include <bits/stdc++.h>
using namespace std;

void findFirstAndLastOccurrence(vector<int> &v, int l, int r, int elem, int &firstIndex, int &lastIndex)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (v[mid] == elem)
        {
            if (mid == 0 || v[mid - 1] < elem)
                firstIndex = mid;
            else
                findFirstAndLastOccurrence(v, l, mid - 1, elem, firstIndex, lastIndex);
            if (mid == v.size() || v[mid + 1] > elem)
                lastIndex = mid;
            else
                findFirstAndLastOccurrence(v, mid + 1, r, elem, firstIndex, lastIndex);
        }

        if (v[mid] > elem)
            return findFirstAndLastOccurrence(v, l, mid - 1, elem, firstIndex, lastIndex);

        return findFirstAndLastOccurrence(v, mid + 1, r, elem, firstIndex, lastIndex);
    }
}

int main()
{

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int elem;
    cin >> elem;

    int firstIndex = -1;
    int lastIndex = -1;
    findFirstAndLastOccurrence(a, 0, a.size() - 1, elem, firstIndex, lastIndex);

    cout << firstIndex << " " << lastIndex << endl;

    return 0;
}