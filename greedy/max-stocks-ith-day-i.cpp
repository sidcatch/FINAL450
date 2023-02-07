// In a stock market, there is a product with its infinite stocks. The stock prices are given for N days, where arr[i] denotes the price of the stock on the ith day. There is a rule that a customer can buy at most i stock on the ith day. If the customer has k amount of money initially, find out the maximum number of stocks a customer can buy.
// For example, for 3 days the price of a stock is given as 7, 10, 4. You can buy 1 stock worth 7 rs on day 1, 2 stocks worth 10 rs each on day 2 and 3 stock worth 4 rs each on day 3.

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

bool lessPrice(pair<int, int> &lhs, pair<int, int> &rhs)
{

    if (lhs.first < rhs.first)
        return true;
    else if (lhs.first > rhs.first)
        return false;
    else
        return lhs.second >= rhs.second;
}

int maxNumOfBuys(int n, int k, int prices[])
{

    vector<pair<int, int>> pricesWithBuyLimit;

    for (int i = 0; i < n; i++)
        pricesWithBuyLimit.push_back(make_pair(prices[i], i + 1));

    sort(pricesWithBuyLimit.begin(), pricesWithBuyLimit.end(), lessPrice);

    int remainingAmount = k, totalNumOfBuys = 0;
    for (auto &priceWithBuyLimit : pricesWithBuyLimit)
    {
        int numOfBuys = min(priceWithBuyLimit.second, remainingAmount / priceWithBuyLimit.first);

        totalNumOfBuys += numOfBuys;

        remainingAmount -= numOfBuys * priceWithBuyLimit.first;
    }

    return totalNumOfBuys;
}

int main()
{
    int prices[] = {10, 7, 19};
    int n = sizeof(prices) / sizeof(prices[0]);
    int k = 45;

    cout << maxNumOfBuys(n, k, prices) << endl;

    return 0;
}