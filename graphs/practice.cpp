#include <bits/stdc++.h>
using namespace std;
template <typename T>
class graph
{
  public:
    unordered_map<T, list<T>> adjlist;

    void addEdge(T u, T v, bool bidirec = 1)
    {

        this->adjlist[u].push_back(v);

        if (bidirec)
            this->adjlist[v].push_back(u);
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
    graph<int> g;
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(4, 5, 0);
    g.addEdge(5, 2, 0);

    g.addEdge(1, 6, 0);
    g.addEdge(6, 5, 0);

    cout << endl;

    return 0;
}