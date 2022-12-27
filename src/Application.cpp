#include "Application.h"
#include "Airline.h"
#include "Airport.h"
#include "graph.h"
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <set>

using namespace std;

void Application() {

}

set<Airport*> Application::readAirports() {
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

set<Airline*> Application::readAirlines() {
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


set <Airport*> Application::teste() {
    set <Airport*> airports = readAirports();
    graph graph1(3019, true);
}