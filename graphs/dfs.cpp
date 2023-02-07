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

    void printPathReverse(T dest, T src, unordered_map<T, T> parents)
    {
        T current = dest;

        while (parents.find(current) != parents.end())
        {
            cout << current << " - ";
            current = parents[current];
        }

        cout << src << endl;
    }

    void printPath(T dest, T src, unordered_map<T, T> parents)
    {
        if (dest == src)
        {
            cout << dest;
        }

        else if (parents.find(dest) == parents.end())
        {
            cout << endl;
        }
        else
        {
            printPath(parents[dest], src, parents);
            cout << " - " << dest;
        }
    }

    void printStartAndEndTimes(unordered_map<T, int> startTimes, unordered_map<T, int> endTimes)
    {

        for (auto n : adjlist)
        {
            cout << n.first << " : ";
            cout << "( " << startTimes[n.first] << " , " << endTimes[n.first] << " ) ";
            cout << endl;
        }
    }

    tuple<unordered_map<T, T>, unordered_map<T, int>, unordered_map<T, int>> dfs(T src)
    {
        unordered_map<T, T> parents;
        unordered_map<T, int> startTimes;
        unordered_map<T, int> endTimes;
        unordered_map<T, char> colors; // 'g', 'b', 'w'
        int time = 0;

        for (auto adjListItem : this->adjlist)
        {
            colors[adjListItem.first] = 'w';
        }

        dfsVisit(src, time, parents, startTimes, endTimes, colors);

        for (auto adjListItem : this->adjlist)
        {
            if (colors[adjListItem.first] == 'w')
                dfsVisit(adjListItem.first, time, parents, startTimes, endTimes, colors);
        }

        return make_tuple(parents, startTimes, endTimes);
    }

    void dfsVisit(T current, int &time, unordered_map<T, T> &parents, unordered_map<T, int> &startTimes, unordered_map<T, int> &endTimes, unordered_map<T, char> &colors)
    {
        time += 1;
        colors[current] = 'g';
        startTimes[current] = time;

        for (auto neighbour : this->adjlist[current])
        {
            if (colors[neighbour] == 'w')
            {
                parents[neighbour] = current;
                dfsVisit(neighbour, time, parents, startTimes, endTimes, colors);
            }
        }

        time += 1;
        colors[current] = 'b';
        endTimes[current] = time;
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

    g.print_adj();

    const int src = 2;
    auto dfsResult = g.dfs(src);
    g.printPath(3, src, get<0>(dfsResult));
    cout << endl;
    g.printStartAndEndTimes(get<1>(dfsResult), get<2>(dfsResult));

    cout << endl;

    return 0;
}