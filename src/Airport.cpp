#include "Airport.h"
#include <string>
#include <cmath>
#include "map"
using namespace std;

Airport::Airport(string &code, string &name, string &city, string &country, double &latitude, double &longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this-> longitude = longitude;
}

double Airport::haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}


string Airport::getCode() {
    return this->code;
}

string Airport::getName() {
    return this->name;
}

string Airport::getCity(){
    return this->city;
}

string Airport::getCountry() {
    return this->country;
}

double Airport::getLatitude() {
    return this->latitude;
}

double Airport::getLongitude() {
    return this->longitude;
}

/**
 * This function finds the index of a given airport
 * @param airport code of the airport
 * @param airportsMap map where the key is the code of the airport and the value is the airport index
 * @return the airport index
 */
int getAirportIndex(const string& airport, const map<string,int>& airports){
    for(const auto& a : airports){
        if(airport == a.first)
            return a.second;
    }
    return -1;
}