#include <climits>
#include <iostream>
#include <queue>
#include <vector>

#define N 4

using namespace std;

struct MinHeapNode
{
    int element;
    int i;
    int j;
};

struct CompareNode
{
    bool operator()(const MinHeapNode &a, const MinHeapNode &b)
    {
        return a.element > b.element;
    }
};

vector<int> mergeKArrays(int arr[][N], int K)
{
    vector<int> output;
    priority_queue<MinHeapNode, vector<MinHeapNode>, CompareNode> pq;

    for (int i = 0; i < K; ++i)
    {
        pq.push({arr[i][0], i, 0});
    }

    while (!pq.empty())
    {
        MinHeapNode root = pq.top();
        pq.pop();

        output.push_back(root.element);

        if (root.j < N - 1)
        {
            pq.push({arr[root.i][root.j + 1], root.i, root.j + 1});
        }
    }

    return output;
}

void printArray(const vector<int> &arr)
{
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
}

int main()
{
    int arr[][N] = {{2, 6, 12, 34},
                    {1, 9, 20, 1000},
                    {23, 34, 90, 2000}};
    int K = sizeof(arr) / sizeof(arr[0]);

    vector<int> output = mergeKArrays(arr, K);

    cout << "Merged array is" << endl;
    printArray(output);

    return 0;
}
