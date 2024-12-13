#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

int find(int u, vector<int> &parent)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent[u], parent);
    }
    return parent[u];
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    int rootU = find(u, parent);
    int rootV = find(v, parent);

    if (rootU != rootV)
    {
        if (rank[rootU] > rank[rootV])
        {
            parent[rootV] = rootU;
        }
        else if (rank[rootU] < rank[rootV])
        {
            parent[rootU] = rootV;
        }
        else
        {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int kruskalMST(int n, vector<Edge> &edges)
{
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n + 1);
    vector<int> rank(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    int mstWeight = 0;
    for (auto edge : edges)
    {
        if (find(edge.u, parent) != find(edge.v, parent))
        {
            mstWeight += edge.weight;
            unionSet(edge.u, edge.v, parent, rank);
        }
    }

    return mstWeight;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    cout << kruskalMST(n, edges) << endl;

    return 0;
}
