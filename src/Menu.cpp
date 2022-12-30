#include "Menu.h"
#include "Application.h"
#include <iostream>

using namespace std;
Application app;

Menu::Menu() {
    mainMenu();
}

void Menu::mainMenu() {
    app.createGraph();
}
