#include <iostream>
#include <string>

using namespace std;

int MIN(int a, int b, int c)
{
    return min(a, min(b, c));
}

int main()
{
    string a = "adceg";
    string b = "abcfg";

    int m[a.size() + 1][b.size() + 1];

    for (int i = 0; i < a.size() + 1; i++)
        for (int j = 0; j < b.size() + 1; j++)
        {
            if (i == 0 && j == 0)
                m[i][j] = 0;
            else if (i == 0)
                m[i][j] = m[i][j - 1] + 1;
            else if (j == 0)
                m[i][j] = m[i - 1][j] + 1;

            else if (a[i - 1] == b[j - 1])
                m[i][j] = m[i - 1][j - 1];
            else
                m[i][j] = MIN(m[i][j - 1], m[i - 1][j], m[i - 1][j - 1]) + 1;
        }

    cout << m[a.size()][b.size()] << endl;
    return 0;
}
