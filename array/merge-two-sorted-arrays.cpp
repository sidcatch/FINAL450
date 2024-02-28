#include <algorithm> // For max function
#include <iostream>

using namespace std;

// Function to merge two arrays
void mergeArray(int a[], int b[], int n, int m)
{
    // Find maximum element of both arrays
    int mx = max(a[n - 1], b[m - 1]);

    // Increment by one to avoid collision of 0 and maximum element of array in modulo operation
    mx++;

    int i = 0, j = 0, k = 0;
    // Merge arrays while elements are present in both arrays
    while (i < n && j < m && k < (n + m))
    {
        // Recover back original element to compare
        int e1 = a[i] % mx;
        int e2 = b[j] % mx;

        // Compare and update elements
        if (e1 <= e2)
        {
            if (k < n)
                a[k] += (e1 * mx);
            else
                b[k - n] += (e1 * mx);
            i++;
            k++;
        }
        else
        {
            if (k < n)
                a[k] += (e2 * mx);
            else
                b[k - n] += (e2 * mx);
            j++;
            k++;
        }
    }

    // Process remaining elements in array a
    while (i < n)
    {
        int el = a[i] % mx;
        if (k < n)
            a[k] += (el * mx);
        else
            b[k - n] += (el * mx);
        i++;
        k++;
    }

    // Process remaining elements in array b
    while (j < m)
    {
        int el = b[j] % mx;
        if (k < n)
            a[k] += (el * mx);
        else
            b[k - n] += (el * mx);
        j++;
        k++;
    }

    // Update elements by dividing with maximum element
    for (int i = 0; i < n; i++)
        a[i] /= mx;

    // Update elements by dividing with maximum element
    for (int i = 0; i < m; i++)
        b[i] /= mx;
}

int main()
{
    int a[] = {3, 5, 6, 8, 12};
    int b[] = {1, 4, 9, 13};
    int n = sizeof(a) / sizeof(int);
    int m = sizeof(b) / sizeof(int);

    mergeArray(a, b, n, m);

    cout << "First array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << "Second array : ";
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}
