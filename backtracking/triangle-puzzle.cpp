#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string blue = "Blue";
const string black = "Black";
const string white = "White";
const string yellow = "Yellow";
const string green = "Green";
const string red = "Red";

const char RIGHT = 'R';
const char LEFT = 'L';
const char VERTICAL = 'V';

void init(vector<vector<string>> &gridLeftBorder, vector<vector<string>> &gridRightBorder, vector<vector<string>> &gridBottomBorder, vector<string> &leftBorder, vector<string> &rightBorder, vector<string> &bottomBorder)
{

    int n = gridLeftBorder.size();
    for (int i = 0; i < n; i++)
        gridLeftBorder[i] = {leftBorder[i], leftBorder[i], leftBorder[i]};
    for (int i = 0; i < n; i++)
        gridRightBorder[i] = {rightBorder[i], rightBorder[i], rightBorder[i]};
    for (int i = 0; i < n; i++)
        gridBottomBorder[i] = {bottomBorder[i], bottomBorder[i], bottomBorder[i]};
}

void printTrianglePiece(vector<string> &trianglePiece)
{
    if (trianglePiece.empty())
        cout << "empty" << endl;
    else
        cout << trianglePiece[0] << " " << trianglePiece[1] << " " << trianglePiece[2] << endl;
}

bool findFreeLocation(vector<vector<vector<string>>> &grid, int &row, int &col)
{

    int n = grid.size();

    for (int k = 0; k < n; k++)
    {
        for (int i = k; i < n; i++)
            if (grid[i][k].empty())
            {
                row = i;
                col = k;
                return true;
            }

        for (int j = k + 1; j < n; j++)
            if (grid[k][j].empty())
            {
                row = k;
                col = j;
                return true;
            }
    }

    return false;
}

void traversal(vector<vector<vector<string>>> &grid)
{
    int n = grid.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = k; i < n; i++)
        {
            cout << i << " " << k << endl;
            printTrianglePiece(grid[i][k]);
        }
        for (int j = k + 1; j < n; j++)
        {
            cout << k << " " << j << endl;
            printTrianglePiece(grid[k][j]);
        }
        cout << endl;
    }
}

void traversal2(vector<vector<vector<string>>> &grid)
{

    int n = grid.size();
    for (int k = 0; k < n; k++)
    {
        // cout << k << " " << k << endl;
        printTrianglePiece(grid[k][k]);

        for (int i = k + 1; i < n; i++)
        {
            // cout << k << " " << i << endl;
            printTrianglePiece(grid[k][i]);
            // cout << i << " " << k << endl;
            printTrianglePiece(grid[i][k]);
        }

        cout << endl;
    }
}

vector<int> getAdjPostion(int n, int i, int j, char dir)
{
    if (i > j)
    {
        switch (dir)
        {
        case RIGHT:
            return {j, i};
            break;
        case LEFT:
            if (j == 0)
                return {i}; // Outside of the grid in gridLeftBorder.
            return {j - 1, i};
            break;
        case VERTICAL:
            if (i == n - 1)
                return {j}; // Outside of the grid in gridBottomBorder.
            return {j, i + 1};
            break;
        default:
            return {};
            break;
        }
    }
    else if (i < j)
    {
        switch (dir)
        {
        case RIGHT:
            return {j, i + 1};
            break;
        case LEFT:
            return {j, i};
            break;
        case VERTICAL:
            return {j - 1, i};
            break;
        default:
            return {};
            break;
        }
    }
    else
    {
        switch (dir)
        {
        case RIGHT:
            return {i}; // Outside of the grid in gridRightBorder.
            break;
        case LEFT:
            if (j == 0)
                return {i}; // Outside of the grid in gridLeftBorder.
            return {j - 1, i};
            break;
        case VERTICAL:
            if (i == n - 1)
                return {j}; // Outside of the grid in gridBottomBorder.
            return {j, i + 1};
            break;
        default:
            return {};
            break;
        }
    }
}

vector<string> getAdjTrianglePiece(vector<vector<vector<string>>> &grid, vector<vector<string>> &gridLeftBorder, vector<vector<string>> &gridRightBorder, vector<vector<string>> &gridBottomBorder, int i, int j, char dir)
{
    int n = grid.size();

    vector<int> adjPos = getAdjPostion(n, i, j, dir);

    if (adjPos.size() == 2)
        return grid[adjPos[0]][adjPos[1]];
    else if (adjPos.size() == 1)
    {
        if (dir == LEFT)
            return gridLeftBorder[adjPos[0]];
        if (dir == RIGHT)
            return gridRightBorder[adjPos[0]];
        if (dir == VERTICAL)
            return gridBottomBorder[adjPos[0]];
    }
    // else
    return vector<string>{};
}

bool isValidPlacement(vector<vector<vector<string>>> &grid, vector<vector<string>> &gridLeftBorder, vector<vector<string>> &gridRightBorder, vector<vector<string>> &gridBottomBorder, int i, int j, vector<string> &trianglePiece)
{

    vector<string> leftAdjPiece = getAdjTrianglePiece(grid, gridLeftBorder, gridRightBorder, gridBottomBorder, i, j, LEFT);
    vector<string> rightAdjPiece = getAdjTrianglePiece(grid, gridLeftBorder, gridRightBorder, gridBottomBorder, i, j, RIGHT);
    vector<string> verticalAdjPiece = getAdjTrianglePiece(grid, gridLeftBorder, gridRightBorder, gridBottomBorder, i, j, VERTICAL);

    if (i > j)
    {

        if (!(leftAdjPiece.empty() || leftAdjPiece[1] == trianglePiece[0]))
            return false;
        if (!(rightAdjPiece.empty() || rightAdjPiece[2] == trianglePiece[1]))
            return false;
        if (!(verticalAdjPiece.empty() || verticalAdjPiece[0] == trianglePiece[2]))
            return false;
    }
    else if (i < j)
    {

        if (!(leftAdjPiece.empty() || leftAdjPiece[1] == trianglePiece[2]))
            return false;
        if (!(rightAdjPiece.empty() || rightAdjPiece[0] == trianglePiece[1]))
            return false;
        if (!(verticalAdjPiece.empty() || verticalAdjPiece[2] == trianglePiece[0]))
            return false;
    }
    else
    {
        if (!(leftAdjPiece.empty() || leftAdjPiece[1] == trianglePiece[0]))
            return false;
        if (!(rightAdjPiece.empty() || rightAdjPiece[0] == trianglePiece[1]))
            return false;
        if (!(verticalAdjPiece.empty() || verticalAdjPiece[0] == trianglePiece[2]))
            return false;
    }

    return true;
}

vector<vector<string>> getTrianglePieceRotations(vector<string> &trianglePiece)
{
    return {trianglePiece, {trianglePiece[1], trianglePiece[2], trianglePiece[0]}, {trianglePiece[2], trianglePiece[0], trianglePiece[1]}};
}

bool solveTrianglePuzzle(vector<vector<vector<string>>> &grid, vector<vector<string>> &gridLeftBorder, vector<vector<string>> &gridRightBorder, vector<vector<string>> &gridBottomBorder, vector<vector<string>> &trianglePieces)
{

    int i, j;
    if (!findFreeLocation(grid, i, j))
        return true;

    int m = trianglePieces.size();

    for (int k = 0; k < m; k++)
    {
        vector<string> trianglePiece = trianglePieces[k];
        vector<vector<string>> trianglePieceRotations = getTrianglePieceRotations(trianglePiece);
        trianglePieces.erase(trianglePieces.begin() + k); // Remove the piece from the available pieces because a piece can be used only once at a time.

        for (vector<string> trianglePieceRotation : trianglePieceRotations)
        {
            if (isValidPlacement(grid, gridLeftBorder, gridRightBorder, gridBottomBorder, i, j, trianglePieceRotation))
            {
                grid[i][j] = trianglePieceRotation; // Place the triangle piece in the grid.

                if (solveTrianglePuzzle(grid, gridLeftBorder, gridRightBorder, gridBottomBorder, trianglePieces))
                    return true;
                grid[i][j] = {}; // Remove the triangle piece from the grid.
            }
        }
        trianglePieces.insert(trianglePieces.begin() + k, trianglePiece); // Put the piece back into available pieces.
    }

    return false;
}

int main()
{
    // Input:

    // Colors are given in clockwise fashion.
    vector<vector<string>> trianglePieces = {
        {black, yellow, green},

        {red, green, white},
        {black, green, red},
        {white, green, yellow},

        {white, blue, white},
        {yellow, green, blue},
        {red, green, yellow},
        {green, red, black},
        {green, black, red},

        {black, green, black},
        {yellow, black, blue},
        {white, yellow, red},
        {white, green, yellow},
        {white, blue, blue},
        {black, white, blue},
        {white, blue, black},
    };

    int N = 4;

    vector<string> leftBorder = {white, red, white, yellow};    //Top to bottom
    vector<string> rightBorder = {blue, red, green, black};     //Top to bottom
    vector<string> bottomBorder = {green, green, white, green}; //Left to right

    // Solution:

    vector<vector<vector<string>>> grid(N, vector<vector<string>>(N, vector<string>{}));
    vector<vector<string>> gridLeftBorder(N, vector<string>{});
    vector<vector<string>> gridRightBorder(N, vector<string>{});
    vector<vector<string>> gridBottomBorder(N, vector<string>{});

    init(gridLeftBorder, gridRightBorder, gridBottomBorder, leftBorder, rightBorder, bottomBorder);

    if (solveTrianglePuzzle(grid, gridLeftBorder, gridRightBorder, gridBottomBorder, trianglePieces))
        traversal2(grid);
    else
        cout << "Cannot be solved!" << endl;

    return 0;
}

// Best case.
// vector<vector<string>> trianglePieces = {

//     //Group.
//     {white, blue, black},
//     {red, green, yellow},
//     {white, blue, blue},
//     {yellow, white, green},

//     {black, black, green},
//     {yellow, green, blue},
//     {blue, black, white},

//     //Group.
//     {black, red, green},
//     {green, red, black},
//     {black, yellow, green},

//     {green, white, red},
//     {black, blue, yellow},

//     //Group.
//     {white, green, yellow},
//     {blue, white, white},

//     {yellow, red, white},
//     //Group.
//     {red, black, green},

// };