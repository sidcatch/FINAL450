#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string smallestWindow(string s, string p)
{
    vector<int> freq(26, 0);

    for (char c : p)
        freq[c - 'a']++;

    int left = 0;
    int count = p.size();
    int start = -1, minLen = INT_MAX;

    for (int right = 0; right < s.size(); right++)
    {

        if (freq[s[right] - 'a'] > 0)
            count--;

        freq[s[right] - 'a']--;

        while (count == 0)
        {

            if (right - left + 1 < minLen)
            {
                minLen = right - left + 1;
                start = left;
            }

            freq[s[left] - 'a']++;

            if (freq[s[left] - 'a'] > 0)
                count++;

            left++;
        }
    }

    if (start == -1)
        return "";

    return s.substr(start, minLen);
}

int main()
{

    string s1 = "timetopractice";
    string p1 = "toc";
    cout << smallestWindow(s1, p1) << endl;

    string s2 = "zoomlazapzo";
    string p2 = "oza";
    cout << smallestWindow(s2, p2) << endl;

    string s3 = "zoom";
    string p3 = "zooe";
    cout << smallestWindow(s3, p3) << endl;

    return 0;
}