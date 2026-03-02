#include <cmath>
#include <iostream>
#include <string>

using namespace std;

/**
 * Rabin-Karp String Matching Algorithm
 * 
 * This algorithm uses hashing to find pattern occurrences in a text.
 * Time Complexity: O((n-m+1)*m) worst case, O(n+m) average case
 * Space Complexity: O(1)
 * 
 * @param T - The text string to search in
 * @param P - The pattern string to search for
 * @param d - The number of characters in the input alphabet (radix)
 * @param q - A prime number used for modulo operation to avoid overflow
 */
void rabinKarpMatcher(const string &T, const string &P, int d, int q)
{
    int n = T.length(); // Length of text
    int m = P.length(); // Length of pattern

    // h = d^(m-1) % q, used for removing leading digit in rolling hash
    int h = static_cast<int>(pow(d, m - 1)) % q;

    int p = 0; // Hash value for pattern
    int t = 0; // Hash value for text window

    // PREPROCESSING PHASE
    // Compute hash value of pattern and first window of text
    // Hash function: hash(s) = (s[0]*d^(m-1) + s[1]*d^(m-2) + ... + s[m-1]) % q
    for (int i = 0; i < m; i++)
    {
        p = (d * p + P[i]) % q; // Pattern hash using Horner's rule
        t = (d * t + T[i]) % q; // First window hash using Horner's rule
    }

    // MATCHING PHASE
    // Slide the pattern over text one position at a time
    for (int s = 0; s <= n - m; s++)
    {
        // If hash values match, check for spurious hit
        if (p == t)
        {
            // Verify actual characters to avoid false positives (spurious hits)
            // This is necessary because different strings can have the same hash
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

        // Compute hash for next window using rolling hash technique
        // Remove leading digit (T[s]) and add trailing digit (T[s+m])
        // Formula: t_new = (d * (t_old - T[s] * h) + T[s+m]) % q
        if (s < n - m)
        {
            t = (d * (t - T[s] * h) + T[s + m]) % q;

            // Ensure t is non-negative (modulo operation can produce negative values)
            if (t < 0)
                t += q;
        }
    }
}

int main()
{
    // Example text to search in
    string T = "The Rabin-Karp algorithm for string matching uses hashing to find any one of a set of pattern strings in a text. The key idea of the method is to calculate a hash value for the pattern and for each substring of the text of the same length as the pattern, and then compare the hash values.";

    // Pattern to search for
    string P = "the";

    // d: Number of characters in the input alphabet (256 for extended ASCII)
    int d = 256;

    // q: A large prime number to reduce spurious hits and avoid overflow
    // Larger prime numbers reduce the probability of hash collisions
    int q = 101;

    rabinKarpMatcher(T, P, d, q);

    return 0;
}
