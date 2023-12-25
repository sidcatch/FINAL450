#include <iostream>
#include <string>
#include <vector>

using namespace std;
int minimumNumberOfSwaps(string s)
{
    // Keep track of '[' positions
    vector<int> pos;
    for (int i = 0; i < s.length(); ++i)
        if (s[i] == '[')
            pos.push_back(i);

    int count = 0; // To count number of encountered '['
    int p = 0;     // To track position of next '[' in pos
    long sum = 0;  // To store result

    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == '[')
        {
            ++count;
            ++p;
        }
        else if (s[i] == ']')
        {
            --count;
        }

        if (count < 0)
        {
            sum += pos[p] - i;
            swap(s[i], s[pos[p]]);
            ++p;
            count = 1;
        }
    }

    return sum;
}
int main()
{
    string s = "[]][][";

    cout << minimumNumberOfSwaps(s) << endl;

    return 0;
}