#include "./Utils.hpp"

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