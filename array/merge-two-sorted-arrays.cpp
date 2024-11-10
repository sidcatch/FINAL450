#include <algorithm> // For max function
#include <iostream>

using namespace std;

// Function to merge two arrays
void mergeArray(int a[], int b[], int m, int n)
{
    // Find maximum element of both arrays
    int mx = max(a[m - 1], b[n - 1]);

    // Increment by one to avoid collision of 0 and maximum element of array in modulo operation
    mx++;

    int i = 0, j = 0, k = 0;
    // Merge arrays while elements are present in both arrays
    while (i < m && j < n && k < (m + n))
    {
        // Recover back original element to compare
        int e1 = a[i] % mx;
        int e2 = b[j] % mx;

        // Compare and update elements
        if (e1 <= e2)
        {
            if (k < m)
                a[k] += (e1 * mx);
            else
                b[k - m] += (e1 * mx);
            i++;
            k++;
        }
        else
        {
            if (k < m)
                a[k] += (e2 * mx);
            else
                b[k - m] += (e2 * mx);
            j++;
            k++;
        }
    }

    // Process remaining elements in array a
    while (i < m)
    {
        int el = a[i] % mx;
        if (k < m)
            a[k] += (el * mx);
        else
            b[k - m] += (el * mx);
        i++;
        k++;
    }

    // Process remaining elements in array b
    while (j < n)
    {
        int el = b[j] % mx;
        if (k < m)
            a[k] += (el * mx);
        else
            b[k - m] += (el * mx);
        j++;
        k++;
    }

    // Update elements by dividing with maximum element
    for (int i = 0; i < m; i++)
        a[i] /= mx;

    // Update elements by dividing with maximum element
    for (int i = 0; i < n; i++)
        b[i] /= mx;
}

int main()
{
    int a[] = {3, 5, 6, 8, 12};
    int b[] = {1, 4, 9, 13};
    int m = sizeof(a) / sizeof(int);
    int n = sizeof(b) / sizeof(int);

    mergeArray(a, b, m, n);

    cout << "First array : ";
    for (int i = 0; i < m; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Second array : ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}
