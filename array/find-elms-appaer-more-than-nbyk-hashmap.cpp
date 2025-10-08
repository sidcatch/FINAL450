#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void moreThanNdK(const vector<int> &arr, int k)
{
    int n = arr.size();
    if (k < 2)
        return;

    unordered_map<int, int> candidates;

    // 1st pass: find potential candidates
    for (int num : arr)
    {
        if (candidates.count(num))
            candidates[num]++;
        else if (candidates.size() < k - 1)
            candidates[num] = 1;
        else
        {
            for (auto it = candidates.begin(); it != candidates.end();)
                if (--(it->second) == 0)
                    it = candidates.erase(it);
                else
                    ++it;
        }
    }

    // 2nd pass: count actual occurrences
    unordered_map<int, int> actualCount;
    for (int num : arr)
        if (candidates.count(num))
            actualCount[num]++;

    // Print valid results
    for (auto &entry : actualCount)
        if (entry.second > n / k)
            cout << entry.first << " ";

    cout << endl;
}

int main()
{
    vector<int> arr = {3, 1, 2, 2, 1, 2, 3, 3};
    int k = 4;
    moreThanNdK(arr, k);
    return 0;
}
