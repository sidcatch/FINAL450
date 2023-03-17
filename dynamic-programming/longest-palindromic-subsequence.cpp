#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main()
{

    string a = "GEEKSFORGEEKS";

    string b = a;
    reverse(b.begin(), b.end());

    int m[a.size() + 1][b.size() + 1];

    for (int i = 0; i < a.size() + 1; i++)
        for (int j = 0; j < b.size() + 1; j++)
        {
            if (i == 0 || j == 0)
                m[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                m[i][j] = 1 + m[i - 1][j - 1];
            else
                m[i][j] = max(m[i - 1][j], m[i][j - 1]);
        }

    cout << m[a.size()][b.size()] << endl;

    return 0;
}