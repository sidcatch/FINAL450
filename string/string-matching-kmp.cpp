#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computePrefixFunction(const string &P)
{
    int m = P.size();
    vector<int> prefixFunction(m, 0);
    int k = 0;
    for (int q = 1; q < m; q++)
    {
        while (k > 0 && P[k] != P[q])
            k = prefixFunction[k - 1];
        if (P[k] == P[q])
            k++;
        prefixFunction[q] = k;
    }
    return prefixFunction;
}

void KMPMatcher(const string &T, const string &P)
{
    int n = T.size();
    int m = P.size();
    auto prefixFunction = computePrefixFunction(P);
    int q = 0; // number of characters matched
    for (int i = 0; i < n; i++)
    { // scan the text from left to right
        while (q > 0 && P[q] != T[i])
            q = prefixFunction[q - 1]; // next character does not match
        if (P[q] == T[i])
            q++; // next character matches
        if (q == m)
        { // is all of P matched?
            cout << "Pattern occurs with shift " << (i - m + 1) << endl;
            q = prefixFunction[q - 1]; // look for the next match
        }
    }
}

int main()
{
    string T = "ABABDABABCABABABACDABABCABAB";
    string P = "ABABCABAB";
    KMPMatcher(T, P);
    return 0;
}
