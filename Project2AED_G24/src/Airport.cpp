#include "Airport.h"
#include <string>
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