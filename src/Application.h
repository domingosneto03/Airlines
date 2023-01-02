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
    struct AirportHash {
        std::size_t operator()(const Airport& airport) const {
            size_t h=0;
            h = 37 * h + std::hash<std::string>()(airport.getCode());
            return h;
        }
    };

    struct EqualAirport {
        bool operator()(const Airport& airport1, const Airport& airport2) const {
            return airport1 == airport2;
        }
    };

    /**
    * Reads the file airports.csv and stores it in a unordered_set, using the Airport constructor.
    * Complexity : O(n)
    * @return an unordered_set with all airports
    */
    unordered_set<Airport, Application::AirportHash, Application::EqualAirport> readAirports();

    /**
    * Reads the file airlines.csv and stores it in a unordered_set, using the Airline constructor.
    * Complexity : O(n)
    * @return an unordered_set with all airlines
    */
    unordered_set<Airline *> readAirlines();

    /**
    * Reads the file flights.csv and stores it in a vector, using a Flights struct.
    * Complexity : O(n)
    * @return an vector with all flights
    */
    vector<Flights> readFlights();

     /**
     * Set the nodes information
     * Time complexity - O(|V|*log(|V|))
     * @param graph1 - graph with all nodes
     * @param AirportIndex - a map containing a index for each airport
     * @param airports - vector with all the airports
     */
    void setGraphNodes(graph &graph, unordered_map<string, int> &airportsIndex, unordered_set<Airport, AirportHash, EqualAirport> &airports);

    /**
    * Cleaning/removal of the edges between nodes in the graph
    * Time complexity - O(|E|)
    * @param graph - graph with all nodes
    */
    void clearEdges(graph &graph);

    /**
    * Creating the graph with all nodes and edges
    * Time complexity - O(n)
    */
    void createGraph();

    /**
    * Calculates the number of flights departing from a specific airport
    * Time complexity - O(n)
    * @param airportCode - airport of departure
    * @return int - number of flights
    */
    int numberFlights(const string& airportCode);

    /**
    * Calculates the number of airlines departing from a specific airport
    * Time complexity - O(|V| + |E|)
    * @param airportCode - airport of departure
    * @return int - number of airlines
    */
    int numberAirlines(const string& airportCode);

    /**
    * Calculates the number of destinations of flights departing from that airport
    * Time complexity - O(n)
    * @param airportCode - airport of departure
    * @return int - number of destinies
    */
    int numberDest(const string& airportCode);

    /**
    * calculates the number of countries it is possible to visit with a single flight from this airport
    * Time complexity - O(n)
    * @param airportCode - airport of departure
    * @return int - number of countries
    */
    int numberCountries(const string &airportCode);

    /**
    * calculates the number of airports that are possible to visit with a maximum number of flights
    * Time complexity - O(|V| + |E|)
    * @param y - number maximum of flights
    * @param airportCode - airport of departure
    */
    unordered_set<int> airportsReachable(int y, const string& airport);

    /**
    * calculates the number of countries that are possible to visit with a maximum number of flights
    * Time complexity - O(|V| + |E| + n) //n is the number of airports that the set has
    * @param y - number maximum of flights
    * @param airportCode - airport of departure
    */
    unordered_set<string> countriesReachabe(int y, const string &airport);

    /**
    * calculates the number of cities that are possible to visit with a maximum number of flights
    * Time complexity - O(|V| + |E| + n) //n is the number of airports that the set has
    * @param y - number maximum of flights
    * @param airportCode - airport of departure
    */
    unordered_set<string> citiesReachable(int y, const string &airport);

private:
    unordered_set <Airport, AirportHash, EqualAirport> airportSet;
    unordered_set<Airline *> airlineSet = {};
    vector<Flights> flightsVector = {};
    graph *graph1;
    unordered_map <string, int> airportIndex; //code e index

};

#endif //PROJECTAED_G24_APPLICATION_H