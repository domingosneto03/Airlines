#include "Application.h"
#include "Airline.h"
#include "Airport.h"
#include "graph.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Application() {

}

unordered_set<Airport*> Application::readAirports() {
    fstream fin;
    fin.open("../dataset/airports.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    int count = 0;
    while (true) {
        row.clear();
        getline(fin, line);
        if (line == "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (count == 0) {
            count++;
            continue;
        }
        string code = row[0];
        string name = row[1];
        string city = row[2];
        string country = row[3];
        string latitude = row[4];
        string longitude = row[5];

        double latitude2 = stod(latitude);
        double longitude2 = stod(longitude);
        airportSet.insert(new Airport(code, name, city, country, latitude2, longitude2));
    }
    return airportSet;
}

unordered_set<Airline*> Application::readAirlines() {
    fstream fin;
    fin.open("../dataset/airlines.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    int count = 0;


    while (true) {
        row.clear();
        getline(fin, line);
        if (line == "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (count == 0) {
            count++;
            continue;
        }
        string code = row[0];
        string name = row[1];
        string callsign = row[2];
        string country = row[3];

        airlineSet.insert(new Airline(code, name, callsign, country));
    }
    return airlineSet;
}

vector<Flights> Application::readFlights() {
    fstream fin;
    fin.open("../dataset/flights.csv", ios::in);
    vector<string> row;
    string line, word, temp;
    int count = 0;
    while (true) {
        row.clear();
        getline(fin, line);
        if (line == "") break;
        stringstream s(line);
        while (getline(s, word, ',')) {
            row.push_back(word);
        }
        if (count == 0) {
            count++;
            continue;
        }
        string source = row[0];
        string target = row[1];
        string airline = row[2];

        Flights flights;
        flights.source = source;
        flights.target = target;
        flights.airline = airline;
        flightsVector.push_back(flights);
    }
    return flightsVector;
}

void Application::setGraphNodes(graph &graph, unordered_map<string, int> &airportsIndex, unordered_set<Airport*> &airports){
    int count=1;
    for (auto itr = airports.begin(); itr != airports.end(); itr++) {
        graph.nodes[count].code = (*itr)->getCode();
        graph.nodes[count].name = (*itr)->getName();
        graph.nodes[count].city = (*itr)->getCity();
        graph.nodes[count].country = (*itr)->getCountry();
        graph.nodes[count].latitude = (*itr)->getLatitude();
        graph.nodes[count].longitude = (*itr)->getLongitude();
        airportsIndex.insert(make_pair((*itr)->getCode(), count));
        count++;
    }
}

void Application::clearEdges(graph &graph) {
    for (int i = 1; i <= graph.n; i++) {
        graph.nodes[i].adj.clear();
    }
}

void Application::createGraph() {
    unordered_set<Airport*> airports = readAirports();
    this->graph1 = new graph(3019, true);
    setGraphNodes(*graph1, airportIndex, airports);
    flightsVector = readFlights();

    for (int i=0; i < flightsVector.size(); i++) {
        int src1 = 0;
        int trg1 = 0;
        double lon1 = 0.0;
        double lat1 = 0.0;
        double lon2 = 0.0;
        double lat2 = 0.0;
        double distance = 0.0;
        string airline = flightsVector[i].airline;

        for (auto m : airportIndex) {
            if (m.first == flightsVector[i].source) {
                src1=m.second;
            }
            if(m.first == flightsVector[i].target) {
                trg1 = m.second;
            }
            if(src1!=0 && trg1!=0) break;
        }

        for (auto a : airports) {
            if (a->getCode() == flightsVector[i].source) {
                lon1 = a->getLongitude();
                lat1 = a->getLatitude();
            }
            if (a->getCode() == flightsVector[i].target) {
                lon2 = a->getLongitude();
                lat2 = a->getLatitude();
            }
            if(lon1!=0.0 && lon2!=0.0) ;
        }
        distance = haversine(lon1, lat1, lat2, lon2);
        graph1->addEdge(src1, trg1, airline, distance);
    }
}

int Application::numberFlights(string airportCode) {
    auto itr = airportIndex.find(airportCode);
    if(itr == airportIndex.end()){
        return -1;
    }
    return graph1->nodes[itr->second].adj.size();
}

int Application::numberAirlines(string airportCode) {
    unordered_set <string> airlines = {};

    auto itr = airportIndex.find(airportCode);
    if(itr == airportIndex.end()){
        return -1;
    }

    for(auto i : graph1->nodes[itr->second].adj) {
        airlines.insert(i.airline);
    }
    return airlines.size();
}

int Application::numberDest(string airportCode) {
    unordered_set <int> airlines = {};

    auto itr = airportIndex.find(airportCode);
    if(itr == airportIndex.end()){
        return -1;
    }

    for(auto i : graph1->nodes[itr->second].adj) {
        airlines.insert(i.dest);
    }
    return airlines.size();
}