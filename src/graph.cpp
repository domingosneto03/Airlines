#include "graph.h"
#include <map>

graph::graph(int num, bool dir) : n(num), hasDir(dir), nodes(num + 1) {

}

void graph::addEdge(int src, int dest, string airline, double weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight, airline});
    if (!hasDir) nodes[dest].adj.push_back({src, weight, airline});
}

void graph::bfs (int v) {
    for (int i=1; i<=n; i++) {
        nodes[i].visited = false;
        nodes[i].dist = -1;
    }
    queue<int> q;
    q.push(v);
    nodes[v].dist = 0;
    nodes[v].visited = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const auto& e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].dist = nodes[u].dist + 1;
                nodes[w].pred = u;
            }
        }
    }
}

void graph::bfs_diameter(int v, int& diameter) {
    for (int i=1; i<=n; i++) {
        nodes[i].visited = false;
        nodes[i].dist = -1;
    }
    queue<int> q;
    q.push(v);
    nodes[v].dist = 0;
    nodes[v].visited = true;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (const auto& e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].dist = nodes[u].dist + 1;
                if(nodes[w].dist > diameter) diameter = nodes[w].dist;
                nodes[w].pred = u;
            }
        }
    }
}

list<tuple<string,string>> graph::getPath(int a, int b) {
    list<tuple<string,string>> path;
    if (nodes[b].dist == INT_MAX / 2) return path;
    path.emplace_back(nodes[b].code, nodes[b].name);
    int v = b;
    while (v != a) {
        v = nodes[v].pred;
        path.push_front(make_tuple(nodes[v].code, nodes[v].name));
    }
    return path;
}

void graph::findArticulationPoints(int u, vector<int>& d, vector<int>& low, vector<int>& parent, vector<bool>& isArticulationPoint) {
    static int index = 0;
    nodes[u].visited = true;
    d[u] = low[u] = ++index;
    int children = 0;

    for (const Edge& e : nodes[u].adj) {
        int v = e.dest;
        if (!nodes[v].visited) {
            children++;
            parent[v] = u;
            findArticulationPoints(v, d, low, parent, isArticulationPoint);
            low[u] = min(low[u], low[v]);
            if (parent[u] == -1 && children > 1) {
                isArticulationPoint[u] = true;
            }
            if (parent[u] != -1 && low[v] >= d[u]) {
                isArticulationPoint[u] = true;
            }
        }
        else if (v != parent[u])
            low[u] = min(low[u], d[v]);
    }
}