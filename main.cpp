/**
 * @file main.cpp
 * @author Luis Zambrano Gahon
 * @brief Main entry point for the Testing project.
 * @details Orchestrates different tests through an interactive menu.
 * @version 1.0.0
 * @date 2026-05-14
 */

#include "include/Entity.h"
#include "include/Utils.h"
#include <iostream>

void displayMenu() {
    std::cout << COLOR_BOLD << COLOR_CYAN << "\n===================================" << COLOR_RESET << "\n";
    std::cout << COLOR_BOLD << "      C++ EXCELLENCE LAB MENU" << COLOR_RESET << "\n";
    std::cout << COLOR_BOLD << COLOR_CYAN << "===================================" << COLOR_RESET << "\n";
    std::cout << "1. Run Memory Leak Test\n";
    std::cout << "0. Exit\n";
    std::cout << "Select option: ";
}

int main() {
    int choice = -1;

    while (choice != 0) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            runMemoryLeakTest();
            break;
        case 0:
            std::cout << COLOR_GREEN << "Closing Lab... Happy coding!" << COLOR_RESET << std::endl;
            break;
        default:
            std::cout << COLOR_RED << "Invalid option. Try again." << COLOR_RESET << std::endl;
            break;
        }
    }

    return 0;
}