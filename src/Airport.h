#include <string>
using namespace std;

#ifndef PROJECTAED_G24_AIRPORT_H
#define PROJECTAED_G24_AIRPORT_H

class Airport {

public:
    /**
    * Creates an object of the struct Airport.
    * @param code
    * @param name
    * @param city
    * @param country
    * @param latitude
    * @param longitude
    */
    Airport(string &code, string &name, string &city, string &country, double &latitude, double &longitude);

    /**
    * This function computes the distance between two locations ( given with coordinates )
    * @param lat1 latitude of the first location
    * @param lon1 longitude of the first location
    * @param lat2 latitude of the second location
    * @param lon2 longitude of the second location
    * @return the distance between the given coordinates
    */
    static double haversine(double lat1, double lon1, double lat2, double lon2);

    /**
    * Returns the Airport's code.
    * Complexity : O(1)
    * @return code
    */
    string getCode();

    /**
    * Returns the Airport's name.
    * Complexity : O(1)
    * @return name
    */
    string getName();

    /**
    * Returns the Airport's city.
    * Complexity : O(1)
    * @return city
    */
    string getCity();

    /**
    * Returns the Airport's country.
    * Complexity : O(1)
    * @return country
    */
    string getCountry();

    /**
    * Returns the Airport's latitude.
    * Complexity : O(1)
    * @return latitude
    */
    double getLatitude();

    /**
    * Returns the Airport's longitude.
    * Complexity : O(1)
    * @return longitude
    */
    double getLongitude();

private:
    string code;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
};

#endif //PROJECTAED_G24_AIRPORT_H