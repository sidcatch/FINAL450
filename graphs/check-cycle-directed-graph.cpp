#include <iostream>
#include <list>

using namespace std;

const char WHITE = 'w';
const char GREY = 'g';
const char BLACK = 'b';

class Graph
{
  private:
    /* data */
    int n;
    list<int> *adj;

  public:
    Graph(int n);
    ~Graph();

    bool isCyclic();
    bool isCyclic(int, char *);
    void addEdge(int, int);
};

Graph::Graph(int n)
{
    this->n = n;
    this->adj = new list<int>[n];
}

Graph::~Graph()
{
    delete[] adj;
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}

bool Graph::isCyclic(int v, char *colors)
{

    colors[v] = GREY;

    for (auto i = adj[v].begin(); i != adj[v].end(); i++)

    {
        int a = *i;

        if (colors[a] == GREY)
            return true;

        if (colors[a] == WHITE && isCyclic(a, colors))
            return true;
    }

    colors[v] = BLACK;

    return false;
}

bool Graph::isCyclic()
{
    char *colors = new char[this->n];

    for (int v = 0; v < this->n; v++)
        colors[v] = WHITE;

    for (int v = 0; v < this->n; v++)
        if (colors[v] == WHITE && isCyclic(v, colors))
            return true;
    return false;
}

int main()
{

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    // g.addEdge(3, 3);

    if (g.isCyclic())
        cout << "Graph is cyclic";
    else
        cout << "Graph is NOT cyclic";

    return 0;
}