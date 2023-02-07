#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    cout << s;
    cout << endl;

    if (s.length() < 2)
    {
        cout << s;
        return 0;
    }

    vector<char> dublicates;

    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == s[i - 1] && (dublicates.empty() || dublicates.back() != s[i]))
            dublicates.push_back(s[i]);
    }

    for (int i = 0; i < dublicates.size(); i++)
    {
        cout << dublicates[i];
    }

    cout << endl;
    return 0;
}