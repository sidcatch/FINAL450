#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int a[] = {12, -1, -7, 8, -15, 30, 16, 28};
    int n = sizeof(a) / sizeof(a[0]);
    int k = 1;

    int r[n - k + 1];

    queue<int> negetiveQueue;

    // for (int i = k /* - 1 */; i > 0; i--)
    //     if (a[i] < 0)
    //         negetiveQueue.push(i);

    for (int i = 0; i < k - 1; i++)
        if (a[i] < 0)
            negetiveQueue.push(i);

    for (int i = 0; i <= n - k; i++)
    {

        if (a[i + k - 1] < 0)
            negetiveQueue.push(i + k - 1);

        if (!negetiveQueue.empty())
            r[i] = a[negetiveQueue.front()];
        else
            r[i] = 0;

        if (!negetiveQueue.empty() && negetiveQueue.front() == i)
            negetiveQueue.pop();
    }

    for (int i = 0; i < n - k + 1; i++)
        cout << r[i] << " ";
    cout << endl;

    return 0;
}