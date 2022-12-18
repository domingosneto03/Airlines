#ifndef UNTITLED_FILES_H
#define UNTITLED_FILES_H

#include <set>
#include "Airport.h"
#include "Airline.h"

class Application {
public:
    set<Airport *> readAirports();
    set<Airline *> readAirlines();

private:
    set<Airport *> airportSet = {};
    set<Airline *> airlineSet = {};
};




#endif //UNTITLED_FILES_H
