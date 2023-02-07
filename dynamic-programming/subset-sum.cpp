#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> set = {3, 34, 4, 12, 5, 2};
    int sum = 30;

    bool r[set.size() + 1][sum + 1];

    for (int i = 0; i < set.size() + 1; i++)
        r[i][0] = true;

    for (int j = 1; j < sum + 1; j++)
        r[0][j] = false;

    for (int i = 1; i < set.size() + 1; i++)
        for (int j = 1; j < sum + 1; j++)
        {
            if (j < set[i - 1])
                r[i][j] = r[i - 1][j];

            else

                r[i][j] = r[i - 1][j] || r[i - 1][j - set[i - 1]];
        }

    cout << r[set.size()][sum] << endl;

    return 0;
}