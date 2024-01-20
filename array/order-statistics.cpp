#include <bits/stdc++.h>
using namespace std;

int findMedian(int a[], int n)
{
    sort(a, a + n);

    return a[n / 2];
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int l, int r, int x)
{

    int i;

    for (i = l; i <= r; i++)
        if (a[i] == x)
            break;

    swap(&a[i], &a[r]);

    i = l;

    for (int j = l; j < r; j++)
    {
        if (a[j] <= x) // if (a[j] >= x), for kthLargest
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[r]);

    return i;
}

int kthSmallest(int a[], int l, int r, int k)
{
    int n = r - l + 1;

    if (k > 0 && k <= n)
    {
        int medians[(n + 4) / 5];

        int i;
        for (i = 0; i < n / 5; i++)
            medians[i] = findMedian(a + l + i * 5, 5);

        if (i * 5 < n)
        {
            medians[i] = findMedian(a + l + i * 5, n % 5);
            i++;
        }

        int medOfMedians = (i == 1) ? medians[i - 1] : kthSmallest(medians, 0, i - 1, i / 2);
        // int medOfMedians;
        // if (i == 1)
        //     medOfMedians = medians[0];
        // else if (i % 2 == 0)
        //     medOfMedians = findMedian(medians, i - 1);
        // else
        //     medOfMedians = findMedian(medians, i);

        int pos = partition(a, l, r, medOfMedians);

        int relativePos = pos - l + 1;

        if (k == relativePos)
            return a[pos];

        if (k < relativePos)
            return kthSmallest(a, l, pos - 1, k);

        if (k > relativePos)
            return kthSmallest(a, pos + 1, r, k - relativePos);
    }

    return INT_MAX;
}

int main()
{

    int arr[] = {7, 10, 4, 3, 20, 15};
    int size = 5;
    int k = 3;
    // int arr[] = {7, 10, 4, 3, 20, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 63, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 2, 53, 54, 565, 56, 5, 758, 59, 60, 61, 62, 36, 64, 65, 66, 67, 68, 69, 70, 71, 2772, 73, 74, 75, 86, 7, 7, 78, 7, 980, 81, 82, 8, 384, 58, 8, 687, 88, 89, 9, 291, 92, 93, 94, 95, 96, 97, 98, 999};
    // int size = 90;
    // int k = 80;

    // int arr[] = {7, 10};
    // int size = 2;
    // int k = 1;

    cout << kthSmallest(arr, 0, size, k);

    cout << endl;

    return 0;
}