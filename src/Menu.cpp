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
    cout << "1 - Airport information" << endl;
    cout << "2 - Airports reachable on a maximum of Y flights" << endl;
    cout << "3 - Exit" << endl;
    cout << "=======================================" << endl;
    cout << "Option:";
    cin >> option;

    while (option < 1 || option > 3) {
        cout << "This option is not valid, try again!" << endl;
        cout << "Option:";
        cin >> option;
    }

    switch (option) {
        case 1:
            airportMenu();
            break;
        case 2:
            ReachableMenu();
            break;
        case 3:
            exit(-1);
    }
}

void Menu::airportMenu() {
    int option;
    cout << "=============AIRPORT MENU=============" << endl;
    cout << "1 - Number of flights departing from this airport" << endl;
    cout << "2 - Number of airlines departing from this airport" << endl;
    cout << "3 - Number of destinations" << endl;
    cout << "4 - Number of countries arriving at this airport" << endl;
    cout << "5 - Back to the main menu" << endl;
    cout << "======================================" << endl;
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
    }
}

void Menu::repetir(int i) {
    int a=i;
    string conti;
    cout << "Do you want to see any more? (y/n)" <<
         endl;
    cin >>
        conti;
    if (conti == "n" || conti == "N") {
        airportMenu();
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
        }
    } else {
        cout << "This option is not valid, Please enter it again." << endl;
        repetir(a);
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
    repetir(1);
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
    repetir(2);
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
    repetir(3);
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
    repetir(4);
}

void Menu::ReachableMenu() {
    int option;
    cout << "=============Reachable MENU=============" << endl;
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
}

void Menu::reachableCountriesMenu() {
    string code;
    cout << "Introduce the airport's code:";
    cin >> code;

    int max;
    cout << "Maximum number of flights:";
    cin >> max;

    int number = app.countriesReachabe(max, code).size();

    if(number==-1) {
        cout << "This option is not valid, Please enter it again." << endl;
        reachableFlightsMenu();
    }
    if(max==1) cout << "This airport flies to " << number << " different countries, with a maximum of " << max << " flight." << endl;
    else cout << "This airport flies to " << number << " different countries, with a maximum of " << max << " flights." << endl;
}

void Menu::reachableCitiesMenu() {
    string code;
    cout << "Introduce the airport's code:";
    cin >> code;

    int max;
    cout << "Maximum number of flights:";
    cin >> max;

    int number = app.citiesReachabe(max, code).size();

    if(number==-1) {
        cout << "This option is not valid, Please enter it again." << endl;
        reachableFlightsMenu();
    }
    if(max==1) cout << "This airport flies to " << number << " different countries, with a maximum of " << max << " flight." << endl;
    else cout << "This airport flies to " << number << " different countries, with a maximum of " << max << " flights." << endl;
}