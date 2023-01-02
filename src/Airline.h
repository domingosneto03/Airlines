#include <string>

using namespace std;

#ifndef PROJECTAED_G24_AIRLINES_H
#define PROJECTAED_G24_AIRLINES_H

class Airline {

public:
    /**
    * Creates an object of the struct Airline.
    * @param code
    * @param name
    * @param callsign
    * @param country
    */
    Airline(string code, string name, string callsign, string country);

private:
    string code;
    string name;
    string callsign;
    string country;
};


#endif //PROJECTAED_G24_AIRLINES_H