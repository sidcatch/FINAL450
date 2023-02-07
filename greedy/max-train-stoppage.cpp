// We are given n-platform and two main running railway track for both direction. Trains which needs to stop at your station must occupy one platform for their stoppage and the trains which need not to stop at your station will run away through either of main track without stopping. Now, each train has three value first arrival time, second departure time and third required platform number. We are given m such trains you have to tell maximum number of train for which you can provide stoppage at your station.

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

const int n = 5;

bool compareByDepartureTime(vector<int> &a, vector<int> &b)
{
    // cout << " " << a[1] << " " << b[1];
    return a[1] <= b[1];
}

int maxTrainsCanStop(int trains[n][3])
{
    unordered_map<int, vector<vector<int>>> trainsByPlatform;

    for (int i = 0; i < n; i++)
        trainsByPlatform[trains[i][2]].push_back({trains[i][0], trains[i][1]});

    //Note: type reference is important here, otherwise sort will happen on a copy!
    for (auto &t : trainsByPlatform)
        sort(t.second.begin(), t.second.end(), compareByDepartureTime);

    int ans = 0;
    for (auto &t : trainsByPlatform)
    {
        int lastTrainDepaturetime = -1;
        for (auto &train : t.second)
            if (train[0] >= lastTrainDepaturetime)
            {
                ans++;
                lastTrainDepaturetime = train[1];
            }
    }

    return ans;
}

int main()
{

    int trains[n][3] = {{1000, 1030, 1},
                        {1010, 1020, 1},
                        {1025, 1040, 1},
                        {1130, 1145, 2},
                        {1130, 1140, 2}};

    cout << "Maximum Stopped Trains = "
         << maxTrainsCanStop(trains) << endl;
    return 0;
}