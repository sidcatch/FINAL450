#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string lookAndSayNext(string str)
{
    string res = "";

    str = str + "$";

    int len = str.length();

    if (len >= 3)
    {
        int prevCharCount = 1;
        for (int i = 1; i < len; i++)
        {
            if (str[i] == str[i - 1])
            {
                prevCharCount++;
            }
            else
            {
                res = res + to_string(prevCharCount) + str[i - 1]; //int to string. Why 'str[i-1]' be need not coverted to string??
                prevCharCount = 1;
            }
        }
    }
    else if (len == 2)
    {
        res = "1" + string(1, str[0]); //char to string
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    string res = "1";
    cout << res << "   ";

    for (int i = 1; i <= n; i++)
    {
        res = lookAndSayNext(res);
        cout << res << "   ";
    }

    return 0;
}