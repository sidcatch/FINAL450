#include <iostream>
#include <limits.h>
#include <queue>
#include <vector>
using namespace std;

const int N = 6;

const vector<vector<int>> offsets{{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};

int main()
{

    int dist[N][N]{};

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dist[i][j] = INT_MAX;

    vector<int> knightPos{4, 5, 0};
    vector<int> targetPos{1, 1};

    queue<vector<int>> q;

    q.push(knightPos);

    while (!q.empty())
    {
        vector<int> currPos = q.front();
        q.pop();

        int i = currPos[0], j = currPos[1], d = currPos[2];
        dist[i][j] = d;
        // cout << i << ", " << j << endl;
        if (
            i == targetPos[0] && j == targetPos[1])
        {
            cout << d << endl;
            return 0;
        }

        for (vector<int> offset : offsets)
            if (i + offset[0] >= 0 && i + offset[0] <= N - 1 && j + offset[1] >= 0 && j + offset[1] <= N - 1 && dist[i + offset[0]][j + offset[1]] == INT_MAX)
                q.push({i + offset[0], j + offset[1], d + 1});

        // if (i > 0 && j > 1 && dist[i - 1][j - 2] == INT_MAX)
        //     q.push({i - 1, j - 2, d + 1});
        // if (i > 0 && j < N - 2 && dist[i - 1][j + 2] == INT_MAX)
        //     q.push({i - 1, j + 2, d + 1});
        // if (i < N - 1 && j > 1 && dist[i + 1][j - 2] == INT_MAX)
        //     q.push({i + 1, j - 2, d + 1});
        // if (i < N - 1 && j < N - 2 && dist[i + 1][j + 2] == INT_MAX)
        //     q.push({i + 1, j + 2, d + 1});

        // if (j > 0 && i > 1 && dist[i - 2][j - 1] == INT_MAX)
        //     q.push({i - 2, j - 1, d + 1});
        // if (j > 0 && i < N - 2 && dist[i + 2][j - 1] == INT_MAX)
        //     q.push({i + 2, j - 1, d + 1});
        // if (j < N - 1 && i > 1 && dist[i - 2][j + 1] == INT_MAX)
        //     q.push({i - 2, j + 1, d + 1});
        // if (j < N - 1 && i < N - 2 && dist[i + 2][j + 1] == INT_MAX)
        //     q.push({i + 2, j + 1, d + 1});
    }

    cout << -1 << endl;

    return 0;
}