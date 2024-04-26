#include <iostream>
#include <vector>

using namespace std;

void printBoard(vector<vector<bool>> &board)
{
    int n = board.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValid(vector<vector<bool>> &visited, int i, int j)
{
    int n = visited.size();

    if (i >= 0 && j >= 0 && i < n && j < n && !visited[i][j])
        return true;

    return false;
}

bool knightsTour(vector<vector<bool>> &visited, int i, int j, vector<int> &path)
{

    static vector<vector<int>> displacements = {{1, 2}, {2, 1}, {-1, 2}, {2, -1}, {1, -2}, {-2, 1}, {-1, -2}, {-2, -1}};

    int n = visited.size();

    if (path.size() == n * n - 1) // Wrong!
    {
        for (int position : path)
            cout << position << " ";
        cout << endl;
        return true;
    }

    for (vector<int> displacement : displacements)
    {
        int x = i + displacement[0];
        int y = j + displacement[1];

        if (isValid(visited, x, y))
        {
            path.push_back((y * n) + x);
            visited[x][y] = true;

            if (knightsTour(visited, x, y, path))
                return true;

            path.pop_back();
            visited[x][y] = false;
        }
    }

    return false;
}

int main()
{
    int n = 8;

    vector<vector<bool>> board(n, vector<bool>(n, false));

    vector<int> path = {0};

    board[0][0] = true;

    printBoard(board);

    knightsTour(board, 0, 0, path);

    return 0;
}