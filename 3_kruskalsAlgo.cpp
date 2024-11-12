#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
};

class DisjointSet
{
public:
    vector<int> parent;

    DisjointSet(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            parent[rootX] = rootY; 
        }
    }
};

vector<Edge> kruskal(int n, vector<Edge> &edges)
{
    vector<Edge> result;
    DisjointSet ds(n);

    sort(edges.begin(), edges.end(), [](Edge &a, Edge &b)
         { return a.weight < b.weight; });

    for (Edge &edge : edges)
    {
        int u = edge.u;
        int v = edge.v;

        if (ds.find(u) != ds.find(v))
        {
            ds.unionSets(u, v);
            result.push_back(edge);
        }
    }

    return result;
}

int main()
{
    int n = 6; 
    int m = 9; 

    // Define the edges (u, v, weight)
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 3},
        {1, 2, 1},
        {1, 3, 2},
        {2, 3, 4},
        {2, 4, 5},
        {3, 4, 6},
        {3, 5, 7},
        {4, 5, 4}};

    vector<Edge> mst = kruskal(n, edges);

    cout << "Minimum Spanning Tree (MST):\n";
    for (Edge &e : mst)
    {
        cout << e.u << " - " << e.v << " : " << e.weight << endl;
    }

    return 0;
}
