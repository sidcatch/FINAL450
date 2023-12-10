#include <climits>
#include <iostream>
#include <unordered_map>

using namespace std;

string minWindow(const string &s, const string &p)
{
    unordered_map<char, int> freqS, freqP;

    for (char c : p)
        freqP[c]++;

    int required_chars = freqP.size();
    int formed_chars = 0;
    int left = 0, right = 0;
    int min_length = INT_MAX;
    int start_idx = 0;

    for (right = 0; right < s.length(); ++right)
    {
        char c = s[right];
        freqS[c]++;

        if (freqP.find(c) != freqP.end() && freqS[c] == freqP[c])
            formed_chars++;

        while (formed_chars == required_chars && left <= right)
        {
            if (right - left + 1 < min_length)
            {
                min_length = right - left + 1;
                start_idx = left;
            }

            char left_char = s[left];
            freqS[left_char]--;

            if (freqP.find(left_char) != freqP.end() && freqS[left_char] < freqP[left_char])
                formed_chars--;

            left++;
        }
    }

    return (min_length == INT_MAX) ? "" : s.substr(start_idx, min_length);
}

int main()
{
    string S = "ADOBECODEBANC";
    string P = "ABC";

    string result = minWindow(S, P);
    cout << "Smallest window in S containing all characters of P: " << result << endl;

    return 0;
}
