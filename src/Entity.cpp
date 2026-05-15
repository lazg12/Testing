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
#include <memory>

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

    std::cout << COLOR_CYAN << "\n--- Starting Stack Test---" << COLOR_RESET << std::endl;
    // Objeto en Stack: Se destruye automáticamente
    Entity stackObj(1, "StackObject");
    stackObj.showInfo();

    std::cout << COLOR_CYAN << "\n--- Starting Heap Test ---" << COLOR_RESET << std::endl;
    // Objeto en Heap: ¡ESTO GENERARÁ UN LEAK si no hacemos delete!
    Entity* heapObj = new Entity(2, "HeapObject (The Leak)");
    heapObj->showInfo();

	// Siempre ejecutar el delete cuando se cree un objeto con new para evitar el memory leak
    delete heapObj; // Libera la memoria de Entity* heapObj = new Entity(2, "HeapObject (The Leak)");

    std::cout << COLOR_CYAN << "\n--- Starting Smart Pointer Test ---" << COLOR_RESET << std::endl;

    // 2. SMART POINTER: Vive en el Stack, apunta al Heap, se borra SOLO
    // Necesitas poner #include <memory> arriba de todo
    std::unique_ptr<Entity> smartObj = std::make_unique<Entity>(3, "SmartPointerObject");

    std::cout << COLOR_CYAN << "--- Test Finished (Check if all objects were destroyed) ---" << COLOR_RESET << std::endl;
}