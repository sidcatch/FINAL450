/*
 * Knuth-Morris-Pratt (KMP) String Matching Algorithm
 * 
 * Algorithm Overview:
 * - Efficient pattern matching using preprocessing to avoid redundant comparisons
 * - Preprocessing: O(m) where m = pattern length
 * - Matching: O(n) where n = text length
 * - Total Time: O(m + n) - linear time!
 * - Space: O(m) for the prefix function array
 * 
 * Key Idea:
 * - Precompute a prefix function π that tells us how many characters to skip
 * - When a mismatch occurs, use π to avoid re-examining previously matched characters
 * - No backtracking in the text (only moves forward)
 * 
 * Advantages over naive approach:
 * - Naive: O(n * m) worst case
 * - KMP: O(n + m) guaranteed
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Computes the prefix function (also called failure function) for the pattern
 * 
 * @param P The pattern string
 * @return Vector π where π[q] = length of longest proper prefix of P[0..q] that is also a suffix
 * 
 * The prefix function π tells us:
 * - For each position q in the pattern, what is the length of the longest proper prefix
 *   of P[0..q] that is also a suffix of P[0..q]
 * - This information helps us skip unnecessary comparisons during matching
 * 
 * Example: For pattern "ABABCABAB"
 * π = [0, 0, 1, 2, 0, 1, 2, 3, 4]
 * 
 * Time Complexity: O(m) where m = pattern length
 */
vector<int> computePrefixFunction(const string &P)
{
    int m = P.size();
    vector<int> prefixFunction(m, 0); // π[0] is always 0 (no proper prefix for single char)
    int k = 0;                        // Length of the previous longest prefix suffix

    // Iterate through pattern starting from index 1
    for (int q = 1; q < m; q++)
    {
        // While there's a mismatch, fall back using previously computed values
        // This is the key optimization - we don't restart from scratch
        while (k > 0 && P[k] != P[q])
            k = prefixFunction[k - 1]; // Move to the next possible match position

        // If characters match, extend the current prefix-suffix length
        if (P[k] == P[q])
            k++;

        // Store the longest prefix-suffix length for position q
        prefixFunction[q] = k;
    }
    return prefixFunction;
}

/**
 * Performs KMP string matching to find all occurrences of pattern in text
 * 
 * @param T The text string to search in
 * @param P The pattern string to search for
 * 
 * Algorithm:
 * 1. Precompute the prefix function π for pattern P
 * 2. Scan through text T from left to right
 * 3. When a character matches, advance both text and pattern pointers
 * 4. When a mismatch occurs, use π to determine how far back to shift in the pattern
 * 5. When full match found (q == m), report position and continue searching
 * 
 * Key Insight:
 * - Text pointer 'i' never backtracks (only moves forward)
 * - Pattern pointer 'q' may shift back using π, but smartly skips redundant checks
 * 
 * Time Complexity: O(n) where n = text length (plus O(m) preprocessing)
 */
void KMPMatcher(const string &T, const string &P)
{
    int n = T.size(); // Text length
    int m = P.size(); // Pattern length

    // Step 1: Preprocess pattern to compute prefix function
    auto prefixFunction = computePrefixFunction(P);

    int q = 0; // Number of characters matched so far

    // Step 2: Scan through the text from left to right
    for (int i = 0; i < n; i++)
    {
        // Handle mismatch: shift pattern using prefix function
        // Keep shifting until we find a match or reach the beginning
        while (q > 0 && P[q] != T[i])
            q = prefixFunction[q - 1]; // Smart shift - skip redundant comparisons

        // If current characters match, advance the pattern pointer
        if (P[q] == T[i])
            q++; // One more character matched

        // Check if we've matched the entire pattern
        if (q == m)
        {
            // Pattern found! Report the starting position (shift)
            cout << "Pattern occurs with shift " << (i - m + 1) << endl;

            // Continue searching for more occurrences
            // Use prefix function to efficiently shift pattern
            q = prefixFunction[q - 1];
        }
    }
}

int main()
{
    // Example text and pattern demonstrating KMP efficiency
    string T = "ABABDABABCABABABACDABABCABAB";
    string P = "ABABCABAB";

    // Find all occurrences of pattern P in text T
    // KMP is especially efficient when pattern has repeating prefixes
    // In this example, the pattern has overlapping prefix/suffix: "ABAB"
    KMPMatcher(T, P);

    return 0;
}
