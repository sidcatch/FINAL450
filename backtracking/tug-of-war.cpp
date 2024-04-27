#include <iostream>
#include <vector>

using namespace std;

void divideForTugOfWar(vector<int> &arr, int i, vector<int> &group1)
{
    static int n = arr.size();

    static int groupSize = n / 2;

    if (i > n - 1)
    {
        if (group1.size() == groupSize)
        {
            for (int num : group1)
            {
                cout << num << " ";
            }
            cout << endl;
        }

        return;
    }

    if ((groupSize - group1.size()) > (n - i))
        return;

    if (group1.size() < groupSize)
    {
        group1.push_back(arr[i]);
        divideForTugOfWar(arr, i + 1, group1);
        group1.pop_back();
    }

    divideForTugOfWar(arr, i + 1, group1);
}

int main()
{

    vector<int> arr = {3, 4, 5, -3, 100, 1, 89, 54, 23, 20};

    vector<int> group;

    divideForTugOfWar(arr, 0, group);

    return 0;
}