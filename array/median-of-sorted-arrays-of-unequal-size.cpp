#include <algorithm>
#include <iostream>
#include <limits.h>
using namespace std;

// Function to find the median of two sorted arrays of unequal sizes
double getMedian(int arr1[], int m, int arr2[], int n)
{
    // Ensure that arr1 is the smaller array
    if (m > n)
    {
        swap(arr1, arr2);
        swap(m, n);
    }

    int low = 0, high = m; // Initialize binary search range for the smaller array

    while (low <= high)
    {

        // Partitioning: At each iteration of the binary search, the algorithm calculates partition indices partition1 and partition2. These partitions divide the arrays into two parts such that:
        // arr1[0..partition1-1] and arr2[0..partition2-1] are on the left side.
        // arr1[partition1..m-1] and arr2[partition2..n-1] are on the right side.
        int partition1 = (low + high) / 2;
        int partition2 = (m + n + 1) / 2 - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : arr1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : arr2[partition2];

        // Check if all numbers on the left is less that all the numbers to on the right. For that, the following conditions must be satisfied:
        // maxLeft1 <= minRight2 and maxLeft2 <= minRight1.
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1)
        {
            if ((m + n) % 2 == 0)
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            else
                return max(maxLeft1, maxLeft2);
        }
        // Adjust partition: If the current partitions don't satisfy the conditions, the algorithm adjusts the partition by moving partition1 to the left or right, depending on the comparison of maxLeft1 and minRight2.
        else if (maxLeft1 > minRight2)
        {
            high = partition1 - 1; // Move next partition1 to the left
        }
        else
        {
            low = partition1 + 1; // Move next partition1 to the right
        }
    }

    throw runtime_error("Input arrays are not sorted or contain duplicate elements.");
}

int main()
{
    int arr1[] = {-5, 3, 6, 12, 15};
    int m = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {-12, -10, -6, -3, 4, 10};
    int n = sizeof(arr2) / sizeof(arr2[0]);

    double median = getMedian(arr1, m, arr2, n);

    cout << "Median is " << median << endl;

    return 0;
}
