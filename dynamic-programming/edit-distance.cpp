#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a = "geek";
    string b = "gesek";

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
            {
                int insert = m[i][j - 1] + 1;
                int remove = m[i - 1][j] + 1;
                int delet = m[i - 1][j - 1] + 1;

                m[i][j] = insert;

                if (remove < m[i][j])
                    m[i][j] = remove;

                if (delet < m[i][j])
                    m[i][j] = delet;
            }
        }

    cout << m[a.size()][b.size()] << endl;

    return 0;
}