#ifndef PROJECTAED_G24_AIRPORT_H
#define PROJECTAED_G24_AIRPORT_H

#include <string>
using namespace std;
#include <cmath>

class Airport {

public:
    /**
    * Creates an object of the struct Airport.
    * Time complexity : O(1)
    * @param code
    * @param name
    * @param city
    * @param country
    * @param latitude
    * @param longitude
    */
    Airport(string code, string name, string city, string country, double latitude, double longitude);

    /**
    * Creates an object of the struct Airport, with only a code.
    * Time complexity : O(1)
    * @param code
    */
    Airport(string code);

    /**
    * Returns the Airport's code.
    * Time complexity : O(1)
    * @return code
    */
    string getCode() const;

    /**
    * Returns the Airport's name.
    * Time complexity : O(1)
    * @return name
    */
    string getName() const;

    /**
    * Returns the Airport's city.
    * Time complexity : O(1)
    * @return city
    */
    string getCity() const;

    /**
    * Returns the Airport's country.
    * Time complexity : O(1)
    * @return country
    */
    string getCountry() const;

    /**
    * Returns the Airport's latitude.
    * Time complexity : O(1)
    * @return latitude
    */
    double getLatitude() const;

    /**
    * Returns the Airport's longitude.
    * Time complexity : O(1)
    * @return longitude
    */
    double getLongitude() const;

    /**
    * Does not allow duplicates.
    * Time complexity : O(1)
    * @param Airport &other
    */
    bool operator==(const Airport& other) const;

private:
    string code;
    string name;
    string city;
    string country;
    double latitude;
    double longitude;
};

/**
 * This function computes the distance between two locations ( given with coordinates )
 * Time complexity : O(1)
 * @param lat1 latitude of the first location
 * @param lon1 longitude of the first location
 * @param lat2 latitude of the second location
 * @param lon2 longitude of the second location
 * @return the distance between the given coordinates
 */
static double haversine(double lat1, double lon1, double lat2, double lon2) {
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

#endif //PROJECTAED_G24_AIRPORT_H