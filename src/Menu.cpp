#include "Menu.h"
#include "Application.h"
#include <iostream>

using namespace std;
Application app;

Menu::Menu() {
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
            AirportMenu();
            break;
        case 2:
            app.createGraph();
            break;
        case 3:
            exit(-1);
    }
}

void Menu::AirportMenu() {
    int option;
    cout << "=============AIRPORT MENU=============" << endl;
    cout << "1 - Number of flights" << endl;
    cout << "2 - Number of airlines " << endl;
    cout << "3 - Number of destinations" << endl;
    cout << "4 - Number of countries" << endl;
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
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            mainMenu();
            break;
    }
}