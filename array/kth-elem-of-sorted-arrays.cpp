#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;

// Function to find the k-th smallest element (1-based) in two sorted arrays of possibly unequal sizes
int getKthElement(int arr1[], int m, int arr2[], int n, int k)
{
    // Validate k
    if (k < 1 || k > m + n)
        throw runtime_error("k is out of range for the combined arrays.");

    // Ensure that arr1 is the smaller array to keep the binary search tight
    if (m > n)
    {
        swap(arr1, arr2);
        swap(m, n);
    }

    // Binary search range for how many elements we take from arr1 into the left half.
    // We must take between max(0, k - n) and min(k, m) from arr1.
    int low = max(0, k - n);
    int high = min(k, m);

    while (low <= high)
    {
        // Partitioning: choose partition1 elements from arr1 and partition2 = k - partition1 from arr2
        // so that exactly k elements lie on the "left side" combined.
        int partition1 = (low + high) / 2;
        int partition2 = k - partition1;

        // Borders for arr1
        int maxLeft1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : arr1[partition1];

        // Borders for arr2
        int maxLeft2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : arr2[partition2];

        // Valid partition when every element on the left is <= every element on the right
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        {
            // The k-th smallest is simply the maximum element from the left sides
            return max(maxLeft1, maxLeft2);
        }
        // If we took too many from arr1, shift left
        else if (maxLeft1 > minRight2)
        {
            high = partition1 - 1;
        }
        // If we took too few from arr1, shift right
        else
        {
            low = partition1 + 1;
        }
    }

    // If we reach here, inputs likely weren't sorted.
    throw runtime_error("Input arrays must be sorted.");
}

int main()
{
    int arr1[] = {2, 3, 4, 10, 15};
    int m = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {1, 5, 8, 12, 14, 18};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    // Try a few ks
    for (int k = 1; k <= m + n; ++k)
    {
        cout << "k = " << k << " -> " << getKthElement(arr1, m, arr2, n, k) << '\n';
    }

    return 0;
}
