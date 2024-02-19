#include <iostream>
#include <string>

using namespace std;

void naiveStringMatcher(const string &T, const string &P)
{
    int n = T.length();
    int m = P.length();

    for (int s = 0; s <= n - m; ++s)
    {
        bool match = true;
        for (int j = 0; j < m; ++j)
        {
            if (P[j] != T[s + j])
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
}

int main()
{
    string T = "This C++ program defines a function naiveStringMatcher that takes two std::string arguments: T for the text and P for the pattern.";
    string P = "the";

    naiveStringMatcher(T, P);

    return 0;
}
