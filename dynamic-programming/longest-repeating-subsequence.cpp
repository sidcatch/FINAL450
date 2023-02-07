#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "axxxy";

    int m[a.size() + 1][a.size() + 1];

    for (int i = 0; i < a.size() + 1; i++)
        for (int j = 0; j < a.size() + 1; j++)
        {
            if (i == 0 || j == 0)
                m[i][j] = 0;
            else if (a[i - 1] == a[j - 1] && i != j)
                m[i][j] = 1 + m[i - 1][j - 1];
            else
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
        }

    cout << m[a.size()][a.size()] << endl;
    return 0;
}