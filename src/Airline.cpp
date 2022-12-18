#include "Airline.h"
#include <string>

using namespace std;

Airline::Airline(string &code, string &name, string &callsign, string &country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}