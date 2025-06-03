#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

/*  O(n)  – returns the optimal jump indexes, or {} if unreachable  */
vector<int> minJumpPath(const vector<int> &arr)
{
    int n = arr.size();
    if (n == 0)
        return {};
    if (n == 1)
        return {0};
    if (arr[0] == 0)
        return {}; // stuck at start

    int farthest = 0;       // furthest reach discovered so far
    int currEnd = 0;        // end of the current BFS layer
    int bestInLayer = 0;    // index inside layer that makes farthest reach
    vector<int> path = {0}; // always start at index 0

    for (int i = 0; i < n - 1; ++i)
    {
        if (i + arr[i] > farthest)
        { // extend reach
            farthest = i + arr[i];
            bestInLayer = i;
        }

        if (i == currEnd)
        {                                    // layer exhausted
            if (currEnd != 0)                // **skip the very first "jump" from 0 to 0**
                path.push_back(bestInLayer); // real jump starts here

            currEnd = farthest; // next layer span

            if (currEnd >= n - 1)
            {                          // we can finish now
                path.push_back(n - 1); // land on the last index
                return path;
            }
        }
    }
    return {}; // never reached the end
}

int main()
{
    vector<int> arr = {2, 3, 1, 1, 4};

    vector<int> path = minJumpPath(arr);

    if (path.empty())
    {
        cout << "The last index is unreachable.\n";
    }
    else
    {
        cout << "Jump indexes: ";
        for (size_t i = 0; i < path.size(); ++i)
            cout << path[i] << (i + 1 == path.size() ? '\n' : ' ');

        cout << "Minimum number of jumps: " << path.size() - 1 << '\n';
    }
    return 0;
}
