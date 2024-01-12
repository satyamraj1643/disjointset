#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{

public:
    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        rank.resize(n + 1, 0);

        for(int i = 0; i<parent.size(); i++){
            parent[i] = i;
        }
    }


    int findUltimateParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionbyrank(int u, int v)
    {
        int up_u = findUltimateParent(u);
        int up_v = findUltimateParent(v);

        if (up_u == up_v)
            return;

        if (rank[up_u] > rank[up_v])
        {
            parent[up_v] = up_u;
        }
        else if (rank[up_u] < rank[up_v])
        {
            parent[up_u] = up_v;
        }
        else
        {
            parent[up_u] = up_v;
            rank[up_v]++;
        }
    }

    void unionbysize(int u, int v)
    {
        int up_u = findUltimateParent(u);
        int up_v = findUltimateParent(v);

        if (up_u == up_v)
            return;

        if (size[up_u] > size[up_v])
        {
            parent[up_v] = up_u;
            size[up_u] += size[up_v];
        }
        else if (size[up_v] > size[up_u])
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
        else
        {
            parent[up_u] = up_v;
            size[up_v] += size[up_u];
        }
    }
};

int main()
{

    DisjointSet ds(7);
    ds.unionbysize(1, 2);
    ds.unionbysize(2, 3);
    ds.unionbysize(4, 5);
    ds.unionbysize(6, 7);
    ds.unionbysize(5, 6);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same parent" << endl;
    }
    else
    {
        cout << "Not same parent" << endl;
    }

    ds.unionbysize(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7))
    {
        cout << "Same parent" << endl;
    }
    else
    {
        cout << "Not same parent" << endl;
    }

    return 0;
}
