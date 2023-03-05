// #include <iostream>
// #include <stack>
// #include <string>

// using namespace std;

// int lenghtBalanced(string &s)
// {

//     int l = 0;
//     int max = l;

//     if (s.size() == 0)
//         return l;

//     stack<int> st;

//     int i = 0;
//     while (i < s.size())
//     {
//         if (s[i] == '(')
//         {
//             st.push(s[i]);
//             l++;
//         }

//         else if (!st.empty() /* && st.top() == '(' */)
//         {
//             st.pop();
//             l++;
//         }
//         else
//         {

//             l = 0;
//         }

//         if (max < l)
//             max = l;
//         i++;
//     }

//     if (st.empty())
//         return max;
//     else
//         return max - st.size();
// }

// int main()
// {
//     string s = "()(())(";

//     // string s = "()(())()";
//     // string s = "()(())((()))";
//     // string s = "((()))(())(";

//     cout << lenghtBalanced(s) << endl;

//     return 0;
// }