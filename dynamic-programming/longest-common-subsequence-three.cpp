#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "geeks", b = "geeksfor", c = "geeksforgeeks";

    int m[a.size() + 1][b.size() + 1][c.size() + 1];

    for (int i = 0; i < a.size() + 1; i++)
        for (int j = 0; j < b.size() + 1; j++)
            for (int k = 0; k < c.size() + 1; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                    m[i][j][k] = 0;

                else if (a[i] == b[j] && a[i] == c[k])
                    m[i][j][k] = 1 + m[i - 1][j - 1][k - 1];
                else
                    m[i][j][k] = max({m[i - 1][j][k], m[i][j - 1][k], m[i][j][k - 1]});
            }

    cout << m[a.size()][b.size()][c.size()] << endl;

    return 0;
}