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

    friend bool operator<(const Flights& a, const Flights& b) {
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
    static void setGraphNodes(graph &graph, unordered_map<string, int> &airportsIndex, unordered_set<Airport, AirportHash, EqualAirport> &airports);

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
    unordered_set<string> countriesReachable(int y, const string &airport);

    /**
    * calculates the number of cities that are possible to visit with a maximum number of flights
    * Time complexity - O(|V| + |E| + n) //n is the number of airports that the set has
    * @param y - number maximum of flights
    * @param airportCode - airport of departure
    */
    unordered_set<string> citiesReachable(int y, const string &airport);

    /**
    * Prints to the consolation the code of all nodes that are pivot points and the total
    * Time complexity - O(|E|)
    */
    void ArticulationPointsRede();

    /**
    * Statistics of a network, such as number of airports, number of flights, number of airlines, diameter and top-k of airports.
    * @param k - number to calculate the top-k
    * Time complexity - O(|E|)
    */
    void redeStatistics(int k);

    /**
    * Prints to the diameter of the code
    * Time complexity - O(|V| + |E|)
    */
    void diameter_Rede();

    /**
    * Statistics of a country, such as number of airports, number of flights, number of airlines and top-k of airports.
    * Time complexity - O(|V| * log(|V|) + |V| + |E|))
    */
    void countryStatistics(int k, string country);

    /**
    * Statistics of a country, such as number of airports, number of flights, number of airlines and top-k of airports.
    * Time complexity - O(|V| * log(|V|) + |V| + |E|))
    */
    vector<string> shortestPathAirports(const string& airport1, const string& airport2);

    /**
    * Calculates the shortest path (fewest flights) between two airports.
    * @param code1 - code of the departure airport
    * @param code2 - code of the departure airport
    * Time complexity - O(n) + O(|V| + |E|)
    */
    void shortestPath(const string& code1, const string& code2);

    /**
    * Checks out all the cities that exist at an airport.
    * @param city
    * Time complexity - O(n)
    * @return returns a vector with all airports and an index of 0
    */
    vector<pair<string,int>> airportCity(const string& city);

    /**
    * Calculates the shortest path (fewest flights) between a city and an airport.
    * @param code1 - city of the departure airport
    * @param code2 - code of the departure airport
    * Time complexity - O(n) + O(|V| + |E|)
    */
    void shortestCityPath(const string& code1, const string& code2);

    /**
    * Find the airports within x Km of me.
    * @param longitude - longitude of the departure airport
    * @param latitude - latitude of the departure airport
    * @param distance - maximum distance
    * Time complexity - O(n)
    */
    vector<pair<string,int>> findAirportsWithinDistance(double longitude, double latitude, double distance);

    /**
    * Calculates the shortest path (fewest flights) between a city and an airport.
    * @param longitude - longitude of the departure airport
    * @param latitude - latitude of the departure airport
    * @param code2 - code of the departure airport
    * @param distance - maximum distance
    * Time complexity - O(n) + O(|V| + |E|)
    */
    void shortestKmPath(double longitude, double latitude, string code2, double distance);

   /**
    * Calculates the existing minimum flight with a specified airline.
    * @param code1 - code of the departure airport
    * @param code2 - code of the departure airport
    * @param airline - airline name
    * Time complexity - O(n) + O(|V| + |E|)
    */
    void shortestAirlinePath(const string &code1, const string &code2, const string &airline);

    void shortestAirlineListPath(const string &code1, const string &code2, const unordered_set<string>& airlines);

private:
    unordered_set <Airport, AirportHash, EqualAirport> airportSet;
    vector<Flights> flightsVector = {};
    graph *graph1;
    unordered_map <string, int> airportIndex; //code e index
    vector <string> articulationPointsRede;

};

#endif //PROJECTAED_G24_APPLICATION_H