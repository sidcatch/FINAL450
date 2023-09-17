#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int minCost(int a[], int n)
{

    priority_queue<int, vector<int>, greater<int>> minHeap(a, a + n);

    int currTotalCost = 0;

    while (minHeap.size() > 1)
    {
        int x = minHeap.top();
        minHeap.pop();
        int y = minHeap.top();
        minHeap.pop();
        int cost = x + y;

        currTotalCost += cost;

        minHeap.push(cost);
    }

    return currTotalCost;
}

int main()
{
    int n = 5;
    int arr[] = {4, 2, 7, 6, 9};
    cout << minCost(arr, n);
    return 0;
}