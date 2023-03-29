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

int main()
{
    graph<int> g;
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);
    g.addEdge(2, 4, 0);
    g.addEdge(4, 5, 0);
    // g.addEdge(5, 2, 0);

    g.addEdge(1, 6, 0);
    g.addEdge(6, 5, 0);

    g.print_adj();
    cout << endl;
    g.topologicalPrint();

    cout << endl;

    return 0;
}