#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

//No need to create a new reversed string! see gfg.
int main()
{

    string a = "GEEKSFORGEEKS";

    string b = a;
    reverse(b.begin(), b.end());

    int m[a.size() + 1][b.size() + 1];
    char r[a.size() + 1][b.size() + 1];

    for (int i = 0; i < a.size() + 1; i++)
        for (int j = 0; j < b.size() + 1; j++)
        {
            if (i == 0 || j == 0)
                m[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
            {
                r[i][j] = 'd';
                m[i][j] = 1 + m[i - 1][j - 1];
            }

            else
            {
                if (m[i - 1][j] > m[i][j - 1])
                {
                    r[i][j] = 'u';
                    m[i][j] = m[i - 1][j];
                }

                else
                {
                    r[i][j] = 's';
                    m[i][j] = m[i][j - 1];
                }
            }
        }

    cout << m[a.size()][b.size()] << endl;
    cout << endl;

    int i = a.size();
    int j = a.size();

    while (i > 0 && j > 0)
    {
        char curr = r[i][j];

        switch (curr)
        {
        case 'd':
            cout << a[i - 1];
            i--;
            j--;
            break;
        case 'u':
            i--;
            break;
        case 's':
            j--;
            break;

        default:
            break;
        }
    }

    return 0;
}