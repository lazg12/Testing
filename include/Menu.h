/**
 * @file Menu.h
 * @author Luis Zambrano Gahón
 * @brief Professional menu handler with input validation.
 * @details Declares functions for displaying the menu, validating user input, and controlling the application loop.
 * @version 1.0.0
 * @date 2026-05-14
 */
#ifndef MENU_H
#define MENU_H

namespace Menu {
    void display();
    int getValidatedInput();
    void run();
}

#endif
