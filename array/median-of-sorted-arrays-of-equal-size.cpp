#include <algorithm>
#include <iostream>
using namespace std;

// Function to find the median of two sorted arrays
double getMedian(int arr1[], int arr2[], int n)
{
    // Find the maximum and minimum elements in both arrays
    int maxElement = max(arr1[n - 1], arr2[n - 1]);
    int minElement = min(arr1[0], arr2[0]);

    int pos = n; // Position to find the median
    double median = 0.0;

    // Binary search within the range of minElement to maxElement
    while (minElement <= maxElement)
    {
        int mid = minElement + (maxElement - minElement) / 2;

        // Count the total number of elements in arrays which are less than mid
        int count1 = upper_bound(arr1, arr1 + n, mid) - arr1;
        int count2 = upper_bound(arr2, arr2 + n, mid) - arr2;
        int totalElementsLessThanMid = count1 + count2;

        if (totalElementsLessThanMid <= pos)
            minElement = mid + 1;
        else
            maxElement = mid - 1;
    }

    median = minElement;

    // As there are even number of elements, we will also have to find element
    // at pos = totalLen/2 - 1
    pos--;
    minElement = min(arr1[0], arr2[0]);
    maxElement = max(arr1[n - 1], arr2[n - 1]);

    while (minElement <= maxElement)
    {
        int mid = minElement + (maxElement - minElement) / 2;

        // Count the total number of elements in arrays which are less than mid
        int count1 = upper_bound(arr1, arr1 + n, mid) - arr1;
        int count2 = upper_bound(arr2, arr2 + n, mid) - arr2;
        int totalElementsLessThanMid = count1 + count2;

        if (totalElementsLessThanMid <= pos)
            minElement = mid + 1;
        else
            maxElement = mid - 1;
    }

    // Calculate the average of two elements in case of an even number of elements
    median = (median + minElement) / 2.0;

    return median;
}

int main()
{
    int arr1[] = {1, 4, 5, 6, 10};
    int arr2[] = {2, 3, 4, 5, 7};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    double median = getMedian(arr1, arr2, n);

    cout << "Median is " << median << endl;

    return 0;
}
