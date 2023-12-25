#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string a)
{
    stack<char> s;

    for (int i = 0; i < a.size(); i++)
    {
        switch (a[i])
        {
        case '[':
            s.push(a[i]);
            break;
        case '(':
            s.push(a[i]);
            break;
        case '{':
            s.push(a[i]);
            break;
        case ']':
            if (s.empty() || s.top() != '[')
                return false;
            s.pop();
            break;
        case ')':

            if (s.empty() || s.top() != '(')
                return false;
            s.pop();
            break;
        case '}':
            if (s.empty() || s.top() != '{')
                return false;
            s.pop();
            break;
            // default:
            //     break;
        }
    }

    if (s.empty())
        return true;
    else
        return false;
}

int main()
{

    string a = "[()]{}{[()()]()}";

    cout << isBalanced(a) << endl;

    return 0;
}