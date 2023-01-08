#include "Menu.h"
#include "Application.h"
#include <iostream>

using namespace std;
Application app;

Menu::Menu() {
    app.createGraph();
    mainMenu();
}

void Menu::mainMenu() {
    int option;
    cout << "===============MAIN MENU===============" << endl;
    cout << "1 - Best route" << endl;
    cout << "2 - Airport information" << endl;
    cout << "3 - Airports/Countries/Cities reachable on a maximum of Y flights" << endl;
    cout << "4 - Statistics" << endl;
    cout << "5 - Articulation points" << endl;
    cout << "6 - Exit" << endl;
    cout << "=======================================" << endl;
    cout << "Option:";
    cin >> option;

    while (option < 1 || option > 6) {
        cout << "This option is not valid, try again!" << endl;
        cout << "Option:";
        cin >> option;
    }

    switch (option) {
        case 1:
            ShortPathMenu();
            break;
        case 2:
            airportMenu();
            break;
        case 3:
            ReachableMenu();
            break;
        case 4:
            statisticsMenu();
            break;
        case 5:
            app.ArticulationPointsRede();
            mainMenu();
            break;
        case 6:
            exit(-1);
        default:
            mainMenu();
    }
}


void Menu::ShortPathMenu() {
    int option;
    cout << "=============SHORTEST PATH MENU=============" << endl;
    cout << "1 - Enter an airport code" << endl;
    cout << "2 - Enter a city" << endl;
    cout << "3 - Enter coordinates" << endl;
    cout << "4 - Back to the main menu" << endl;
    cout << "===========================================" << endl;
    cout << "Option:";
    cin >> option;

    while (option < 1 || option > 4) {
        cout << "This option is not valid, try again!" << endl;
        cout << "Option:";
        cin >> option;
    }

    switch (option) {
        case 1:
            AirportCodePathMenu();
            ShortPathMenu();
            break;
        case 2:
            AirportCityPathMenu();
            ShortPathMenu();
            break;
        case 3:
            AirportKmPathMenu();
            ShortPathMenu();
        case 4:
            exit(-1);
        default:
            mainMenu();
    }
}

void Menu::AirportCodePathMenu() {
    string code1;
    string code2;
    cout << "Introduce the departure airport's code:" ;
    cin >> code1;
    cout << "Introduce the arrival airport's code:" ;
    cin >> code2;
    app.shortestPath(code1, code2);
}

void Menu::AirportCityPathMenu() {
    string code1;
    string code2;
    cout << "Introduce the departure airport's city:" ;
    getline(cin >> ws,code1);
    cout << "Introduce the arrival airport's code:" ;
    cin >> code2;
    app.shortestCityPath(code1, code2);
}


void Menu::AirportKmPathMenu() {
    double longitude;
    double latitude;
    string code2;
    double distance;

    cout << "Introduce the longitude:" ;
    cin >> longitude;
    cout << "Introduce the latitude:" ;
    cin >> latitude;
    cout << "Introduce the arrival airport's code:" ;
    cin >> code2;
    cout << "Enter the maximum distance, in km, you wish to travel to an airport:" ;
    cin >> distance;
    app.shortestKmPath(longitude, latitude, code2, distance);
}


void Menu::airportMenu() {
    int option;
    cout << "=============AIRPORT MENU=============" << endl;
    cout << "1 - Number of flights departing from this airport" << endl;
    cout << "2 - Number of airlines departing from this airport" << endl;
    cout << "3 - Number of destinations" << endl;
    cout << "4 - Number of countries arriving at this airport" << endl;
    cout << "5 - Back to the main menu" << endl;
    cout << "=======================================" << endl;
    cout << "Option:";
    cin >> option;

    while (option < 1 || option > 5) {
        cout << "This option is not valid, try again!" << endl;
        cout << "Option:";
        cin >> option;
    }

    switch (option) {
        case 1:
            numberFlightsMenu();
            break;
        case 2:
            numberAirlinesMenu();
            break;
        case 3:
            numberDestMenu();
            break;
        case 4:
            numberCountriesMenu();
            break;
        case 5:
            mainMenu();
            break;
        default:
            mainMenu();
    }
}

void Menu::repeat(int i) {
    int a=i;
    string conti;
    cout << "Do you want to see any more? (y/n)" << endl;
    cin >>
        conti;
    if (conti == "n" || conti == "N") {
        switch (i) {
            case 1 : case 2: case 3: case 4:
                airportMenu();
                break;
            case 5: case 6: case 7:
                ReachableMenu();
                break;
            default:
                mainMenu();
        }

    } else if (conti == "Y" || conti == "y") {
        switch (i) {
            case 1:
                numberFlightsMenu();
                break;
            case 2:
                numberAirlinesMenu();
                break;
            case 3:
                numberDestMenu();
                break;
            case 4:
                numberCountriesMenu();
                break;
            case 5:
                reachableFlightsMenu();
                break;
            case 6:
                reachableCountriesMenu();
                break;
            case 7:
                reachableCitiesMenu();
                break;
            default:
                mainMenu();
        }
    } else {
        cout << "This option is not valid, Please enter it again." << endl;
        repeat(a);
    }
}

void Menu::numberFlightsMenu() {
    string code;
    cout << "Introduce the airport's code:" ;
    cin >> code;
    int number = app.numberFlights(code);
    if(number==-1) {
        cout << "This option is not valid, Please enter it again." << endl;
        numberFlightsMenu();
    }
    cout << "There are " << number << " flights." << endl;
    repeat(1);
}

void Menu::numberAirlinesMenu() {
    string code;
    cout << "Introduce the airport's code:" ;
    cin >> code;
    int number = app.numberAirlines(code);
    if(number==-1) {
        cout << "This option is not valid, Please enter it again." << endl;
        numberAirlinesMenu();
    }
    cout << "There are " << number << " airlines from this airport." << endl;
    repeat(2);
}

void Menu::numberDestMenu() {
    string code;
    cout << "Introduce the airport's code:" ;
    cin >> code;
    int number = app.numberDest(code);
    if(number==-1) {
        cout << "This option is not valid, Please enter it again." << endl;
        numberDestMenu();
    }
    cout << "There are " << number << " destinations from this airport." << endl;
    repeat(3);
}

void Menu::numberCountriesMenu() {
    string code;
    cout << "Introduce the airport's code:" ;
    cin >> code;
    int number = app.numberCountries(code);
    if(number==-1) {
        cout << "This option is not valid, Please enter it again." << endl;
        numberCountriesMenu();
    }
    cout << "This airport flies to " << number << " different countries." << endl;
    repeat(4);
}

void Menu::ReachableMenu() {
    int option;
    cout << "=============REACHABLE MENU=============" << endl;
    cout << "1 - Airports" << endl;
    cout << "2 - Countries" << endl;
    cout << "3 - Cities" << endl;
    cout << "4 - Back to the main menu" << endl;
    cout << "======================================" << endl;
    cout << "Option:";
    cin >> option;

    while (option < 1 || option > 4) {
        cout << "This option is not valid, try again!" << endl;
        cout << "Option:";
        cin >> option;
    }

    switch (option) {
        case 1:
            reachableFlightsMenu();
            break;
        case 2:
            reachableCountriesMenu();
            break;
        case 3:
            reachableCitiesMenu();
            break;
        case 4:
            mainMenu();
            break;
        default:
            mainMenu();
    }
}

void Menu::reachableFlightsMenu() {
    string code;
    cout << "Introduce the airport's code:" ;
    cin >> code;

    int max;
    cout << "Maximum number of flights:" ;
    cin >> max;

    int number = app.airportsReachable(max, code).size();
    if(number==-1) {
        cout << "This option is not valid, Please enter it again." << endl;
        reachableFlightsMenu();
    }
    if(max==1) cout << "This airport flies to " << number << " different airports, with a maximum of " << max << " flight." << endl;
    else cout << "This airport flies to " << number << " different countries, with a maximum of " << max << " flights." << endl;

    repeat(5);
}

void Menu::reachableCountriesMenu() {
    string code;
    cout << "Introduce the airport's code:";
    cin >> code;

    int max;
    cout << "Maximum number of flights:";
    cin >> max;

    int number = app.countriesReachable(max, code).size();

    if(number==-1) {
        cout << "This option is not valid, Please enter it again." << endl;
        reachableFlightsMenu();
    }
    if(max==1) cout << "This airport flies to " << number << " different countries, with a maximum of " << max << " flight." << endl;
    else cout << "This airport flies to " << number << " different countries, with a maximum of " << max << " flights." << endl;

    repeat(6);
}

void Menu::reachableCitiesMenu() {
    string code;
    cout << "Introduce the airport's code:";
    cin >> code;

    int max;
    cout << "Maximum number of flights:";
    cin >> max;

    int number = app.citiesReachable(max, code).size();

    if(number==-1) {
        cout << "This option is not valid, Please enter it again." << endl;
        reachableFlightsMenu();
    }
    if(max==1) cout << "This airport flies to " << number << " different countries, with a maximum of " << max << " flight." << endl;
    else cout << "This airport flies to " << number << " different countries, with a maximum of " << max << " flights." << endl;

    repeat(7);
}

void Menu::statisticsMenu() {
    int option;
    cout << "=============STATISTICS MENU=============" << endl;
    cout << "1 - Rede" << endl;
    cout << "2 - Country" << endl;
    cout << "3 - Back to the main menu" << endl;
    cout << "======================================" << endl;
    cout << "Option:";
    cin >> option;

    while (option < 1 || option > 4) {
        cout << "This option is not valid, try again!" << endl;
        cout << "Option:";
        cin >> option;
    }

    switch (option) {
        case 1:
            int k;
            cout << "Enter the k for the top-k:" ;
            cin >> k;
            app.redeStatistics(k);
            mainMenu();
            break;
        case 2:
            CountryStatisticsMenu();
            mainMenu();
            break;
        case 3:
            mainMenu();
            break;
        default:
            mainMenu();
    }
}

void Menu::CountryStatisticsMenu() {
    string code;
    cout << "Introduce the country's name:";
    cin >> code;

    int k;
    cout << "Enter the k for the top-k:" ;
    cin >> k;

    app.countryStatistics(k,code);
}