#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> grid =
        {{0, 1, 2},
         {0, 1, 2},
         {2, 1, 1}};

    vector<vector<int>> offsets = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    queue<vector<int>> rottenQueue;

    for (int i = 0; i < grid.size(); i++)
        for (int j = 0; j < grid[0].size(); j++)
            if (grid[i][j] == 2)
                rottenQueue.push({i, j, 0});

    int generation = 0;
    while (!rottenQueue.empty())
    {
        vector<int> cell = rottenQueue.front();
        rottenQueue.pop();

        for (vector<int> offset : offsets)
        {
            int x = cell[0] + offset[0];
            int y = cell[1] + offset[1];
            if (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1)
            {
                grid[x][y] = 2;
                rottenQueue.push({x, y, cell[2] + 1});
                generation = cell[2] + 1;
            }
        }
    }

    cout << generation << endl;

    return 0;
}