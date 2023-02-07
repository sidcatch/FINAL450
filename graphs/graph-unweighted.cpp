#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
  public:
    unordered_map<T, list<T>> adjlist;

    void addEdge(T u, T v, bool bidirec = 1)
    {

        adjlist[u].push_back(v);

        if (bidirec)
            adjlist[v].push_back(u);
        else if (this->adjlist.find(v) == this->adjlist.end())
            this->adjlist[v] = list<T>{};
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
};

int main()
{
    graph<char> g;
    g.addEdge('0', '1', 0);
    g.addEdge('0', '7', 0);
    g.addEdge('1', '7', 0);
    g.addEdge('1', '2', 0);
    g.addEdge('7', '8', 0);
    g.addEdge('2', '8', 0);
    g.addEdge('8', '6', 0);
    g.addEdge('2', '5', 0);
    g.addEdge('6', '5', 0);
    g.addEdge('2', '3', 0);
    g.addEdge('3', '3', 0);
    g.addEdge('3', '4', 0);
    g.addEdge('5', '4', 0);
    g.addEdge('7', '6', 0);
    g.print_adj();

    return 0;
}