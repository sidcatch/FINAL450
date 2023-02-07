#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int n = 4;
    int a[][n] = {{4, 5, 3, 2},
                  {2, 10, 1, 4}};
    int t[][n] = {{0, 7, 4, 5},
                  {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};

    int T1[4];

    int T2[4];

    T1[0] = e[0] + a[0][0];

    T2[0] = e[1] + a[1][0];

    for (int i = 1; i < n; i++)
    {

        T1[i] = min(T1[i - 1] + a[0][i], T2[i - 1] + t[0][i] + a[0][i]);
        T2[i] = min(T2[i - 1] + a[1][i], T1[i - 1] + t[1][i] + a[1][i]);
    }

    int MIN = min(T1[n - 1] + x[0], T2[n - 1] + x[1]);

    cout << MIN << endl;

    return 0;
}