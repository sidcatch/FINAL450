#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    string a = "what'sup";

    stack<char> s;

    for (int i = 0; i < a.length(); i++)
        s.push(a[i]);

    for (int i = 0; i < a.length(); i++)
        cout << a[i];
    cout << endl;

    for (int i = 0; i < a.length(); i++)
    {
        a[i] = s.top();
        s.pop();
    }

    for (int i = 0; i < a.length(); i++)
        cout << a[i];
    cout << endl;

    return 0;
}