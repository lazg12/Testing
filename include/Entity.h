/**
 * @file Entity.h
 * @author Luis Zambrano Gahon
 * @brief Entity class for testing purposes.
 * @details Defines an entity to test memory management and lifecycle.
 * @version 1.0.0
 * @date 2026-05-14
 * @copyright Copyright (c) 2026 - Licencia MIT
 */

#ifndef ENTITY_H
#define ENTITY_H

#include <string>

class Entity {
public:
    // Constructor: Inicializa la entidad
    Entity(int id, std::string name);

    // Destructor: Crucial para detectar memory leaks
    ~Entity();

    // Muestra información de la entidad
    void showInfo() const;

private:
    int id;
    std::string name;
};

// Función global para ejecutar la prueba de fuga de memoria
void runMemoryLeakTest();

#endif
