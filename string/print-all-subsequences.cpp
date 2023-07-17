#include <iostream>
#include <string>

using namespace std;

void printAllSubsequence(string input, string output = "")
{
    if (input.length() == 0)
    {
        cout << output << endl;
        return;
    }

    printAllSubsequence(input.substr(1), output);
    // cout << output << " :Not includeing" << endl;
    printAllSubsequence(input.substr(1), output + input[0]);
    // cout << output << " : Includeing" << endl;
}

int main()
{
    cout << "start" << endl;
    printAllSubsequence("abc");

    return 0;
}