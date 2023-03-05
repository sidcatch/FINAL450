// #include <iostream>
// #include <stack>
// #include <string>

// using namespace std;

// bool isVaild(string &s)
// {

//     if (s.size() == 0)
//         return true;

//     stack<int> st;

//     int i = 0;
//     while (i < s.size())
//     {
//         if (s[i] == '(')
//             st.push(s[i]);
//         else if (!st.empty() /* && st.top() == '(' */)
//         {
//             st.pop();
//         }
//         else
//         {
//             return false;
//         }
//         i++;
//     }

//     if (st.empty())
//         return true;
//     else
//         return false;
// }

// int main()
// {
//     // string s = "()(())(";

//     // string s = "()(())()";
//     // string s = "()(())((()))";
//     string s = "((()))(())(";

//     cout << isVaild(s) << endl;

//     return 0;
// }