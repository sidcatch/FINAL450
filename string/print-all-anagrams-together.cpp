#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode
{
    bool isEnd;
    unordered_map<char, TrieNode *> children;
    vector<string> anagrams;
    TrieNode() : isEnd(false) {}
};

void insert(TrieNode *root, const string &word)
{
    TrieNode *curr = root;
    string sortedWord = word;
    sort(sortedWord.begin(), sortedWord.end());

    for (char ch : sortedWord)
    {
        if (curr->children.find(ch) == curr->children.end())
            curr->children[ch] = new TrieNode();
        curr = curr->children[ch];
    }

    curr->isEnd = true;
    curr->anagrams.push_back(word);
}

void printAnagramsUtil(TrieNode *root)
{
    if (!root)
        return;

    if (root->isEnd)
    {
        for (const string &anagram : root->anagrams)
            cout << anagram << " ";
    }

    for (auto &pair : root->children)
        printAnagramsUtil(pair.second);
}

void printAnagramsTogether(const vector<string> &wordArr)
{
    TrieNode *root = new TrieNode();

    for (const string &word : wordArr)
        insert(root, word);

    printAnagramsUtil(root);
}

int main()
{
    vector<string> wordArr = {"cat", "dog", "tac", "god", "act", "gdo"};
    printAnagramsTogether(wordArr);
    return 0;
}
