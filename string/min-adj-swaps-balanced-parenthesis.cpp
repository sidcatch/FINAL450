#include <iostream>
#include <string>
#include <vector>

using namespace std;
int minimumNumberOfSwaps(string s)
{
    // Keep track of '[' positions
    vector<int> openPositions;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '[')
            openPositions.push_back(i);

    int countOpen = 0;        // To count number of encountered '['
    int nextOpenPosIndex = 0; // To track position of next '[' in openPositions
    long swaps = 0;           // To store result

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '[')
        {
            ++countOpen;
            ++nextOpenPosIndex;
        }
        else if (s[i] == ']')
        {
            --countOpen;
        }
        else
        {
            //throw!
        }

        if (countOpen < 0)
        {
            swaps += openPositions[nextOpenPosIndex] - i;
            swap(s[i], s[openPositions[nextOpenPosIndex]]);
            ++nextOpenPosIndex;
            countOpen = 1;
        }
    }

    return swaps;
}
int main()
{
    string s = "[]][]["; // "[][]][", "[][][]"

    cout << minimumNumberOfSwaps(s) << endl;

    return 0;
}