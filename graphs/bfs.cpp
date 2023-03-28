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

    void printDist(T dest, T src, unordered_map<T, int> distances)
    {

        if (distances.find(dest) != distances.end())
            cout << distances[dest] << endl;
    }

    pair<unordered_map<T, T>, unordered_map<T, int>> bfs(T src /* , unordered_map<T, T> &parents, unordered_map<T, int> &distances, unordered_map<T, char> &colors */)
    {
        unordered_map<T, T> parents;
        unordered_map<T, int> distances;
        unordered_map<T, char> colors; // 'g', 'b', 'w'

        for (auto adjListItem : this->adjlist)
        {
            colors[adjListItem.first] = 'w';
        }

        distances[src] = 0;
        colors[src] = 'g';

        list<T> queue;

        queue.push_back(src);

        while (!queue.empty())
        {
            T current = queue.front();
            queue.pop_front();

            for (auto attached : this->adjlist[current])
            {
                if (colors[attached] == 'w')
                {

                    colors[attached] = 'g';
                    distances[attached] = distances[current] + 1;
                    parents[attached] = current;
                    queue.push_back(attached);
                }
            }

            colors[current] = 'b';
        }

        return make_pair(parents, distances);
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

    const int src = 6;
    auto bfsResult = g.bfs(src);

    g.printPathReverse(3, 1, bfsResult.first);
    g.printPath(3, src, bfsResult.first);
    cout << endl;
    g.printDist(3, src, bfsResult.second);

    cout << endl;

    return 0;
}