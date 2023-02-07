#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> s = {1, 2, 3};

    int n = 4;

    int r[s.size()][n + 1];

    for (int i = 0; i < s.size(); i++)
        r[i][0] = 1;

    // for (int i = 0; i < n + 1; i++)
    //     r[0][i] = 0;

    for (int i = 0; i < s.size(); i++)
        for (int j = 1; j < n + 1; j++)

        {
            if (j < s[i])
                r[i][j] = i > 0 ? r[i - 1][j] : 0;
            else

                r[i][j] = (i > 0 ? r[i - 1][j] : 0) + r[i][j - s[i]];
        }

    cout << r[s.size() - 1][n];

    return 0;
}

// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     vector<int> s = {1, 2, 3};

//     int n = 4;

//     int r[s.size() + 1][n + 1];

//     for (int i = 0; i < s.size(); i++)
//         r[i][0] = 1;

//     for (int i = 0; i < n + 1; i++)
//         r[0][i] = 0;

//     for (int i = 1; i < s.size() + 1; i++)
//         for (int j = 1; j < n + 1; j++)

//         {
//             if (j < s[i - 1])
//                 r[i][j] = r[i - 1][j];
//             else

//                 r[i][j] = r[i - 1][j] + r[i][j - s[i - 1]];
//         }

//     cout << r[s.size()][n];

//     return 0;
// }
