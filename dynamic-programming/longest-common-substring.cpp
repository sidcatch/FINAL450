#include <iostream>
#include <limits.h>
#include <string>

using namespace std;

int main()
{

    string a = "ABCDGH";
    string b = "ACDGHR";

    const int n = a.size() + 1;
    const int m = b.size() + 1;

    int max[n][m]{0};

    for (int j = 0; j < m; j++)
        max[0][j] = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            max[i][j] = (a[i - 1] == b[j - 1]) ? (max[i - 1][j - 1] + 1) : 0;
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << max[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans < max[i][j])
                ans = max[i][j];
        }
    }
    cout << ans << endl;

    return 0;
}