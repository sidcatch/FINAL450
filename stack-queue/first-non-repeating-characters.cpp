#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

string firstNonRepeatingChar(const string &A)
{
    unordered_map<char, int> count;
    queue<char> nonRepeatingChars;

    string result;

    for (char c : A)
    {
        count[c]++;
        if (count[c] == 1)
        {
            nonRepeatingChars.push(c);
        }

        while (!nonRepeatingChars.empty() && count[nonRepeatingChars.front()] > 1)
        {
            nonRepeatingChars.pop();
        }

        if (nonRepeatingChars.empty())
        {
            result += '#';
        }
        else
        {
            result += nonRepeatingChars.front();
        }
    }

    return result;
}

int main()
{
    string A = "aabc";
    cout << "Input: " << A << endl;
    cout << "Output: " << firstNonRepeatingChar(A) << endl;
    return 0;
}
