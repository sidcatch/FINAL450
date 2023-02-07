// Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note: Unlike 0/1 knapsack, you are allowed to break the item.

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

//Proof: let's assume M is the max possible total value that can be put in the knapsack.
//If there is no part of the most valuable item in it then we can replace replace the max value item part in the knapsack with the part of the most valuable item.
//That would increase the max possible total value in the knapsack.
//Hence by contradiction there should be some part of the most valuable item in the knapsack.

bool comp(vector<int> a, vector<int> b)
{
    return ((a[0] / a[1]) > (b[0] / b[1]));
}

int main()
{
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int n = 3, W = 50;

    vector<vector<int>> items;

    for (int i = 0; i < n; i++)
        items.push_back({values[i], weights[i]});

    sort(items.begin(), items.end(), comp);

    int knapsackCapacityLeft = W;
    int valueInKnapsack = 0;

    for (int i = 0; i < n; i++)
    {

        if (items[i][1] <= knapsackCapacityLeft)
        {
            valueInKnapsack += items[i][0];
            knapsackCapacityLeft -= items[i][1];
        }
        else
        {
            valueInKnapsack += items[i][0] / items[i][1] * knapsackCapacityLeft;
            // knapsackCapacityLeft = 0;
            break;
        }
    }

    cout << valueInKnapsack << endl;

    return 0;
}
