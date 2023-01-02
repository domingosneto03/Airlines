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