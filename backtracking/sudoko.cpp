#include <bits/stdc++.h>
using namespace std;

const int N = 9;

void printGrid(int grid[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void init(int grid[N][N], unordered_set<int> colNums[N], unordered_set<int> rowNums[N], unordered_set<int> subBoxNums[3][3])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            if (grid[i][j] != 0)
            {
                colNums[j].insert(grid[i][j]);
                rowNums[i].insert(grid[i][j]);
                subBoxNums[i / 3][j / 3].insert(grid[i][j]);
            }
        }
    }
}

void fill(int grid[N][N], int n, int col, int row, unordered_set<int> colNums[N], unordered_set<int> rowNums[N], unordered_set<int> subBoxNums[3][3])
{
    grid[row][col] = n;
    colNums[col].insert(n);
    rowNums[row].insert(n);
    subBoxNums[row / 3][col / 3].insert(n);
}

void erase(int grid[N][N], int n, int col, int row, unordered_set<int> colNums[N], unordered_set<int> rowNums[N], unordered_set<int> subBoxNums[3][3])
{
    grid[row][col] = 0;
    colNums[col].erase(n);
    rowNums[row].erase(n);
    subBoxNums[row / 3][col / 3].erase(n);
}

bool isValid(int grid[N][N], int n, int col, int row, unordered_set<int> colNums[N], unordered_set<int> rowNums[N], unordered_set<int> subBoxNums[3][3])
{
    return grid[row][col] == 0 && colNums[col].find(n) == colNums[col].end() && rowNums[row].find(n) == rowNums[row].end() && subBoxNums[row / 3][col / 3].find(n) == subBoxNums[row / 3][col / 3].end();
}

bool findFreeLocation(int grid[N][N], int &col, int &row)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;

    return false;
}

bool solveSudoko(int grid[N][N], unordered_set<int> colNums[N], unordered_set<int> rowNums[N], unordered_set<int> subBoxNums[3][3])
{

    int row, col;

    if (!findFreeLocation(grid, col, row))
        return true;

    for (int i = 1; i <= N; i++)
    {
        if (isValid(grid, i, col, row, colNums, rowNums, subBoxNums))
        {
            fill(grid, i, col, row, colNums, rowNums, subBoxNums);
            if (solveSudoko(grid, colNums, rowNums, subBoxNums))
                return true;
            erase(grid, i, col, row, colNums, rowNums, subBoxNums);
        }
    }

    return false;
}

int main()
{
    int grid[N][N] =
        {{3, 0, 6, 5, 0, 8, 4, 0, 0},
         {5, 2, 0, 0, 0, 0, 0, 0, 0},
         {0, 8, 7, 0, 0, 0, 0, 3, 1},
         {0, 0, 3, 0, 1, 0, 0, 8, 0},
         {9, 0, 0, 8, 6, 3, 0, 0, 5},
         {0, 5, 0, 0, 9, 0, 6, 0, 0},
         {1, 3, 0, 0, 0, 0, 2, 5, 0},
         {0, 0, 0, 0, 0, 0, 0, 7, 4},
         {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    printGrid(grid);

    unordered_set<int> colNums[N];
    unordered_set<int> rowNums[N];
    unordered_set<int> subBoxNums[3][3];

    init(grid, colNums, rowNums, subBoxNums);

    solveSudoko(grid, colNums, rowNums, subBoxNums);

    printGrid(grid);

    cout << endl;

    return 0;
}
