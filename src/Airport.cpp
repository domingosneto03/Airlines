#include "Airport.h"
#include <string>
#include "map"
using namespace std;

Airport::Airport(string code, string name, string city, string country, double latitude, double longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this-> longitude = longitude;
}

Airport::Airport(string code) {
    this->code = code;
    this->name = "";
    this->city = "";
    this->country = "";
    this->latitude = 0.0;
    this-> longitude = 0.0;
}

string Airport::getCode() const {
    return this->code;
}

string Airport::getName() const {
    return this->name;
}

string Airport::getCity() const {
    return this->city;
}

string Airport::getCountry() const {
    return this->country;
}

double Airport::getLatitude() const {
    return this->latitude;
}

double Airport::getLongitude() const {
    return this->longitude;
}

bool Airport::operator==(const Airport& other) const{
    return this->code == other.code;
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