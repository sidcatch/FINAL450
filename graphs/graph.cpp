#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
  public:
    unordered_map<T, list<pair<T, int>>> adjlist;

    void addEdge(T u, T v, int dist, bool bidirec = 1)
    {

        adjlist[u].push_back(make_pair(v, dist));

        if (bidirec)
            adjlist[v].push_back(make_pair(u, dist));
        else if (this->adjlist.find(v) == this->adjlist.end())
            this->adjlist[v] = list<pair<T, int>>{};
    }

    void print_adj()
    {
        for (auto n : adjlist)
        {
            cout << n.first << " : ";
            for (auto a : n.second)
            {
                cout << "( " << a.first << " , " << a.second << " ) ";
            }
            cout << endl;
        }
    }
};

int main()
{
    graph<char> g;
    g.addEdge('0', '1', 4, 0);
    g.addEdge('0', '7', 8, 0);
    g.addEdge('1', '7', 11, 0);
    g.addEdge('1', '2', 8, 0);
    g.addEdge('7', '8', 7, 0);
    g.addEdge('2', '8', 2, 0);
    g.addEdge('8', '6', 6, 0);
    g.addEdge('2', '5', 4, 0);
    g.addEdge('6', '5', 2, 0);
    g.addEdge('2', '3', 7, 0);
    g.addEdge('3', '3', 14, 0);
    g.addEdge('3', '4', 9, 0);
    g.addEdge('5', '4', 10, 0);
    g.addEdge('7', '6', 1, 0);
    g.print_adj();

    return 0;
}