#include "../config/Config.hpp"

#include <chrono>
#include <random>

#include "_uuid.hpp"
#include "_glm.hpp"

#include "./Utils.hpp"

std::string generate_random_string()
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string result;
    result.reserve(32);

    unsigned seed = (unsigned) std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, sizeof(alphanum) - 2);

    for (int i = 0; i < 32; ++i)
    {
        result += alphanum[distribution(generator)];
    }

    return result;
}

std::string get_uuid()
{
    #if defined(LINUX)
        uuid_t uuid;
        char uuid_str[37];

        uuid_generate_random(uuid);
        uuid_unparse_lower(uuid, uuid_str);

        return std::string(uuid_str);

    #elif defined(WINDOWS)
        std::random_device rd;
        auto seed_data = std::array<int, std::mt19937::state_size> {};
        std::generate(std::begin(seed_data), std::end(seed_data), std::ref(rd));
        std::seed_seq seq(std::begin(seed_data), std::end(seed_data));
        std::mt19937 generator(seq);
        uuids::uuid_random_generator gen{generator};

        uuids::uuid const id = gen();
        return uuids::to_string(id);
    #endif
}

// Generate vertices for a sphere
void generateSphere(float radius, unsigned int rings, unsigned int sectors, std::vector<glm::vec3>& vertices)
{
    float const R = 1.0f / static_cast<float>(rings - 1);
    float const S = 1.0f / static_cast<float>(sectors - 1);

    for (unsigned int r = 0; r < rings; ++r)
    {
        for (unsigned int s = 0; s < sectors; ++s)
        {
            float const y = sin(-glm::pi<float>() / 2.0f + glm::pi<float>() * r * R);
            float const x = cos(2.0f * glm::pi<float>() * s * S) * sin(glm::pi<float>() * r * R);
            float const z = sin(2.0f * glm::pi<float>() * s * S) * sin(glm::pi<float>() * r * R);

            vertices.push_back(glm::vec3(x, y, z) * radius);
        }
    }
}

// Generate vertices for a cube
void generateCube(float size, std::vector<glm::vec3>& vertices)
{
    size /= 2.0f;

    vertices = {
        glm::vec3(-size, -size, -size),
        glm::vec3(-size, -size, size),
        glm::vec3(size, -size, size),
        glm::vec3(size, -size, -size),
        glm::vec3(-size, size, -size),
        glm::vec3(-size, size, size),
        glm::vec3(size, size, size),
        glm::vec3(size, size, -size)
    };
}

// Generate vertices for a cylinder
void generateCylinder(float radius, float height, unsigned int sides, std::vector<glm::vec3>& vertices)
{
    float angle = 2.0f * glm::pi<float>() / static_cast<float>(sides);

    for (unsigned int i = 0; i < sides; ++i)
    {
        float x = radius * cos(angle * i);
        float z = radius * sin(angle * i);

        vertices.push_back(glm::vec3(x, -height / 2.0f, z));
        vertices.push_back(glm::vec3(x, height / 2.0f, z));
    }
}

// Generate vertices for a capsule (combination of sphere and cylinder)
void generateCapsule(float radius, float height, unsigned int rings, unsigned int sectors, unsigned int sides, std::vector<glm::vec3>& vertices)
{
    generateSphere(radius, rings, sectors, vertices);
    generateCylinder(radius, height - (2 * radius), sides, vertices);

    // Translate the cylinder part
    for (unsigned int i = rings * sectors; i < vertices.size(); ++i)
    {
        vertices[i].y += (height - (2 * radius)) / 2.0f;
    }
}

// Generate vertices for a plane
void generatePlane(float size, std::vector<glm::vec3>& vertices)
{
    size /= 2.0f;

    vertices = {
        glm::vec3(-size, 0.0f, -size),
        glm::vec3(-size, 0.0f, size),
        glm::vec3(size, 0.0f, size),
        glm::vec3(size, 0.0f, -size)
    };
}

// Generate vertices for an n-sided pyramid
void generatePyramid(float size, unsigned int sides, float height, std::vector<glm::vec3>& vertices)
{
    float angle = 2.0f * glm::pi<float>() / static_cast<float>(sides);

    for (unsigned int i = 0; i < sides; ++i)
    {
        float x = size * cos(angle * i);
        float z = size * sin(angle * i);

        vertices.push_back(glm::vec3(x, 0.0f, z));
    }

    vertices.push_back(glm::vec3(0.0f, height, 0.0f));
}

// Generate vertices for a cone
void generateCone(float radius, float height, unsigned int sides, std::vector<glm::vec3>& vertices)
{
    generateCylinder(radius, height, sides, vertices);

    // Translate the cone part
    for (size_t i = vertices.size() / 2; i < vertices.size(); ++i)
    {
        vertices[i].y -= height / 2.0f;
    }
}