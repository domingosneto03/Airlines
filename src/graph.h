#ifndef PROJECTAED_G24_GRAPH_H
#define PROJECTAED_G24_GRAPH_H

#include <vector>
#include <list>
#include <iostream>
#include <queue>

using namespace std;

class graph {
public:
    struct Edge {
        int dest;
        double weight;
        string airline;
    };

    struct Node {
        list<Edge> adj;
        double dist;
        int pred;
        bool visited;
        string code;
        string name;
        string city;
        string country;
        double latitude;
        double longitude;
    };

    int n;
    bool hasDir;
    vector<Node> nodes;

    /**
    * Constructor
    * Time complexity : O(1)
    * @param nodes - number of nodes
    * @param dir - direction
    */
    graph(int nodes, bool dir = false);

    /**
    * Add edge from source to destination with a certain weight
    * Time complexity : O(1)
    * @param src - source airport
    * @param dest - destination airport
    * @param airline - selected airline
    * @param weight
    */
    void addEdge(int src, int dest, string airline, double weight = 1);

    /**
    * This function returns the path created by the chosen traversal algorithm
    * @param a - airport index of origin
    * @param b - airport index of destination
    * @return - list of tuples with the airports information
    */
    list<tuple<string,string>> getPath(int a, int b);

    /**
    * Breadth-first search through the graph
    * Time complexity - O(|V| + |E|)
    * @param v - origin node index
    */
    void bfs(int v);

    /**
    * Breadth-first, to calculate diameter, search through the graph
    * Time complexity - O(|V| + |E|)
    * @param v - origin node index
    * @param v - maximum distance between two nodes
    */
    void bfs_diameter(int v, int &diameter);

    /**
    * Breadth-first, to calculate the shortest path, search through the graph
    * Time complexity - O(|V| + |E|)
    * @param v - origin node index
    * @param v - target node index
    */
    vector<string> shortestPath_bfs(int v, int t);

    /**
    * Breadth-first, to calculate the shortest path with an specific airline, search through the graph
    * Time complexity - O(|V| + |E|)
    * @param v - origin node index
    * @param airline - airline name
    */
    vector<string> shortestAirlinePath_bfs(int v, const string &airline);


    /**
    * Find articulation Points
    * Time complexity - O(|V| + |E|)
    * @param u - origin node index
    * @param d - stores the order in which nodes are visited
    * @param small - stores the smallest visit index number of all vertices that can be reached from the vertex currently being visited, including itself.
    * @param parent - stores the parent vertex of each vertex in the depth search tree.
    * @param isArticulationPoint - stores a boolean value indicating whether each vertex is a pivot point or not.
    */
    void findArticulationPoints(int u, vector<int> &d, vector<int> &small, vector<int> &parent, vector<bool> &isArticulationPoint);


};

#endif //PROJECTAED_G24_GRAPH_H