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

    printAllSubsequence(input.substr(1), output + input[0]);
}

int main()
{

    printAllSubsequence("abandadgfasd");

    return 0;
}