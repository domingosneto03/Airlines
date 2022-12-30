#ifndef PROJECTAED_G24_APPLICATION_H
#define PROJECTAED_G24_APPLICATION_H

#include "Airport.h"
#include "Airline.h"
#include "graph.h"
#include <vector>
#include <map>


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
    vector<Airport *> readAirports();
    vector<Airline *> readAirlines();
    vector<Flights> readFlights();

    /**
     * Set the nodes information
     * Time complexity: O(n*log(n))
     * @param graph1 - graph with all nodes
     * @param AirportIndex - a map containing a index for each airport
     * @param airports - vector with all the airports
     */
    void setGraphNodes(graph &graph, std::map<string, int> &airportsIndex, vector<Airport*> &airports);

    /**
    * Cleaning/removal of the edges between nodes in the graph
    * @param graph - graph with all nodes
    */
    void clearEdges(graph &graph);

    void createGraph();


private:
    vector<Airport *> airportVector = {};
    vector<Airline *> airlineVector = {};
    vector<Flights> flightsVector = {};
    graph *graph1 = NULL;
};

#endif //PROJECTAED_G24_APPLICATION_H