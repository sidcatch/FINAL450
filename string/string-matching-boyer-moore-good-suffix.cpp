#include <bits/stdc++.h>
using namespace std;

// A border is a substring which is both a proper prefix and a proper suffix of a string. For example, for a string xxxcxxx, x is a border, xx is a border, xxx too. But xxxc is not. The widest border is xxx. For simplicity, In this code simply border refers to the widest border. As another example, for string abcab, ab is the border.

// When the good suffix exists somewhere in the pattern itself and character before the good suffix does not match
void preprocessSuffix(int *shift, int *borderPosition, char *pattern, int m)
{

    int i = m, j = m + 1;
    // borderPosition[i] should be start position of border of suffix starting at i. if no border of a suffix exists then start position of border is taken as m. For example, for a pattern aabbccaacc, at postion i=4, the suffix is ccaacc, and the widest border for that is cc (p[8]p[9]), so j = f[i=4] = 8.
    // Observation:- If y == borderPosition[x] and y < m, then p[x] == p[y].

    borderPosition[i] = j;

    // Find borderPosition[i] from i = m to 0.
    while (i > 0)
    {

        while (j <= m && pattern[i - 1] != pattern[j - 1])
        {

            // // cout << "p[" << i << "]:" << pattern[i] << ", "
            // //      << "p[" << j << "]:" << pattern[j] << endl;

            if (shift[j] == 0)    // Once shift is calcualted, p[i] could again match p[j] for a smaller value of i in a later iteration. But we want to ignore this match that is further apart.
                shift[j] = j - i; // j == m or p[i] matches p[j] (borderPosition[i] = j before entering this while loop), but p[i-1] != p[j-1], so we shift from i to j, that that is s[j] = j - i.

            j = borderPosition[j]; // Since p[i-1] != p[j-1], to find borderPosition[i - 1] we have to continue our search to the right so j moves to the right. Set j to the  start position of the border of suffix starting at j i.e. borderPosition[j]. Now since j is start of a border position and p[i] matches p[j] (even after j = borderPosition[j]), next time if the loop condition fails i.e. p[i-1] == p[j-1] we would have found the border for suffix starting at i - 1 i.e. borderPosition[i - 1] will be j - 1.
        }

        // Since p[i-1] is matched with p[j-1] then we have found the border suffix starting at i - 1, then store the border. So borderPosition[i - 1] should be j - 1.
        i--;
        j--; // Side note:- If there is no border for a particular i then in the above while loop j will become m + 1. In this line it will become m, so in the below line, borderPosition[i] = m.
        borderPosition[i] = j;
    }
}

// When the good suffix does not exists somewhere in the pattern itself and or it exist but character before the good suffix do not match
void preprocessPrefix(int *shift, int *borderPosition, char *pattern, int m)
{
    int i, j;
    j = borderPosition[0];
    for (i = 0; i <= m; i++)
    {

        if (shift[i] == 0)
            shift[i] = j; // In this case, regardless of where the mismatch is, simply shift with the amount equivalent to the start position of the next widest border.

        // If suffix becomes shorter than the widest border, use the position of the next widest border as the value of j.
        if (i == j)
            j = borderPosition[j];
    }
}

void boyerMooreAlgorithm(char *text, char *pattern)
{
    // s is a shift of the pattern concerning input text.
    int s = 0, j;
    int m = strlen(pattern);
    int n = strlen(text);

    // An array to store the shifts and borderPosition will store the widest border of the pattern for every suffix.
    int borderPosition[m + 1], shift[m + 1];

    // initialize all occurrences of the shift to 0
    for (int i = 0; i < m + 1; i++)
        shift[i] = 0;

    // First performing the preprocessing
    preprocessSuffix(shift, borderPosition, pattern, m);
    preprocessPrefix(shift, borderPosition, pattern, m);

    while (s <= n - m)
    {

        j = m - 1;

        // If the pattern and text are matching, keep on reducing the j variable.
        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        // If the current shift of the pattern represents a valid match with the text, then j will become -1.
        if (j < 0)
        {
            cout << "Pattern found at index:" << s << endl;
            s += shift[0];
        }
        else
            // pattern[i] != pattern[s+j] so Shifting the pattern so that the bad character of the text is aligned
            s += shift[j + 1];
    }
}

int main()
{
    char text[] = "ABACABAB skjdfslk ABACABABPOIUYTREEWQABACABAB";
    char pattern[] = "ABACABAB";

    boyerMooreAlgorithm(text, pattern);

    return 0;
}
