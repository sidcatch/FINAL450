#include <iostream>
#include <string>

using namespace std;

const int SIZE = 4;

void dfs(int m[][SIZE], int n, int i, int j, string path)
{
    if (i < 0 || i >= n || j < 0 || j >= n || m[i][j] != 1)
        return;

    if (i == n - 1 && j == n - 1)
    {
        cout << path << endl;
        return;
    }

    m[i][j] = -1;

    dfs(m, n, i, j - 1, path + "L");
    dfs(m, n, i, j + 1, path + "R");
    dfs(m, n, i - 1, j, path + "U");
    dfs(m, n, i + 1, j, path + "D");

    m[i][j] = 1;
}

int main()
{
    int n = SIZE;
    int m[][SIZE] = {{1, 0, 0, 0},
                     {1, 1, 1, 1},
                     {1, 1, 0, 1},
                     {0, 1, 1, 1}};

    dfs(m, n, 0, 0, "");

    return 0;
}
