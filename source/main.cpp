#include "Application.hpp"

int main(int argc, char const *argv[])
{
    Application app;
    int status = app.init();

    if (status != 0)
        return status;

    return app.run();
}