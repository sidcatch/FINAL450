#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WildcardMatcher
{
  public:
    /*
    ----------------------------------------------------
    1) Recursive Solution
       Time: Exponential in worst case
       Space: O(n + m) recursion stack
    ----------------------------------------------------
    */
    static bool matchRecursive(const string &wild, const string &pattern)
    {
        return solveRecursive(wild, pattern, 0, 0);
    }

    /*
    ----------------------------------------------------
    2) Dynamic Programming Solution
       Time: O(n * m)
       Space: O(n * m)
    ----------------------------------------------------
    */
    static bool matchDP(const string &wild, const string &pattern)
    {
        int n = wild.size();
        int m = pattern.size();

        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        // wild vs empty pattern
        for (int i = 1; i <= n; i++)
        {
            if (wild[i - 1] == '*')
            {
                dp[i][0] = dp[i - 1][0];
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (wild[i - 1] == '*')
                {
                    // '*' matches empty OR one more character
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
                else if (wild[i - 1] == '?' || wild[i - 1] == pattern[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }

        return dp[n][m];
    }

    /*
    ----------------------------------------------------
    3) Greedy Solution
       Time: O(n + m)
       Space: O(1)
    ----------------------------------------------------
    */
    static bool matchGreedy(const string &wild, const string &pattern)
    {
        int i = 0;          // pointer for wild
        int j = 0;          // pointer for pattern
        int lastStar = -1;  // index of last '*' in wild
        int lastMatch = -1; // position in pattern matched by last '*'

        while (j < (int)pattern.size())
        {
            if (i < (int)wild.size() &&
                (wild[i] == pattern[j] || wild[i] == '?'))
            {
                i++;
                j++;
            }
            else if (i < (int)wild.size() && wild[i] == '*')
            {
                lastStar = i;
                lastMatch = j;
                i++;
            }
            else if (lastStar != -1)
            {
                i = lastStar + 1;
                lastMatch++;
                j = lastMatch;
            }
            else
            {
                return false;
            }
        }

        while (i < (int)wild.size() && wild[i] == '*')
        {
            i++;
        }

        return i == (int)wild.size();
    }

  private:
    static bool solveRecursive(const string &wild, const string &pattern, int i, int j)
    {
        int n = wild.size();
        int m = pattern.size();

        if (i == n && j == m)
        {
            return true;
        }

        if (i == n)
        {
            return false;
        }

        if (wild[i] == '*')
            return solveRecursive(wild, pattern, i + 1, j) ||
                   (j < m && solveRecursive(wild, pattern, i, j + 1));

        if (j < m && (wild[i] == '?' || wild[i] == pattern[j]))
            return solveRecursive(wild, pattern, i + 1, j + 1);

        return false;
    }
};

void runTest(const string &wild, const string &pattern)
{
    cout << "Wild    : " << wild << '\n';
    cout << "Pattern : " << pattern << '\n';

    bool ans1 = WildcardMatcher::matchRecursive(wild, pattern);
    bool ans2 = WildcardMatcher::matchDP(wild, pattern);
    bool ans3 = WildcardMatcher::matchGreedy(wild, pattern);

    cout << "Recursive : " << (ans1 ? "Yes" : "No") << '\n';
    cout << "DP        : " << (ans2 ? "Yes" : "No") << '\n';
    cout << "Greedy    : " << (ans3 ? "Yes" : "No") << '\n';
    cout << "-----------------------------\n";
}

int main()
{
    runTest("ge*ks", "geeks");
    runTest("ge?ks*", "geeksforgeeks");
    runTest("g*k", "gee");
    runTest("*pqrs", "pqrst");
    runTest("abc*bcd", "abcdhghgbcd");
    runTest("abc*c?d", "abcd");
    runTest("*c*d", "abcd");
    runTest("*?c*d", "abcd");
    runTest("geeks**", "geeks");

    return 0;
}