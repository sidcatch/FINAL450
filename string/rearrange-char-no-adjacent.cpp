#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

string rearrangeString(string str)
{
    unordered_map<char, int> freq;
    priority_queue<pair<int, char>> pq;

    // Calculate frequency of each character
    for (char ch : str)
    {
        freq[ch]++;
    }

    // Push characters and their frequencies into max heap
    for (auto &it : freq)
    {
        pq.push({it.second, it.first});
    }

    string result = "";
    pair<int, char> prev = {-1, '#'};

    while (!pq.empty())
    {
        pair<int, char> current = pq.top();
        pq.pop();

        result += current.second;
        current.first--;

        // If the previous character exists, push it back to the heap
        if (prev.first > 0)
        {
            pq.push(prev);
        }

        prev = current;

        // If no adjacent character possible
        if (pq.empty() && prev.first > 0)
        {
            return "Not possible";
        }
    }

    return result;
}

int main()
{
    string str = "aaabbc";
    string result = rearrangeString(str);
    cout << "Rearranged string: " << result << endl;

    return 0;
}
