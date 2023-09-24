#include <algorithm>
#include <iostream>
#include <vector>
#define N 3

using namespace std;

//Check if this is correct!
int minCashFlow(int graph[N][N])
{
    vector<int> credits(N, 0);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            //Switching signs here won't effect the answer!
            credits[i] -= graph[i][j];
            credits[j] += graph[i][j];
        }

    sort(credits.begin(), credits.end());

    int i = 0;
    int j = N - 1;
    int cashFlow = 0;

    while (i < j)
    {

        if (credits[i] == 0)
        {
            i++;
            continue;
        }

        if (credits[j] == 0)
        {
            j--;
            continue;
        }

        if (credits[i] > 0 || credits[j] < 0)
            break;

        const int left = credits[i] + credits[j];

        if (left == 0)
        {
            cashFlow += credits[j];
            i++;
            j--;
            continue;
        }

        if (left > 0)
        {
            cashFlow += abs(credits[i]);
            credits[j] = left;
            i++;
            continue;
        }

        if (left < 0)
        {
            cashFlow += credits[j];
            credits[i] = left;
            j--;
        }
    }

    return cashFlow;
}

int main()
{
    // graph[i][j] indicates the amount that person i needs
    // to pay person j
    // int graph[N][N] = {
    //     {0, 1000, 2000},
    //     {0, 0, 5000},
    //     {0, 0, 0},
    // };

    int graph[N][N] = {
        {0, 1000, 2000},
        {0, 0, 5000},
        {1000, 0, 0},
    };

    cout << minCashFlow(graph) << endl;
    return 0;
}