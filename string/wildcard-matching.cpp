
#include <iostream>
#include <stdbool.h>
#include <stdio.h>
#include <string>

using namespace std;

// bool match(char *first, char *second)
// {

//     if (*first == '\0' && *second == '\0')
//         return true;

//     if (*first == '*')
//     {
//         while (*(first + 1) == '*')
//             first++;
//     }

//     if (*first == '*' && *(first + 1) != '\0' && *second == '\0')
//         return false;

//     if (*first == '?' || *first == *second)
//         return match(first + 1, second + 1);

//     if (*first == '*')
//         return match(first + 1, second) || match(first, second + 1);
//     return false;
// }

//Possible segmentation fault! Need to fix.
bool match2(string pattern, string text, int i, int j)
{

    cout << "i: " << i << " "
         << "j: " << j << endl;

    if (i == pattern.size() && j == text.size())
        return true;

    if (pattern[i] == '*')
    {
        while (pattern[i + 1] == '*')
            i++;
    }

    if (pattern[i] == '*' && i == pattern.size() && j == text.size())
        return false;

    if (pattern[i] == '?' || pattern[i] == text[j])
        return match2(pattern, text, i + 1, j + 1);

    if (pattern[i] == '*')
        return match2(pattern, text, i + 1, j) || match2(pattern, text, i, j + 1);
    return false;
}

void test(char *first, char *second)
{
    // match(first, second) ? puts("Yes") : puts("No");
    match2(first, second, 0, 0) ? puts("Yes") : puts("No");
    cout << endl;
}

int main()
{
    // test("g*ks", "geeks");
    // test("ge?ks*", "geeksforgeeks");
    test("g*k", "gee");
    // test("*pqrs",
    //      "pqrst");
    // test("abc*bcd", "abcdhghgbcd");
    // test("abc*c?d", "abcd");

    // test("*c*d", "abcd");
    // test("*?c*d", "abcd");
    // test("geeks**", "geeks");

    cout << endl;

    return 0;
}
