#pragma once

#include <cstring>
#include <cxxabi.h>
#include <string>
#include <typeinfo>

#include "Logging.hpp"

#include "Utils.hpp"

class Reflection
{
    public:
    template<typename T>
    static std::string GetTypeName(const T& obj)
    {
        int status;
        char* demangled_name = abi::__cxa_demangle(typeid(obj).name(), nullptr, nullptr, &status);
        std::string type_name(demangled_name);
        std::free(demangled_name);
        return type_name;
    }

    template<typename T>
    static std::string GetTypeName()
    {
        int status;
        char* demangled_name = abi::__cxa_demangle(typeid(T).name(), nullptr, nullptr, &status);
        std::string type_name(demangled_name);
        std::free(demangled_name);
        return type_name;
    }

    template<typename Tclass, typename Tbase>
    static bool IsExtending()
    {
        bool valid = std::is_base_of<Tbase, Tclass>::value;

        if (!valid) // Class does NOT extend Component
            Log::Error(fmt::format("%s is not a subclass of %s", GetTypeName<Tclass>(), GetTypeName<Tbase>()));

        return valid;
    }
};

#define REFLECT_OBJECT(obj) Reflection::GetTypeName(obj)
#define REFLECT_TYPE(T) Reflection::GetTypeName<T>()
#define REFLECT_IS_EXTENDING(Tclass, Tbase) Reflection::IsExtending<Tclass, Tbase>()