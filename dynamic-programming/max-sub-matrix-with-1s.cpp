#include <algorithm>
#include <iostream>

using namespace std;

const int n = 3, m = 4;
// const int n = 2, m = 2;

void printMat(int a[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
}

void printMax(int a[n][m])
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > max)
                max = a[i][j];
        }
    }

    cout << max << endl;
}

//For simpler solution see gfg.
int main()
{

    int a[n][m] = {
        {1, 0, 0, 1},
        {1, 1, 1, 0},
        {1, 1, 1, 0},
    };

    // int a[n][m] = {
    //     {1, 1},
    //     {1, 1},

    // };

    printMat(a);

    int max[n][m]{};

    for (int i = 0; i < n; i++)
        max[i][0] = a[i][0];

    for (int j = 0; j < m; j++)
        max[0][j] = a[0][j];

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] == 0)
                max[i][j] = 0;
            else if (max[i - 1][j] == 0 || max[i][j - 1] == 0)
                max[i][j] = 1;
            else if ((max[i - 1][j] == max[i][j - 1]) && (max[i - max[i - 1][j]][j - max[i - 1][j]] > 0))
                max[i][j] = max[i - 1][j] + 1;
            else if ((max[i - 1][j] == max[i][j - 1]) && (max[i - max[i - 1][j]][j - max[i - 1][j]] == 0))
                max[i][j] = max[i - 1][j];
            else if (max[i - 1][j] < max[i][j - 1])
                max[i][j] = max[i - 1][j] + 1;
            else if (max[i - 1][j] > max[i][j - 1])
                max[i][j] = max[i][j - 1] + 1;
        }
    }

    printMat(max);
    printMax(max);

    return 0;
}