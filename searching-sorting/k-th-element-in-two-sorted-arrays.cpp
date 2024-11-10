#include <algorithm>
#include <climits> // Include this for INT_MAX and INT_MIN
#include <iostream>
#include <vector>

using namespace std;

// See:- array/median-of-sorted-arrays-of-unequal-size.cpp
int findKthElement(const vector<int> &arr1, const vector<int> &arr2, int k)
{
    int n = arr1.size();
    int m = arr2.size();

    // Ensure arr1 is the smaller array
    if (n > m)
        return findKthElement(arr2, arr1, k);

    int low = max(0, k - m);
    int high = min(k, n);

    int totalNumOfElmOnLeft = k;

    while (low <= high)
    {
        int cut1 = (low + high) / 2;
        int cut2 = totalNumOfElmOnLeft - cut1;

        int left1 = (cut1 == 0) ? INT_MIN : arr1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : arr2[cut2 - 1];
        int right1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int right2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (left1 <= right2 && left2 <= right1)
        {
            return max(left1, left2);
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }

    return -1; // This should not happen if k is valid
}

int main()
{
    vector<int> arr1 = {1, 3, 8, 9, 15};
    vector<int> arr2 = {7, 11, 18, 19, 21, 25};
    int k = 5;

    int result = findKthElement(arr1, arr2, k);
    cout << "The " << k << "-th element in the merged sorted array is: " << result << endl;

    return 0;
}
