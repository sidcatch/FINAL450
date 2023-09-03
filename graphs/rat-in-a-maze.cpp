#include <iostream>
#include <string>
using namespace std;

const string UP = "U";
const string DOWN = "D";
const string LEFT = "L";
const string RIGHT = "R";

void dfs(int m[][4], int n, int i, int j, string path)
{

    m[i][j] = -1;

    if (i == n - 1 && j == n - 1)
        cout << path << endl;

    if (j > 0 && m[i][j - 1] == 1)
        dfs(m, n, i, j - 1, path + LEFT);
    if (j < n - 1 && m[i][j + 1] == 1)
        dfs(m, n, i, j + 1, path + RIGHT);
    if (i > 0 && m[i - 1][j] == 1)
        dfs(m, n, i - 1, j, path + UP);
    if (i < n - 1 && m[i + 1][j] == 1)
        dfs(m, n, i + 1, j, path + DOWN);

    m[i][j] = 1;
}

int main()
{
    int n = 4;
    int m[][4] = {{1, 0, 0, 0},
                  {1, 1, 0, 1},
                  {1, 1, 0, 0},
                  {0, 1, 1, 1}};
    int visited[][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };

    string path = "";
    int i = 0, j = 0;

    dfs(m, n, i, j, path);

    return 0;
}