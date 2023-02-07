// In a candy store, there are N different types of candies available and the prices of all the N different types of candies are provided to you.
// You are now provided with an attractive offer.
// You can buy a single candy from the store and get at most K other candies ( all are different types ) for free.
// Now you have to answer two questions. Firstly, you have to find what is the minimum amount of money you have to spend to buy all the N different candies. Secondly, you have to find what is the maximum amount of money you have to spend to buy all the N different candies.
// In both the cases you must utilize the offer i.e. you buy one candy and get K other candies for free.

#include <algorithm>
#include <iostream>

using namespace std;

int findMinimumAmount(int a[], int n, int k)
{
    int amount = 0;

    for (int i = 0; i < n; i++)
    {
        amount += a[i];

        n -= k;
    }

    return amount;
}

int findMaximumAmount(int a[], int n, int k)
{
    int amount = 0;
    int start = 0;

    for (int i = n; i > start; i--)
    {
        amount += a[i];

        start += k;
    }

    return amount;
}

int main()
{
    int arr[] = {3, 2, 1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    sort(arr, arr + n);

    cout
        << findMinimumAmount(arr, n, k) << " "
        << findMaximumAmount(arr, n, k) << endl;

    return 0;
}