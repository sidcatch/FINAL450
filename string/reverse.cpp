#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    cout << s << endl;

    cout << s.length() << endl;

    int i = 0;
    int j = s.length() - 1;

    while (i < j)
    {
        char temp = s[i];

        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }

    cout << s << endl;
}