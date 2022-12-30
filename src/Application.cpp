#include "Application.h"
#include "Airline.h"
#include "Airport.h"
#include "graph.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

void Application() {

}

vector<Airport*> Application::readAirports() {
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
        airportVector.push_back(new Airport(code, name, city, country, latitude2, longitude2));
    }
    return airportVector;
}

vector<Airline*> Application::readAirlines() {
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

        airlineVector.push_back(new Airline(code, name, callsign, country));
    }
    return airlineVector;
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

void Application::setGraphNodes(graph &graph, map<string, int> &airportsIndex, vector<Airport*> &airports){
    for (unsigned int i = 1; i < graph.getNodes().size(); i++) {
        graph.nodes[i].code = airports[i - 1]->getCode();
        graph.nodes[i].name = airports[i - 1]->getName();
        graph.nodes[i].city = airports[i - 1]->getCity();
        graph.nodes[i].country = airports[i - 1]->getCountry();
        graph.nodes[i].latitude = airports[i - 1]->getLatitude();
        graph.nodes[i].longitude = airports[i - 1]->getLongitude();
        airportsIndex.insert(make_pair(airports[i - 1]->getCode(), i));
    }
}

void Application::clearEdges(graph &graph) {
    for (int i = 1; i <= graph.n; i++) {
        graph.nodes[i].adj.clear();
    }
}

void Application::createGraph() {
    vector<Airport*> airports = readAirports();
    this->graph1 = new graph(3019, true);
    map<string, int> airportIndex;
    setGraphNodes(*graph1, airportIndex, airports);
    for (auto i: graph1->getNodes()) {
        cout << i.name << endl;
    }
}