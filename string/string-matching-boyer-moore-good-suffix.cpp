#include <bits/stdc++.h>
using namespace std;

/*
 * ============================================================================
 * BOYER-MOORE GOOD SUFFIX ALGORITHM - DETAILED EXPLANATION
 * ============================================================================
 * 
 * CONCEPT OF BORDER:
 * A border is a substring which is both a proper prefix AND a proper suffix.
 * 
 * Example 1: String "xxxcxxx"
 *            x x x c x x x
 *            ^-----^-----^
 *            Prefix      Suffix
 *            
 *    Borders: "x", "xx", "xxx" (but NOT "xxxc")
 *    Widest border: "xxx"
 * 
 * Example 2: String "abcab"
 *            a b c a b
 *            ^-^   ^-^
 *            Prefix & Suffix
 *            
 *    Border: "ab"
 * 
 * Example 3: Pattern "ABACABAB"
 *            Index:  0 1 2 3 4 5 6 7
 *            Chars:  A B A C A B A B
 *                    ^-----------^-^  (AB is border)
 *                    ^-------^---^    (ABAB is border)
 *            
 *    Widest border of whole pattern: "ABAB"
 */

/*
 * ============================================================================
 * PREPROCESS SUFFIX - Build borderPosition[] and shift[] arrays
 * ============================================================================
 * 
 * PURPOSE: Handle cases when good suffix exists in pattern but character 
 *          before it doesn't match
 * 
 * WHAT IS borderPosition[i]?
 * - borderPosition[i] = starting index of the widest border of suffix from i to m-1
 * - If no border exists, borderPosition[i] = m
 * 
 * EXAMPLE with pattern "ABACABAB" (m=8):
 * 
 *    Index:     0  1  2  3  4  5  6  7
 *    Pattern:   A  B  A  C  A  B  A  B
 *    
 *    i=7: suffix = "B"       → no border → borderPosition[7] = 8
 *    i=6: suffix = "AB"      → no border → borderPosition[6] = 8
    i=5: suffix = "BAB"     → border "B" at index 7 → borderPosition[5] = 7
 *    i=4: suffix = "ABAB"    → border "AB" at index 6 → borderPosition[4] = 6
 *    i=3: suffix = "CABAB"   → no border → borderPosition[3] = 8
 *    i=2: suffix = "ACABAB"  → no border → borderPosition[2] = 8
 *    i=1: suffix = "BACABAB" → no border → borderPosition[1] = 8
 *    i=0: suffix = "ABACABAB"→ border "ABAB" at index 4 → borderPosition[0] = 4
 *    
 *    Final arrays:
 *    i:               0  1  2  3  4  5  6  7  8
 *    borderPosition:  4  8  8  8  6  7  8  8  9
 */
void preprocessSuffix(int *shift, int *borderPosition, char *pattern, int m)
{

    int i = m, j = m + 1;

    /* 
     * BASE CASE: Initialize borderPosition[m] = m + 1
     * At position m (beyond pattern), there's no suffix, so no valid border
     */
    borderPosition[i] = j;

    // Find borderPosition[i] from i = m to 0.
    while (i > 0)
    {

        /*
         * INNER LOOP: Find where pattern[i-1] matches pattern[j-1]
         * If they don't match, calculate shift and adjust j
         */
        while (j <= m && pattern[i - 1] != pattern[j - 1])
        {
            /*
             * SHIFT CALCULATION:
             * When pattern[i-1] != pattern[j-1], we've found a mismatch.
             * The shift tells us how far to move the pattern.
             * 
             * Visual example when mismatch at j=7:
             * 
             * Text:     X X X X C X X X
             * Pattern:  A B A C A B A B  (i=4, j=8 initially)
             *                       ↑
             *                     matched up to here, mismatch before
             * 
             * Shift pattern by (j-i):
             * Text:     X X X X C X X X
             * Pattern:      A B A C A B A B  (shifted by 3)
             */
            if (shift[j] == 0)
                shift[j] = j - i;

            /*
             * Jump to next border position
             * This is the key insight: we use previously computed borders
             * to speed up the search
             */
            j = borderPosition[j];
        }

        /*
         * MATCH FOUND: pattern[i-1] == pattern[j-1]
         * Record the border position for suffix starting at (i-1)
         */
        i--;
        j--;
        borderPosition[i] = j;
    }
}

/*
 * ============================================================================
 * PREPROCESS PREFIX - Fill remaining shift[] positions
 * ============================================================================
 * 
 * PURPOSE: Handle cases when good suffix doesn't exist in pattern, or exists
 *          but character before it matches (no shift calculated in preprocessSuffix)
 * 
 * STRATEGY: Use the widest border of the pattern for shifts
 * 
 * EXAMPLE with pattern "ABACABAB" (m=8):
 * 
 * After preprocessSuffix:
 *    i:              0  1  2  3  4  5  6  7  8
 *    shift:          0  0  0  0  0  0  0  3  0
 *    borderPosition: 4  8  8  8  6  7  8  8  9
 * 
 * borderPosition[0] = 4 means pattern has border "ABAB" starting at index 4
 * 
 * Fill missing shift values:
 *    - shift[0] = 4 (use widest border)
 *    - shift[1] = 4
 *    - shift[2] = 4
 *    - shift[3] = 4
 *    - shift[4] = 4 (at border start, use next border)
 *    - shift[5] = 4
 *    - shift[6] = 4
 *    - shift[7] = 3 (already set)
 *    - shift[8] = 4
 * 
 * Final shift array:
 *    i:     0  1  2  3  4  5  6  7  8
 *    shift: 4  4  4  4  4  4  4  3  4
 * 
 * MEANING: If mismatch occurs at position i, shift pattern by shift[i] positions
 */
void preprocessPrefix(int *shift, int *borderPosition, char *pattern, int m)
{
    int i, j;
    j = borderPosition[0]; // Start with widest border of entire pattern

    for (i = 0; i <= m; i++)
    {
        /*
         * Fill shift[i] if not already calculated in preprocessSuffix
         */
        if (shift[i] == 0)
            shift[i] = j;

        /*
         * If we've reached the border position, update to next border
         * This handles nested border structures
         */
        if (i == j)
            j = borderPosition[j];
    }
}

/*
 * ============================================================================
 * BOYER-MOORE SEARCH ALGORITHM
 * ============================================================================
 * 
 * MAIN SEARCH PROCESS - Uses preprocessed shift[] array
 * 
 * EXAMPLE: Search "ABACABAB" in "ABACABAB skjdfslk ABACABABPOIUYTREEWQABACABAB"
 * 
 * Step 1: Align pattern at text[0]
 *    Text:    A B A C A B A B  s k j d f s l k ...
 *    Pattern: A B A C A B A B
 *    Index:   0 1 2 3 4 5 6 7
 *             ↑               ↑
 *             Start comparing from right (j=7)
 *    
 *    Comparison: j=7,6,5,4,3,2,1,0 all match!
 *    Result: MATCH FOUND at index 0!
 *    Shift by shift[0] = 4
 * 
 * Step 2: Align pattern at text[4]
 *    Text:    A B A C A B A B  s k j d f s l k ...
 *    Pattern:         A B A C A B A B
 *    Index:           0 1 2 3 4 5 6 7
 *                                 ↑
 *    
 *    j=7: pattern[7]='B' vs text[4+7]=' ' → MISMATCH
 *    Shift by shift[7+1] = shift[8] = 4
 * 
 * Continue until pattern position > text length...
 * 
 * VISUALIZATION OF SHIFTING:
 *    
 *    Text:    X X X X C X X X Y Z ...
 *    Pattern: A B A C A B A B
 *    
 *    After shift[6] = 4:
 *    Text:    X X X X C X X X Y Z ...
 *    Pattern:         A B A C A B A B
 */
void boyerMooreAlgorithm(char *text, char *pattern)
{
    int s = 0, j; // s = shift/offset of pattern in text
    int m = strlen(pattern);
    int n = strlen(text);

    int borderPosition[m + 1], shift[m + 1];

    // Initialize shift array to 0
    for (int i = 0; i < m + 1; i++)
        shift[i] = 0;

    /*
     * PREPROCESSING PHASE
     * Build the shift[] and borderPosition[] lookup tables
     */
    preprocessSuffix(shift, borderPosition, pattern, m);
    preprocessPrefix(shift, borderPosition, pattern, m);

    /*
     * PRINT PREPROCESSED ARRAYS (for debugging)
     */
    // cout << "\nPattern: " << pattern << " (length=" << m << ")\n";
    // cout << "shift array:         ";
    // for(int i = 0; i <= m; i++) cout << shift[i] << " ";
    // cout << "\nborderPosition array: ";
    // for(int i = 0; i <= m; i++) cout << borderPosition[i] << " ";
    // cout << "\n\n";

    /*
     * SEARCH PHASE
     * Try all possible alignments of pattern in text
     */
    while (s <= n - m)
    {
        j = m - 1; // Start comparing from rightmost character

        /*
         * Compare pattern with text from right to left
         * 
         * Visual at position s:
         *    Text:    ... [text[s] text[s+1] ... text[s+j] ... text[s+m-1]] ...
         *    Pattern:     [patt[0] patt[1]  ... patt[j]  ... patt[m-1] ]
         *                                          ↑ comparing here
         */
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0)
        {
            /*
             * MATCH FOUND! All characters matched (j went from m-1 to -1)
             * 
             * Text:    ... [M A T C H E D] ...
             * Pattern:     [M A T C H E D]
             *          ↑ position s
             */
            cout << "Pattern found at index:" << s << endl;
            s += shift[0]; // Shift to find next occurrence
        }
        else
        {
            /*
             * MISMATCH at position j
             * 
             * Text:    ... [? ? ? ? X ? ? ?] ...
             * Pattern:     [A B A C Y B A B]
             *                       ↑ mismatch at j
             * 
             * Shift pattern by shift[j+1] positions
             */
            s += shift[j + 1];
        }
    }
}

/*
 * ============================================================================
 * COMPLETE EXAMPLE TRACE
 * ============================================================================
 * 
 * Text:    "ABACABAB skjdfslk ABACABABPOIUYTREEWQABACABAB"
 * Pattern: "ABACABAB"
 * 
 * PREPROCESSING RESULTS:
 * ----------------------
 * Pattern:          A  B  A  C  A  B  A  B
 * Index:            0  1  2  3  4  5  6  7
 * borderPosition:   4  8  8  8  6  7  8  8  (and [8]=9)
 * shift:            4  4  4  4  4  4  4  3  (and [8]=4)
 * 
 * SEARCH TRACE:
 * -------------
 * 
 * Position s=0:
 *    Text:    [A B A C A B A B] s k j d f s l k ...
 *    Pattern:  A B A C A B A B
 *    Result:  MATCH! → Print "Pattern found at index: 0"
 *    Shift:   s += shift[0] = 4 → s = 4
 * 
 * Position s=4:
 *    Text:    A B A C [A B A B   s k j d f s l k] ...
 *    Pattern:          A B A C A B A B
 *                                      ↑ mismatch at j=7
 *    Result:  Mismatch at pattern[7] vs text[11]
 *    Shift:   s += shift[8] = 4 → s = 8
 * 
 * Position s=8:
 *    Text:    A B A C A B A B [ s k j d f s l k] A B A C ...
 *    Pattern:                   A B A C A B A B
 *                               ↑ immediate mismatch
 *    Result:  Mismatch
 *    Shift:   s += shift[...] → continue...
 * 
 * Eventually finds matches at indices: 0, 18, 39
 * 
 * TIME COMPLEXITY:
 * ----------------
 * Preprocessing: O(m) where m = pattern length
 * Searching: O(n) best case, O(n*m) worst case
 *            where n = text length
 * 
 * SPACE COMPLEXITY: O(m)
 */
int main()
{
    char text[] = "ABACABAB skjdfslk ABACABABPOIUYTREEWQABACABAB";
    char pattern[] = "ABACABAB";

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "\nSearching...\n"
         << endl;

    boyerMooreAlgorithm(text, pattern);

    return 0;
}
