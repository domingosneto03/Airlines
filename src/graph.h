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
    * @param nodes - number of nodes
    * @param dir - direction
    */
    graph(int nodes, bool dir = false);

    /**
    * Add edge from source to destination with a certain weight
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
    * Breadth-first search through the graph \n
    * @return nodes
    */
    vector<Node> getNodes(){
        return nodes;
    }

    /**
    * Breadth-first search through the graph \n
    * @param v - origin node index
    */
    void bfs(int v);

};

#endif //PROJECTAED_G24_GRAPH_H