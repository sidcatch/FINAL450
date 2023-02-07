#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a = {1, 2, 3, 4};
    int k = 11;

    int r[a.size() + 1][k + 1];

    for (int i = 0; i < a.size() + 1; i++)
        r[i][0] = 0;

    for (int i = 0; i < k + 1; i++)
        r[0][i] = 0;

    for (int i = 1; i < a.size() + 1; i++)
        for (int j = 1; j < k + 1; j++)
        {

            r[i][j] = r[i - 1][j];

            if (a[i - 1] <= j)
                r[i][j] += r[i - 1][j / a[i - 1]] + 1;
        }

    cout << r[a.size()][k] << endl;

    return 0;
}