#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> computeTransitionFunction(const string &P)
{
    int m = P.length();
    vector<vector<int>> transitionFunction(m + 1, vector<int>(256, 0)); // Assuming ASCII characters

    for (int q = 0; q <= m; ++q)
    {
        for (int a = 0; a < 256; ++a)
        { // Iterate through all possible ASCII characters
            int k = min(m, q + 1);
            while (k > 0)
            {
                string Pk = P.substr(0, k);                                    // Prefix of P of length k
                string Pqa = (q < m) ? P.substr(0, q) + char(a) : P + char(a); // Pq + a
                if (Pk == Pqa.substr(Pqa.length() - k))
                {
                    break; // Found the longest prefix which is also a suffix
                }
                --k;
            }
            transitionFunction[q][a] = k;
        }
    }

    return transitionFunction;
}

void finiteAutomatonMatcher(const string &T, const vector<vector<int>> &transitionFunction, int m)
{
    int n = T.length();
    int q = 0; // Start state

    for (int i = 0; i < n; ++i)
    {
        q = transitionFunction[q][T[i]]; // Transition to next state using ASCII value of T[i]
        if (q == m)
        { // If in accepting state
            cout << "Pattern occurs with shift " << (i - m + 1) << endl;
        }
    }
}

int main()
{
    string T = "This algorithm uses a deterministic finite automaton DFA for string matching. The DFA processes the input text one character at a time, changing states based on the transition function δ. The state set Q includes all integers from 0 to m (inclusive), where m is the length of the pattern P. The start state is 0, and the only accepting state is m, indicating a complete match of the pattern.";
    string P = "the";

    auto transitionFunction = computeTransitionFunction(P);
    finiteAutomatonMatcher(T, transitionFunction, P.length());

    return 0;
}
