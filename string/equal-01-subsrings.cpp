#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int numOfEqual01Substrings(string str)
{
    int n = str.length();

    int count = 0, count1 = 0, count0 = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
            count0++;
        else if (str[i] == '1')
            count1++;

        if (count0 == count1)
            count++;
    }

    return count;
}

int main()
{
    string s = "0110";

    cout << numOfEqual01Substrings(s) << endl;

    return 0;
}