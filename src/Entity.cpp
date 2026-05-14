/**
 * @file Entity.cpp
 * @author Luis Zambrano Gahon
 * @brief Implementation of the Entity class.
 * @version 1.0.0
 * @date 2026-05-14
 */

#include "Entity.h"
#include "Utils.h"
#include <iostream>

 // Implementación del constructor
Entity::Entity(int id, std::string name) : id(id), name(name) {
    std::cout << COLOR_YELLOW << "[CONSTRUCTOR] " << COLOR_RESET
        << "Entity " << id << " (" << name << ") allocated." << std::endl;
}

// Implementación del destructor
Entity::~Entity() {
    std::cout << COLOR_RED << "[DESTRUCTOR] " << COLOR_RESET
        << "Entity " << id << " destroyed. Memory released." << std::endl;
}

void Entity::showInfo() const {
    std::cout << COLOR_BOLD << "Entity ID: " << id << " | Name: " << name << COLOR_RESET << std::endl;
}

void runMemoryLeakTest() {
    std::cout << COLOR_CYAN << "\n--- Starting Memory Leak Test ---" << COLOR_RESET << std::endl;

    // Objeto en Stack: Se destruye automáticamente
    Entity stackObj(1, "StackObject");
    stackObj.showInfo();

    // Objeto en Heap: ¡ESTO GENERARÁ UN LEAK si no hacemos delete!
    Entity* heapObj = new Entity(2, "HeapObject (The Leak)");
    heapObj->showInfo();

    std::cout << COLOR_CYAN << "--- Test Finished (Check if all objects were destroyed) ---" << COLOR_RESET << std::endl;

    // Para arreglarlo, deberías poner: delete heapObj;
}