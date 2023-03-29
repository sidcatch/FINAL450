#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
  public:
    unordered_map<T, unordered_set<T>> adjlist;

    void addEdge(T u, T v, bool bidirec = 0)
    {

        if (u == v)
            return;

        this->adjlist[u].insert(v);

        if (bidirec)
            this->adjlist[v].insert(u);
        else if (this->adjlist.find(v) == this->adjlist.end())
            this->adjlist[v] = unordered_set<T>{};
    }

    void addVertex(T u)
    {
        if (this->adjlist.find(u) == this->adjlist.end())
            this->adjlist[u] = unordered_set<T>{};
    }

    void print_adj()
    {
        for (auto n : adjlist)
        {
            cout << n.first << " : ";
            for (auto a : n.second)
            {
                cout << "( " << a << " ) ";
            }
            cout << endl;
        }
    }

    void topologicalPrint()
    {
        stack<T> s;
        unordered_map<T, char> colors; // 'g', 'b', 'w'
        for (auto adjListItem : this->adjlist)
            colors[adjListItem.first] = 'w';

        for (auto adjListItem : this->adjlist)
            if (colors[adjListItem.first] == 'w')
                dfsVisit(adjListItem.first, colors, s);

        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void dfsVisit(T current, unordered_map<T, char> &colors, stack<T> &s)
    {

        colors[current] = 'g';
        for (auto neighbour : this->adjlist[current])
            if (colors[neighbour] == 'w')
                dfsVisit(neighbour, colors, s);

        colors[current] = 'b';
        s.push(current);
    }
};

// a <--b
// |\   |
// | \  |
// V  / V
// c   d

void alienDictionaryOrderUtil(vector<string> &s, int start, int end, int currentCharIndex, graph<char> &g)
{

    while (s[start].size() <= currentCharIndex && start != end)
        start++;

    if (start == end)
        return;

    int newStart = start;
    int newEnd = start;
    while (newEnd <= end)
    {
        while (newEnd < end && s[newStart][currentCharIndex] == s[newEnd + 1][currentCharIndex])
            newEnd++;

        // cout << newStart << " " << newEnd << endl;
        alienDictionaryOrderUtil(s, newStart, newEnd, currentCharIndex + 1, g);

        newStart = newEnd + 1;

        if (newStart <= end)
        {
            // cout << s[newEnd][currentCharIndex] << " " << s[newStart][currentCharIndex] << endl;
            g.addEdge(s[newEnd][currentCharIndex], s[newStart][currentCharIndex]);
        }

        newEnd = newStart;
    }
}

void alienDictionaryOrder(vector<string> &s, int N, int K)
{
    graph<char> g;

    for (int i = 0; i < K; i++)
        g.addVertex('a' + i);

    alienDictionaryOrderUtil(s, 0, N - 1, 0, g);

    g.print_adj();

    g.topologicalPrint();
}

int main()
{

    vector<string> s = {"baa", "abcd", "abca", "cab", "cad"};
    int k = 4;

    // vector<string> s = {"caa", "aaa", "aab"};
    // int k = 3;

    alienDictionaryOrder(s, s.size(), k);

    // graph<char> g;
    // g.addEdge('b', 'a');
    // g.addEdge('a', 'c');
    // g.addEdge('d', 'a');
    // g.addEdge('b', 'd');

    // g.print_adj();

    // g.topologicalPrint();

    // cout << endl;

    return 0;
}