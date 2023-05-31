#include "./Utils.hpp"

#include <chrono>
#include <random>
#include <uuid/uuid.h>

std::string generate_random_string()
{
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string result;
    result.reserve(32);

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, sizeof(alphanum) - 2);

    for (int i = 0; i < 32; ++i)
    {
        result += alphanum[distribution(generator)];
    }

    return result;
}

std::string uuid()
{
    uuid_t uuid;
    char uuid_str[37];

    uuid_generate_random(uuid);
    uuid_unparse_lower(uuid, uuid_str);

    return std::string(uuid_str);
}