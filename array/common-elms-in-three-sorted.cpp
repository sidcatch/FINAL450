#include <bits/stdc++.h>
using namespace std;

// This function prints common elements in ar1
void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
    // Initialize starting indexes for ar1[], ar2[] and
    // ar3[]
    int i = 0, j = 0, k = 0;

    // Iterate through three arrays while all arrays have
    // elements
    while (i < n1 && j < n2 && k < n3)
    {
        // If x = y and y = z, print any of them and move
        // ahead in all arrays
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
        {
            cout << ar1[i] << " ";
            i++;
            j++;
            k++;
        }

        // x < y
        else if (ar1[i] < ar2[j])
            i++;

        // y < z
        else if (ar2[j] < ar3[k])
            j++;

        // We reach here when x > y and z < y, i.e., z is
        // smallest
        else
            k++;

        //Dealing with duplicates without using any additional data structure
        if (i > 0)
        {
            int p = ar1[i - 1];
            while (ar1[i] == p && i < n1)
                i++;
        }
        if (j > 0)
        {
            int p = ar2[j - 1];
            while (ar2[j] == p && j < n2)
                j++;
        }
        if (k > 0)
        {
            int p = ar3[k - 1];
            while (ar3[k] == p && k < n3)
                k++;
        }
    }
}

// Driver code
int main()
{
    int ar1[] = {1, 5, 10, 20, 20, 40, 80};
    int ar2[] = {6, 7, 20, 20, 80, 100};
    int ar3[] = {3, 4, 15, 20, 20, 30, 70, 80, 120};
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    int n3 = sizeof(ar3) / sizeof(ar3[0]);

    cout << "Common Elements are ";
    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}
