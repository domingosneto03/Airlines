#ifndef PROJECTAED_G24_MENU_H
#define PROJECTAED_G24_MENU_H

class Menu {
public:
    Menu();

    /**
    * @brief Displays the main menu and handles user input.
    * @details The main menu consists of a list of options the user can choose from. The function prompts the user to
    * enter their choice as an integer between 1 and 6. If the user enters an invalid option, the function will continue
    * to prompt the user until a valid option is entered. Once a valid option is chosen, the function will execute the
    * corresponding action using a switch statement. The function is set up to run in a loop, so once the chosen action
    * has been executed, the function will display the main menu again and prompt the user for another choice.
    */
    void mainMenu();

    /**
    * @brief Displays the shortest path menu and prompts the user to choose an option.
    *
    * Options include: enter an airport code, enter a city, enter coordinates or return to the main menu when option 4.
    * Then a function is called according to the chosen option and the menu is displayed again after the function call.
    */
    void ShortPathMenu();
    /**
    * @brief Requests the user to enter the departure and arrival airport codes and calls the shortest path function.
    */
    static void AirportCodePathMenu();

    /**
    * @brief Requests the user to enter the cities of the departure and arrival airports and calls the shortest path function.
    */
    static void AirportCityPathMenu();

    /**
    * @brief Requests the user to enter the longitude and latitude of the departure and the max distance in km and arrival airports and calls the shortest path function.
    */
    static void AirportKmPathMenu();

    /**
    * @brief Displays the airport information menu and prompts the user to choose an option.
    *
    * Options include: see the number of flights leaving the airport
    * view the number of airlines leaving the airport, view the number of destinations
    * view the number of countries arriving at the airport and return to the main menu, with option 5.
    * The chosen option is read from the standard input (stdin) and checked to make sure it is valid (1-5).
    * Then a function is called up according to the chosen option.
    * The menu is displayed again after the function call.
    */
    void airportMenu();

    /**
    * @brief Asks the user if he wants to see more information, and if so, calls the corresponding function.
    *
    * Displays "Do you want to see any more? (y/n)" message
    * Reads the user's answer from the standard input (stdin). If the answer is "n" or "N", returns to the previous menu.
    * If the answer is "Y" or "y", calls the corresponding function according to the value of `i`.
    * If the answer is not valid, the function is called again.
    *
    * @param i Integer value that determines which function should be called.
    */
    void repeat(int i);

    /**
    * @brief Requests the user to enter an airport code and displays the number of flights leaving from the airport.
    *
    * Prompts the user to enter an airport code
    * Then calls the App class function numberFlights passing the code as an argument.
    * If it returns -1, the option is not valid and the function is called again.
    * If the answer is valid, then calls the repeat function passing 1 as argument.
    */
    void numberFlightsMenu();

    /**
    * @brief Requests the user to enter an airport code and displays the number of airlines leaving from the airport.
    *
    * Prompts the user to enter an airport code
    * Then calls the function numberAirlines from the App class passing the code as argument.
    * If the return is -1, the option is not valid and the function is called again.
    * If the answer is valid, then calls the repeat function, passing 2 as argument.
    */
    void numberAirlinesMenu();

    /**
    * @brief Requests the user to enter an airport code and displays the number of destinations leaving from the airport.
    *
    * Prompts the user to enter an airport code
    * Then calls the function numberDest from the App class passing the code as argument.
    * If it returns -1, the option is not valid and the function is called again.
    * If the answer is valid, tt then calls the repeat function, passing 3 as an argument.
    */
    void numberDestMenu();

    /**
    * @brief Requests the user to enter an airport code and displays the number of countries the airport flies to.
    *
    * Prompts the user to enter an airport code
    * Then calls the function numberCountries from the App class passing the code as argument.
    * If the return is -1,the option is not valid and the function is called again.
    * If the answer is valid, then calls the repeat function, passing 4 as argument.
    */
    void numberCountriesMenu();

    /**
    * @brief Displays a menu with options to search for airports, countries and cities reachable within a maximum number of flights.
    *
    * Displays a menu of "Airports", "Countries", "Cities" and "Back to main menu".
    * Asks the user to choose an option.
    * If the chosen option is valid, it calls the corresponding function: reachableFlightsMenu, reachableCountriesMenu, or reachableCitiesMenu.
    * If the chosen option is "Back to main menu", it returns to the main menu.
    */
    void reachableFlightsMenu();

    /**
    * @brief Requests the user to enter an airport code and a maximum number of flights, and displays the number of airports reachable from the chosen airport at a maximum number of flights equal to the number chosen by the user.
    *
    * Asks the user to enter an airport code and a maximum number of flights
    * Then calls the function airportsReachable from the App class passing the maximum number of flights and the code as arguments.
    * If it returns -1, the option is not valid and the function is called again.
    * If the answer is valid, then calls the repeat function passing 5 as argument.
    */
    void ReachableMenu();

    /**
    * @brief Prompts the user to enter an airport code and a maximum number of flights, and displays the number of countries reachable from the chosen airport in a maximum number of flights equal to the number chosen by the user.
    *
    * Prompts the user to enter an airport code and a maximum number of flights.
    * Then, it calls the countriesReachable function of the App class, passing the maximum number of flights and the code as arguments.
    * If it returns -1, the option is not valid and the function is called again.
    * If the answer is valid, then it calls the repeat function, passing 6 as an argument.
    */
    void reachableCountriesMenu();

    /**
    * @brief Prompts the user to enter an airport code and a maximum number of flights, and displays the number of cities reachable from the chosen airport in a maximum number of flights equal to the number chosen by the user.
    *
    * Prompts the user to enter an airport code and a maximum number of flights.
    * Then, it calls the citiesReachable function of the App class, passing the maximum number of flights and the code as arguments.
    * If it returns -1, the option is not valid and the function is called again.
    * If the answer is valid, then it calls the repeat function, passing 7 as an argument.
    */
    void reachableCitiesMenu();

    /**
    * @brief Displays a menu with options for displaying statistics about the entire network or about a specific country, and prompts the user to select an option.
    *
    * Displays a menu with options for displaying statistics about the entire network or about a specific country, and prompts the user to select an option.
    * If the user selects option 1, it prompts the user to enter a value for k and calls the redeStatistics function of the App class, passing k as an argument.
    * If the user selects option 2, it calls the CountryStatisticsMenu function. If the user selects option 3, it returns to the main menu.
    */
    void statisticsMenu();

    /**
    * @brief Prompts the user to enter a country name and a value for k, and calls the countryStatistics function of the App class, passing the entered values as arguments.
    *
    * Prompts the user to enter a country name and a value for k, and calls the countryStatistics function of the App class,
    * passing the entered values as arguments.
    */
    void CountryStatisticsMenu();

    /**
    * @brief Displays a menu that allows the user to find the shortest path between two airports through a specific airline.
    * @details Prompts the user to enter the codes for the departure and arrival airports, as well as the name of the airline.
    * Calls the `shortestAirlinePath` function of the `app` object to find and display the shortest path.
    */
    void AirlinePathMenu();
};

#endif //PROJECTAED_G24_MENU_H