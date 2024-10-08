#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    if (prices.empty() || prices.size() == 1)
        return 0;

    int minimumSoFar = prices[0];
    int profit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[i] > minimumSoFar)
            profit = max(profit, prices[i] - minimumSoFar);

        if (prices[i] < minimumSoFar)
            minimumSoFar = prices[i];
    }

    cout << profit << endl;

    return 0;
}