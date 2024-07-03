#pragma once

#include <string>

class TermColor {
public:
    enum class Color {
        BLACK,
        RED,
        GREEN,
        YELLOW,
        BLUE,
        MAGENTA,
        CYAN,
        WHITE,
        GRAY,
        LIGHT_GRAY
    };

    enum class Style {
        REGULAR,
        BOLD,
        UNDERLINE,
        BACKGROUND,
        HIGH_INTENSITY,
        BOLD_HIGH_INTENSITY,
        BACKGROUND_HIGH_INTENSITY
    };

    static std::string color(Color color, Style style = Style::REGULAR);

    static const std::string RESET;
};

/*
NOTE: Disabled. Unsure if this is really wanted yet.

// Reset
#define RESET "\033[0m"

// Regular colors
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Bold colors
#define BOLD_BLACK "\033[1;30m"
#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN "\033[1;36m"
#define BOLD_WHITE "\033[1;37m"

// Underline colors
#define UNDERLINE_BLACK "\033[4;30m"
#define UNDERLINE_RED "\033[4;31m"
#define UNDERLINE_GREEN "\033[4;32m"
#define UNDERLINE_YELLOW "\033[4;33m"
#define UNDERLINE_BLUE "\033[4;34m"
#define UNDERLINE_MAGENTA "\033[4;35m"
#define UNDERLINE_CYAN "\033[4;36m"
#define UNDERLINE_WHITE "\033[4;37m"

// Background colors
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

// High intensity colors
#define LIGHT_BLACK "\033[0;90m"
#define LIGHT_RED "\033[0;91m"
#define LIGHT_GREEN "\033[0;92m"
#define LIGHT_YELLOW "\033[0;93m"
#define LIGHT_BLUE "\033[0;94m"
#define LIGHT_MAGENTA "\033[0;95m"
#define LIGHT_CYAN "\033[0;96m"
#define LIGHT_WHITE "\033[0;97m"

// Bold high intensity colors
#define BOLD_LIGHT_BLACK "\033[1;90m"
#define BOLD_LIGHT_RED "\033[1;91m"
#define BOLD_LIGHT_GREEN "\033[1;92m"
#define BOLD_LIGHT_YELLOW "\033[1;93m"
#define BOLD_LIGHT_BLUE "\033[1;94m"
#define BOLD_LIGHT_MAGENTA "\033[1;95m"
#define BOLD_LIGHT_CYAN "\033[1;96m"
#define BOLD_LIGHT_WHITE "\033[1;97m"

// High intensity background colors
#define BG_LIGHT_BLACK "\033[0;100m"
#define BG_LIGHT_RED "\033[0;101m"
#define BG_LIGHT_GREEN "\033[0;102m"
#define BG_LIGHT_YELLOW "\033[0;103m"
#define BG_LIGHT_BLUE "\033[0;104m"
#define BG_LIGHT_MAGENTA "\033[0;105m"
#define BG_LIGHT_CYAN "\033[0;106m"
#define BG_LIGHT_WHITE "\033[0;107m"
*/