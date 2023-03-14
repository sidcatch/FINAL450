#include <iostream>
#include <vector>
//#include <algorithm>

using namespace std;

int main()
{
    int W = 8;
    vector<int> p = {1, 4, 5, 7};
    vector<int> w = {1, 3, 4, 5};

    int r[w.size() + 1][W + 1];

    for (int i = 0; i < w.size() + 1; i++)
        r[i][0] = 0;
    for (int i = 0; i < W + 1; i++)
        r[0][i] = 0;

    for (int i = 1; i < w.size() + 1; i++)
        for (int j = 1; j < W + 1; j++)
        {
            if (w[i - 1] > j)
                r[i][j] = r[i - 1][j];
            else
                r[i][j] = max(r[i - 1][j], r[i][j - w[i - 1]] + p[i - 1]);
        }

    cout << r[w.size()][W] << endl;

    return 0;
}