

#include <bits/stdc++.h>
using namespace std;

int minJumps(int arr[], int n)
{

    if (n <= 1)
        return 0;
    if (arr[0] >= n - 1)
        return 1;
    if (arr[0] == 0)
        return -1;

    int currMaxReach = arr[0];
    int stepsLeft = arr[0];
    int currJump = 1;

    int i = 1;
    for (i = 1; i < n; i++)
    {

        if (i == n - 1)
            return currJump;
        if (arr[i] + 1 >= (n - 1))
            return currJump + 1;

        currMaxReach = max(currMaxReach, i + arr[i]);
        stepsLeft--;

        if (stepsLeft == 0)
        {
            currJump++;
            if (i >= currMaxReach)
                return -1;
            stepsLeft = currMaxReach - i;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {2, 3, 1, 1, 4};

    int size = sizeof(arr) / sizeof(int);

    cout << minJumps(arr, size) << endl;
    return 0;
}
