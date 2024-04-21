#include <bits/stdc++.h>
using namespace std;

bool isWord(vector<string> &dict, string &s)
{
    for (string d : dict)
        if (d == s)
            return true;

    return false;
}

void wordbreak(vector<string> &dict, string &s, int i, vector<string> &words)
{
    int n = s.size();
    if (i > n - 1)
    {
        for (string word : words)
            cout << word << " ";
        cout << endl;
    }

    for (int j = i; j < n; j++)
    {
        string w = s.substr(i, j - i + 1);

        if (isWord(dict, w))
        {
            words.push_back(w);

            wordbreak(dict, s, j + 1, words);

            words.pop_back();
        }
    }
}

int main()
{
    string s = "catsanddog";
    vector<string> dict = {"cats", "cat", "and", "sand", "dog"};

    vector<string> words;

    wordbreak(dict, s, 0, words);
    return 0;
}
