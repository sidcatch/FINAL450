#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int longestRecurringSubsequenceLenght(string str)
{
    int len = str.length();

    int res[len + 1][len + 1];

    for (int i = 0; i <= len; i++)
        for (int j = 0; j <= len; j++)
            res[i][j] = 0;

    for (int i = 1; i <= len; i++)
        for (int j = 1; j <= len; j++)
        {
            if (str[i] == str[j] && i != j)
                res[i][j] = 1 + res[i - 1][j - 1];
            else
                res[i][j] = max(res[i - 1][j], res[i][j - 1]);
        }

    return res[len][len];
}

int main()
{
    cout << longestRecurringSubsequenceLenght("lkjasdflklkjadsflkjsadflkj") << endl;
    return 0;
}