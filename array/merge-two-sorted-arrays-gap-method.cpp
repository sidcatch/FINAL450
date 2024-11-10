// Merge two sorted arrays a[] and b[] with O(1) extra space.
// using Gap method of shell sort
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void mergeArrays(vector<int> &a, vector<int> &b)
{
    int m = a.size();
    int n = b.size();
    int gap = (m + n) / 2;

    while (gap > 0)
    {
        int i = 0, j = gap;

        while (j < m + n)
        {

            // If both pointers are in the first array a[]
            if (j < m && a[i] > a[j])
            {
                swap(a[i], a[j]);
            }

            // If first pointer is in a[] and
            // the second pointer is in b[]
            else if (i < m && j >= m && a[i] > b[j - m])
            {
                swap(a[i], b[j - m]);
            }

            // Both pointers are in the second array b
            else if (i >= m && b[i - m] > b[j - m])
            {
                swap(b[i - m], b[j - m]);
            }
            i++;
            j++;
        }

        // Calculate the next gap
        gap = (gap) / 2;
    }
}

int main()
{
    vector<int> a = {1, 5, 9, 10, 15, 20};
    vector<int> b = {2, 3, 8, 13};
    mergeArrays(a, b);

    for (int ele : a)
        cout << ele << " ";
    cout << "\n";
    for (int ele : b)
        cout << ele << " ";
    return 0;
}
