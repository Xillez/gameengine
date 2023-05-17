#pragma once

#include <chrono>
#include <random>
#include <string>

//#include <uuid/uuid.h>

std::string generate_random_string();

/*
I think the problem for why I get unknown in this case is because the type I sent in through template parameters isn't included and known where the name is to be looked up
*/