#pragma once

#include <string>
#include <type_traits>
#include <vector>
#include "_glm.hpp"

std::string generate_random_string();

std::string get_uuid();

// Generate vertices for a sphere
void generateSphere(
    float radius,
    unsigned int rings,
    unsigned int sectors,
    std::vector<glm::vec3>& vertices);

// Generate vertices for a cube
void generateCube(float size, std::vector<glm::vec3>& vertices);

// Generate vertices for a cylinder
void generateCylinder(
    float radius,
    float height,
    unsigned int sides,
    std::vector<glm::vec3>& vertices);

// Generate vertices for a capsule (combination of sphere and cylinder)
void generateCapsule(
    float radius,
    float height,
    unsigned int rings,
    unsigned int sectors,
    unsigned int sides,
    std::vector<glm::vec3>& vertices);

// Generate vertices for a plane
void generatePlane(float size, std::vector<glm::vec3>& vertices);

// Generate vertices for an n-sided pyramid
void generatePyramid(
    float size,
    unsigned int sides,
    float height,
    std::vector<glm::vec3>& vertices);

// Generate vertices for a cone
void generateCone(
    float radius,
    float height,
    unsigned int sides,
    std::vector<glm::vec3>& vertices);