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