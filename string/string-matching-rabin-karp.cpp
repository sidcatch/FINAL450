#include <cmath>
#include <iostream>
#include <string>

using namespace std;

void rabinKarpMatcher(const string &T, const string &P, int d, int q)
{
    int n = T.length();
    int m = P.length();
    int h = static_cast<int>(pow(d, m - 1)) % q;
    int p = 0;
    int t = 0;

    // Preprocessing
    for (int i = 0; i < m; i++)
    {
        p = (d * p + P[i]) % q;
        t = (d * t + T[i]) % q;
    }

    // Matching
    for (int s = 0; s <= n - m; s++)
    {
        if (p == t)
        {
            bool match = true;
            for (int j = 0; j < m; j++)
            {
                if (T[s + j] != P[j])
                {
                    match = false;
                    break;
                }
            }
            if (match)
            {
                cout << "Pattern occurs with shift " << s << endl;
            }
        }
        if (s < n - m)
        {
            t = (d * (t - T[s] * h) + T[s + m]) % q;
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    string T = "The Rabin-Karp algorithm for string matching uses hashing to find any one of a set of pattern strings in a text. The key idea of the method is to calculate a hash value for the pattern and for each substring of the text of the same length as the pattern, and then compare the hash values.";
    string P = "the";
    int d = 256; // A common choice for d is the number of characters in the input alphabet
    int q = 101; // A prime number

    rabinKarpMatcher(T, P, d, q);

    return 0;
}
