#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPalindrome(string &s)
{
    int i = 0;
    int j = s.size() - 1;

    while (i < j)
    {
        if (s[i] != s[j])
            return false;

        i++;
        j--;
    }

    return true;
}

void palindromicPartitions(string &s, int i, vector<string> &palindromes)
{

    int n = s.size();

    if (i > n - 1)
    {
        for (string palindrome : palindromes)
            cout << palindrome << " ";
        cout << endl;

        return;
    }

    for (int j = i; j < n; j++)
    {
        string curr = s.substr(i, j - i + 1);

        if (isPalindrome(curr))
        {
            palindromes.push_back(curr);
            palindromicPartitions(s, j + 1, palindromes);
            palindromes.pop_back();
        }
    }
}

int main()
{

    string s = "nitin";

    vector<string> palindromes;

    palindromicPartitions(s, 0, palindromes);

    return 0;
}