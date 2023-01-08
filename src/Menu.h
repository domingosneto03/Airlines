#ifndef PROJECTAED_G24_MENU_H
#define PROJECTAED_G24_MENU_H


class Menu {
public:
    Menu();
    void mainMenu();
    void airportMenu();
    void numberFlightsMenu();
    void numberAirlinesMenu();
    void numberDestMenu();
    void numberCountriesMenu();
    void reachableFlightsMenu();
    void ReachableMenu();
    void reachableCountriesMenu();
    void reachableCitiesMenu();
    void repeat(int i);
    void statisticsMenu();

    void CountryStatisticsMenu();
    void testMenu();

    static void ArticulationPointsAirlinesMenu();
};

#endif //PROJECTAED_G24_MENU_H