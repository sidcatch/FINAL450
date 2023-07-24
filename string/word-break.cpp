
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

const unordered_set<string> dictionary = {"mobile", "samsung", "sam", "sung", "man", "mango", "icecream", "and", "go", "i", "like", "ice", "cream"};

int dictionaryContains(string word)
{
    return dictionary.find(word) != dictionary.end();
}

bool wordBreak(string str)
{
    int size = str.size();

    if (size == 0)
        return true;

    for (int i = 1; i <= size; i++)
    {

        if (dictionaryContains(str.substr(0, i)) &&
            wordBreak(str.substr(i, size - i)))
            return true;
    }

    return false;
}

int main()
{
    wordBreak("ilikesamsung") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("iiiiiiii") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmango") ? cout << "Yes\n" : cout << "No\n";
    wordBreak("samsungandmangok") ? cout << "Yes\n" : cout << "No\n";
    return 0;
}
