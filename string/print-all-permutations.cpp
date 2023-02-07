#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void printAllPermutations(string str, int l, int r)
{
    if (r == l)
        cout << str << " ";
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(str[l], str[i]);

            printAllPermutations(str, l + 1, r);

            swap(str[l], str[i]);
        }
    }
}

int main()
{
    string s = "abcihb";

    printAllPermutations(s, 0, s.length() - 1);
    cout << endl;
    return 0;
}