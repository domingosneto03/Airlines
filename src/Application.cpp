#include "Application.h"
#include "Airline.h"
#include "Airport.h"
#include "graph.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void Application() {

}

unordered_set <Airport, Application::AirportHash, Application::EqualAirport> Application::readAirports() {
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
        airportSet.insert(Airport(code, name, city, country, latitude2, longitude2));
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

void Application::setGraphNodes(graph &graph, unordered_map<string, int> &airportsIndex, unordered_set<Airport, AirportHash, EqualAirport> &airports){
    int count=1;
    for (auto itr = airports.begin(); itr != airports.end(); itr++) {
        graph.nodes[count].code = itr->getCode();
        graph.nodes[count].name = itr->getName();
        graph.nodes[count].city = itr->getCity();
        graph.nodes[count].country = itr->getCountry();
        graph.nodes[count].latitude = itr->getLatitude();
        graph.nodes[count].longitude = itr->getLongitude();
        airportsIndex.insert(make_pair(itr->getCode(), count));
        count++;
    }
}

void Application::clearEdges(graph &graph) {
    for (int i = 1; i <= graph.n; i++) {
        graph.nodes[i].adj.clear();
    }
}

void Application::createGraph() {
    readAirports();
    this->graph1 = new graph(3019, true);
    setGraphNodes(*graph1, airportIndex, airportSet);
    flightsVector = readFlights();

    for (auto & i : flightsVector) {
        int src1 = 0;
        int trg1 = 0;
        string airline = i.airline;

        src1 = airportIndex[i.source];
        trg1 = airportIndex[i.target];

        Airport airport2 = Airport(i.source);
        auto itr = airportSet.find(airport2);
        double lon1 = itr->getLongitude();
        double lat1 = itr->getLatitude();

        Airport airport3 = Airport(i.target);
        auto itr2 = airportSet.find(airport3);
        double lon2 = itr2->getLongitude();
        double lat2 = itr2->getLatitude();

        double distance = haversine(lon1, lat1, lat2, lon2);
        graph1->addEdge(src1, trg1, airline, distance);
    }
}

int Application::numberFlights(const string& airportCode) {
    auto itr = airportIndex.find(airportCode);
    if(itr == airportIndex.end()){
        return -1;
    }
    return graph1->nodes[itr->second].adj.size();
}

int Application::numberAirlines(const string& airportCode) {
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

int Application::numberDest(const string& airportCode) {
    unordered_set <int> airlines = {};

    auto itr = airportIndex.find(airportCode);
    if(itr == airportIndex.end()){
        return -1;
    }

    for(auto& i : graph1->nodes[itr->second].adj) {
        airlines.insert(i.dest);
    }
    return airlines.size();
}

int Application::numberCountries(const string& airportCode) {
    unordered_set <string> countries = {};

    auto itr = airportIndex.find(airportCode);
    if(itr == airportIndex.end()){
        return -1;
    }

    for(auto& i : graph1->nodes[itr->second].adj) {
        countries.insert(graph1->nodes[i.dest].country);
    }
    return countries.size();
}

unordered_set <int> Application::airportsReachable(int y, const string& airport) {
    unordered_set <int> reachable;
    int index = airportIndex[airport];
    graph1->bfs(index);

    for (int i = 1; i <= graph1->n; i++) {
        if ((graph1->nodes[i].dist <= y && graph1->nodes[i].dist >= 1) and graph1->nodes[i].dist != airportIndex[airport]) {
            reachable.insert(i);
        }
    }
    return reachable;
}

unordered_set <string> Application::countriesReachable(int y, const string& airport) {
    unordered_set <string> countries;
    unordered_set <int> airports = airportsReachable(y,airport);
    string airportCode;

    for (auto a : airports) {
        for (auto i : airportIndex) {
            if (i.second == a) {
                airportCode = i.first;
                break;
            }
        }
        auto itr = airportSet.find(airportCode);
        countries.insert(itr->getCountry());
    }

    return countries;
}

unordered_set <string> Application::citiesReachable(int y, const string& airport) {
    unordered_set <string> cities;
    unordered_set <int> airports = airportsReachable(y,airport);
    string airportCode;

    for (auto a : airports) {
        for (auto i : airportIndex) {
            if (i.second == a) {
                airportCode = i.first;
                break;
            }
        }
        auto itr = airportSet.find(airportCode);
        cities.insert(itr->getCity());
    }

    return cities;
}

vector<vector<string>> Application::shortestPathAirports(const string& airport1, const string& airport2) {
    vector<vector<string>> flights;
    int s = airportIndex[airport1];
    int t = airportIndex[airport2];
    vector<string> airport_route = graph1->shortestPath_bfs(s,t);
    for(int i=1; i<airport_route.size(); i++) {
        string target = airport_route[i];
        string source = airport_route[i-1];
        for(auto x : flightsVector) {
            if(x.source == source && x.target == target)
                string airline = x.airline;
        }
        flights[i-1].push_back(source);
        flights[i-1].push_back(target);
        //flights[i-1].push_back(airline);
    }
    return flights;
}

void Application::ArticulationPointsRede() {
    vector<int> d(graph1->n, -1);
    vector<int> low(graph1->n, -1);
    vector<int> parent(graph1->n, -1);
    parent[0] = 0; //node da raiz da bfs
    int count=0;
    vector<bool> isArticulationPoint(graph1->n, false);

    for (int i = 0; i < graph1->n; i++) {
        if (!graph1->nodes[i].visited) {
            graph1->findArticulationPoints(i, d, low, parent, isArticulationPoint);
        }
    }

    for (int i = 0; i < graph1->n; i++) {
        if (isArticulationPoint[i]) {
            count++;
            articulationPointsRede.push_back(graph1->nodes[i].code);
            cout << graph1->nodes[i].code << endl;
        }
    }
    cout << "Total: " << count << endl;
}

void Application::diameter_Rede() {
    int diameter = 0;
    for(int i = 1; i < graph1->nodes.size(); i++) {
        graph1->bfs_diameter(i, diameter);
    }
    cout << "A rede apresenta um diametro de " << diameter << endl;
}

void Application::redeStatistics(int k) {
    // nodes, edges, airlines, diametro e top k
    int count=0;
    unordered_set <string> differentAirlines;
    vector<pair<string,int>> numFlights;

    for(const auto& n: graph1->nodes) {
        count += n.adj.size();
        pair<string, int> s = make_pair(n.code,n.adj.size());
        numFlights.push_back(s);
        for (auto a: n.adj) {
            differentAirlines.insert(a.airline);
        }
    }

    int numAirlines = differentAirlines.size();

    cout << "The network have " << graph1->n << " " << "and " << count << " flights in " << numAirlines << " " << "different airlines." << endl;
    cout << "Top" << k << " for number of flights:" << endl;

    sort(numFlights.begin(), numFlights.end(), [](const auto& p1, const auto& p2) {
        return p1.second > p2.second;
    });

    for(int i=0; i<k; i++) {
        cout << numFlights[i].first << " : " << numFlights[i].second << endl;
    }

    diameter_Rede();
}


void Application::countryStatistics(int k, string country) {
    // nodes, edges, airlines, diameter e top k
    int edges=0;
    unordered_set <string> differentAirports;
    unordered_set <string> differentAirlines;
    vector<pair<string,int>> numFlights;

    for(const auto& n: graph1->nodes) {
        if (n.country == country) {
            differentAirports.insert(n.code);
            edges+= n.adj.size();
            for (auto a : n.adj) {
                differentAirlines.insert(a.airline);
            }
        }
    }

    int numAirlines = differentAirlines.size();

    for(auto d: differentAirports) {
        int index = airportIndex[d];
        numFlights.emplace_back(d,graph1->nodes[index].adj.size());
    }
    cout << "In " << country << " we have " << differentAirports.size() << " airports and " << edges << " flights in " << numAirlines << " " << "different airlines." << endl;
    cout << "Top" << k << " for number of flights:" << endl;

    sort(numFlights.begin(), numFlights.end(), [](const auto& p1, const auto& p2) {
        return p1.second > p2.second;
    });

    for(int i=0; i<k; i++) {
        cout << numFlights[i].first << " : " << numFlights[i].second << endl;
    }
}