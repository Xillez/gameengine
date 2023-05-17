#include "./Enable.hpp"

bool Enable::isEnabled()
{
    return this->enabled;
}

void Enable::setEnabled(bool state)
{
    this->enabled = state;
}