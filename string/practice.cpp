#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long countSwapsToBalance(string s)
{
    vector<int> openBracketPositions;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '[')
            openBracketPositions.push_back(i);

    int unbalancedCount = 0;
    int nextOpenBracketPos = 0;
    long swapCount = 0;

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '[')
        {
            ++unbalancedCount;
            ++nextOpenBracketPos;
        }
        else if (s[i] == ']')
        {
            --unbalancedCount;
        }

        if (unbalancedCount < 0)
        {
            cout << openBracketPositions[nextOpenBracketPos] << " " << i << endl;
            swapCount += openBracketPositions[nextOpenBracketPos] - i;
            swap(s[i], s[openBracketPositions[nextOpenBracketPos]]);
            ++nextOpenBracketPos;
            unbalancedCount = 1;
        }
    }

    return swapCount;
}

int main()
{
    string input1 = "[]][][";
    cout << "Swaps needed for input 1: " << countSwapsToBalance(input1) << endl;

    string input2 = "[[][]]";
    cout << "Swaps needed for input 2: " << countSwapsToBalance(input2) << endl;

    return 0;
}
