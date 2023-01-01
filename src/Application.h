#ifndef PROJECTAED_G24_APPLICATION_H
#define PROJECTAED_G24_APPLICATION_H

#include "Airport.h"
#include "Airline.h"
#include "graph.h"
#include <vector>
#include <unordered_map>
#include <unordered_set>

struct Flights {
    string source;
    string target;
    string airline;

    friend bool operator<(Flights a, Flights b) {
        if (b.source == a.source) {
            if (b.target == a.target) {
                return b.airline < a.airline;
            } else {
                return b.target < a.target;
            }
        } else {
            return b.source < a.source;
        }
    }
};


class Application {

public:
    unordered_set<Airport *> readAirports();
    unordered_set<Airline *> readAirlines();
    vector<Flights> readFlights();

    /**
     * Set the nodes information
     * Time complexity: O(n*log(n))
     * @param graph1 - graph with all nodes
     * @param AirportIndex - a map containing a index for each airport
     * @param airports - vector with all the airports
     */
    void setGraphNodes(graph &graph, unordered_map<string, int> &airportsIndex, unordered_set<Airport*> &airports);

    /**
    * Cleaning/removal of the edges between nodes in the graph
    * @param graph - graph with all nodes
    */
    void clearEdges(graph &graph);

    void createGraph();
    int numberFlights(string airportCode);
    int numberAirlines(string airportCode);
    int numberDest(string airportCode);

private:
    unordered_set<Airport *> airportSet = {};
    unordered_set<Airline *> airlineSet = {};
    vector<Flights> flightsVector = {};
    graph *graph1 = NULL;
    unordered_map <string, int> airportIndex; //code e index

};

#endif //PROJECTAED_G24_APPLICATION_H