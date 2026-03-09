/*
 * String Matching using Finite Automaton (DFA-based approach)
 * 
 * Algorithm Overview:
 * - Builds a Deterministic Finite Automaton (DFA) for pattern matching
 * - Preprocessing: O(m * |Σ|) where m = pattern length, |Σ| = alphabet size
 * - Matching: O(n) where n = text length
 * - Total Time: O(m * |Σ| + n)
 * - Space: O(m * |Σ|)
 * 
 * The DFA has:
 * - States: 0 to m (where m is pattern length)
 * - Start state: 0
 * - Accept state: m
 * - Transition function δ(q, a) determines next state based on current state q and character a
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Computes the transition function for the finite automaton
 * 
 * @param P The pattern string to search for
 * @return 2D vector representing δ(state, character) -> next_state
 * 
 * For each state q and character a:
 * - δ(q, a) = longest prefix of P that is also a suffix of P[0..q-1] + a
 * - This tells us which state to transition to when reading character a in state q
 * 
 * Time Complexity: O(m³ * |Σ|) - can be optimized to O(m * |Σ|) using KMP preprocessing
 */
vector<vector<int>> computeTransitionFunction(const string &P)
{
    int m = P.length();
    // Create transition table: transitionFunction[state][character] = next_state
    // Size: (m+1) states x 256 possible ASCII characters
    vector<vector<int>> transitionFunction(m + 1, vector<int>(256, 0));

    // For each state q (0 to m)
    for (int q = 0; q <= m; ++q)
    {
        // For each possible input character a (all ASCII)
        for (int a = 0; a < 256; ++a)
        {
            // Find the longest prefix of P that is a suffix of P[0..q-1] + char(a)
            // Start with maximum possible length k and decrease until we find a match
            int k = min(m, q + 1);
            while (k > 0)
            {
                // Pk: prefix of pattern P with length k
                string Pk = P.substr(0, k);

                // Pqa: pattern prefix up to state q, concatenated with character a
                string Pqa = (q < m) ? P.substr(0, q) + char(a) : P + char(a);

                // Check if Pk matches the suffix of Pqa with length k
                if (Pk == Pqa.substr(Pqa.length() - k))
                {
                    break; // Found the longest prefix-suffix match
                }
                --k; // Try shorter prefix
            }
            // Store the next state for current state q reading character a
            transitionFunction[q][a] = k;
        }
    }

    return transitionFunction;
}

/**
 * Performs string matching using the precomputed transition function
 * 
 * @param T The text string to search in
 * @param transitionFunction The DFA transition table (δ function)
 * @param m The length of the pattern
 * 
 * Algorithm:
 * 1. Start in state 0
 * 2. For each character in text T, transition to next state using δ(current_state, character)
 * 3. If we reach state m (accept state), we've found a complete match
 * 
 * Time Complexity: O(n) where n = text length
 * - Each character is processed exactly once
 * - No backtracking required (advantage over naive approach)
 */
void finiteAutomatonMatcher(const string &T, const vector<vector<int>> &transitionFunction, int m)
{
    int n = T.length();
    int q = 0; // Start at initial state 0

    // Process each character in the text
    for (int i = 0; i < n; ++i)
    {
        // Transition to next state based on current state and input character
        // Uses ASCII value of T[i] to index the transition table
        q = transitionFunction[q][T[i]];

        // Check if we've reached the accept state (complete pattern match)
        if (q == m)
        {
            // Pattern found! Calculate starting position (shift)
            cout << "Pattern occurs with shift " << (i - m + 1) << endl;
            // Note: The automaton continues running to find all occurrences
        }
    }
}

int main()
{
    // Example text containing multiple occurrences of the pattern
    string T = "This algorithm uses a deterministic finite automaton DFA for string matching. The DFA processes the input text one character at a time, changing states based on the transition function δ. The state set Q includes all integers from 0 to m (inclusive), where m is the length of the pattern P. The start state is 0, and the only accepting state is m, indicating a complete match of the pattern.";

    // Pattern to search for (case-sensitive)
    string P = "the";

    // Step 1: Preprocessing - Build the transition function (DFA)
    // This needs to be done only once for each pattern
    auto transitionFunction = computeTransitionFunction(P);

    // Step 2: Matching - Search for pattern in text using the DFA
    // This can be reused to search the same pattern in multiple texts
    finiteAutomatonMatcher(T, transitionFunction, P.length());

    return 0;
}
