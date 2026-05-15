/**
 * @file Menu.cpp
 * @author Luis Zambrano Gahón
 * @brief Implementation of the professional menu system.
 * @details Handles input stream cleaning and validation to prevent infinite loops on character insertion.
 * @version 1.0.0
 * @date 2026-05-14
 */
#include "../include/Entity.h"
#include "../include/Menu.h"
#include "../include/Utils.h"
#include <iostream>
#include <limits>

void Menu::display() {
    std::cout << COLOR_BOLD << COLOR_CYAN << "\n===================================" << COLOR_RESET << "\n";
    std::cout << COLOR_BOLD << "      C++ EXCELLENCE LAB MENU" << COLOR_RESET << "\n";
    std::cout << COLOR_BOLD << COLOR_CYAN << "===================================" << COLOR_RESET << "\n";
    std::cout << "1. Run Memory Leak Test\n";
    std::cout << "0. Exit\n";
    std::cout << COLOR_BOLD << "Select option: " << COLOR_RESET;
}

int Menu::getValidatedInput() {
    int input;
    while (true) {
        if (std::cin >> input) {
            return input;
        }
        else {
            std::cout << COLOR_RED << "Error: Please enter a valid number: " << COLOR_RESET;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void Menu::run() {
    int choice = -1;
    while (choice != 0) {
        display();
        choice = getValidatedInput();

        switch (choice) {
        case 1:
            runMemoryLeakTest();
            break;
        case 0:
            std::cout << COLOR_GREEN << "Closing Lab... Happy coding!" << COLOR_RESET << std::endl;
            break;
        default:
            std::cout << COLOR_RED << "Invalid option [0-1]. Try again." << COLOR_RESET << std::endl;
            break;
        }
    }
}