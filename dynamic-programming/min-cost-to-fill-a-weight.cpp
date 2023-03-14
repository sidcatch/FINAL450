
// #include <algorithm>
// #include <iostream>
// #include <limits.h>

// using namespace std;

// int c[] = {20, 10, 4, 50, 100};
// const int n = sizeof(c) / sizeof(c[0]);

// const int w = 5;

// void printMat(int a[n + 1][w])
// {
//     for (int i = 0; i < n + 1; i++)
//     {
//         for (int j = 0; j < w; j++)
//         {
//             cout << a[i][j] << " ";
//         }
//         cout << endl;
//     }

//     cout << endl;
// }

// int main()
// {

//     int m[n + 1][w];

//     for (int i = 0; i < n + 1; i++)
//         m[i][0] = 0;

//     for (int j = 1; j < w; j++)
//         m[0][j] = -1;

//     for (int i = 1; i < n + 1; i++)
//     {
//         for (int j = 1; j < w; j++)
//         {
//             if (j > i - 1 || c[i - 1] == -1)
//                 m[i][j] = m[i - 1][j];
//             else if (m[i][j - i + 1] == -1)
//                 m[i][j] = m[i - 1][j];
//             else if (m[i - 1][j] != -1)
//                 m[i][j] = min(m[i - 1][j], m[i][j - i + 1] + c[i - 1]);
//             else
//                 m[i][j] = m[i][j - i + 1] + c[i - 1];
//         }
//     }
//     printMat(m);

//     return 0;
// }