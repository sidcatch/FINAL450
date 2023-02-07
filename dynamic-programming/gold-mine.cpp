#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> mine = {{1, 3, 3},
                                {2, 1, 4},
                                {0, 6, 4}};

    // int m[mine[0].size()][mine.size()];

    int m[mine.size()][mine[0].size()];

    for (int j = mine[0].size() - 1; j >= 0; j--)
        for (int i = 0; i < mine.size(); i++)
        {

            if (j == mine[0].size() - 1)
            {
                m[i][j] = mine[i][j];
                continue;
            }

            int rightUp = i > 0 ? mine[i][j] + m[i - 1][j + 1] : 0;
            int right = mine[i][j] + m[i][j + 1];

            int rightDown = i < mine.size() - 1 ? mine[i][j] + m[i + 1][j + 1] : 0;

            m[i][j] = rightUp;

            if (right > m[i][j])
                m[i][j] = right;

            if (rightDown > m[i][j])
                m[i][j] = rightDown;
        }
    int res = m[0][0];
    for (int i = 1; i < mine.size(); i++)
        res = max(res, m[i][0]);
    int MAX = res;

    cout << MAX << endl;

    return 0;
}