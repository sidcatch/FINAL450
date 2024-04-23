#include <bits/stdc++.h>
using namespace std;

const int N = 4;

void printGrid(bool graph[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isGraphColored(int &n, unordered_map<int, int> &nodeColors)
{

    for (int i = 0; i < N; i++)
        if (nodeColors.find(i) == nodeColors.end())
        {
            n = i;
            return false;
        }

    return true;
}

bool isValid(bool graph[N][N], int n, int m, unordered_map<int, int> &nodeColors)
{

    if (nodeColors.find(n) != nodeColors.end())
        return false;

    for (int i = 0; i < N; i++)
    {
        if (!graph[n][i])
            continue;

        if (nodeColors.find(i) == nodeColors.end())
            continue;

        if (nodeColors[i] != m)
            return false;
    }

    return true;
}

bool graphColoring(bool graph[N][N], int m, unordered_map<int, int> &nodeColors)
{
    int n;

    if (isGraphColored(n, nodeColors))
        return true;

    for (int i = 0; i < m; i++)
    {
        if (
            isValid(graph, n, m, nodeColors))
        {
            nodeColors[n] = i;
            if (graphColoring(graph, m, nodeColors))
                return true;

            nodeColors.erase(n);
        }
    }

    return false;
}

int main()
{
    bool graph[N][N] =
        {{0, 1, 1, 1},
         {1, 0, 1, 0},
         {1, 1, 0, 1},
         {1, 0, 1, 0}};

    printGrid(graph);

    int m = 3;

    unordered_map<int, int> nodeColors;

    cout << (graphColoring(graph, m, nodeColors) ? "Yes" : "No");

    cout << endl;

    return 0;
}
