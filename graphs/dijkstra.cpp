#include <iostream>
#include <limits.h>
#include <list>
#include <queue>
#include <utility>

using namespace std;

struct Comparator
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};

class Graph
{
  private:
    int n;
    list<pair<int, int>> *adj;

  public:
    Graph(int n);
    ~Graph();
    void addEdge(int, int, int);

    void shortestPaths(int src, int *&distances, int *&parents);
    void printShortestPath(int src, int dest, int *parents);
};

Graph::Graph(int n)
{
    this->n = n;
    this->adj = new list<pair<int, int>>[n];
}

Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(int u, int v, int w = 0)
{
    adj[u].push_back(make_pair(v, w));
}

void Graph::shortestPaths(int src, int *&distances, int *&parents)
{

    priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> q;

    for (int i = 0; i < this->n; i++)
    {
        distances[i] = INT_MAX;
        parents[i] = -1;
    }

    distances[src] = 0;

    q.push(make_pair(src, distances[src]));

    while (!q.empty())
    {
        int u = q.top().first;
        int distance = q.top().second;

        q.pop();

        for (auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int v = (*i).first;
            int w = (*i).second;

            if (distances[v] > distance + w)
            {
                distances[v] = distance + w;
                parents[v] = u;

                q.push(make_pair(v, distances[v]));
            }
        }
    }
}

void Graph::printShortestPath(int src, int dest, int *parents)
{
    if (dest == src)
    {
        cout << src << " ";
        return;
    }

    if (parents[dest] == -1)
        return;

    Graph::printShortestPath(src, parents[dest], parents);
    cout << dest << " ";
}

int main()
{

    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    // g.addEdge(7, 8, 7);
    g.addEdge(7, 8, 1);

    int *distances = new int[V];
    int *parents = new int[V];

    g.shortestPaths(0, distances, parents);

    g.printShortestPath(0, 8, parents);
    cout << endl;
    g.printShortestPath(0, 4, parents);
    cout << endl;

    return 0;
}