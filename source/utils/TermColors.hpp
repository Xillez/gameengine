#pragma once

class TermColor {
public:
    // Reset
    static const std::string RESET;

    // Regular colors
    static const std::string BLACK;
    static const std::string RED;
    static const std::string GREEN;
    static const std::string YELLOW;
    static const std::string BLUE;
    static const std::string MAGENTA;
    static const std::string CYAN;
    static const std::string WHITE;

    // Bold colors
    static const std::string BOLD_BLACK;
    static const std::string BOLD_RED;
    static const std::string BOLD_GREEN;
    static const std::string BOLD_YELLOW;
    static const std::string BOLD_BLUE;
    static const std::string BOLD_MAGENTA;
    static const std::string BOLD_CYAN;
    static const std::string BOLD_WHITE;

    // Underline colors
    static const std::string UNDERLINE_BLACK;
    static const std::string UNDERLINE_RED;
    static const std::string UNDERLINE_GREEN;
    static const std::string UNDERLINE_YELLOW;
    static const std::string UNDERLINE_BLUE;
    static const std::string UNDERLINE_MAGENTA;
    static const std::string UNDERLINE_CYAN;
    static const std::string UNDERLINE_WHITE;

    // Background colors
    static const std::string BG_BLACK;
    static const std::string BG_RED;
    static const std::string BG_GREEN;
    static const std::string BG_YELLOW;
    static const std::string BG_BLUE;
    static const std::string BG_MAGENTA;
    static const std::string BG_CYAN;
    static const std::string BG_WHITE;

    // High intensity colors
    static const std::string LIGHT_BLACK;
    static const std::string LIGHT_RED;
    static const std::string LIGHT_GREEN;
    static const std::string LIGHT_YELLOW;
    static const std::string LIGHT_BLUE;
    static const std::string LIGHT_MAGENTA;
    static const std::string LIGHT_CYAN;
    static const std::string LIGHT_WHITE;

    // Bold high intensity colors
    static const std::string BOLD_LIGHT_BLACK;
    static const std::string BOLD_LIGHT_RED;
    static const std::string BOLD_LIGHT_GREEN;
    static const std::string BOLD_LIGHT_YELLOW;
    static const std::string BOLD_LIGHT_BLUE;
    static const std::string BOLD_LIGHT_MAGENTA;
    static const std::string BOLD_LIGHT_CYAN;
    static const std::string BOLD_LIGHT_WHITE;

    // High intensity background colors
    static const std::string BG_LIGHT_BLACK;
    static const std::string BG_LIGHT_RED;
    static const std::string BG_LIGHT_GREEN;
    static const std::string BG_LIGHT_YELLOW;
    static const std::string BG_LIGHT_BLUE;
    static const std::string BG_LIGHT_MAGENTA;
    static const std::string BG_LIGHT_CYAN;
    static const std::string BG_LIGHT_WHITE;
};

const std::string TermColor::RESET = "\033[0m";

// Regular colors
const std::string TermColor::BLACK = "\033[0;30m";
const std::string TermColor::RED = "\033[0;31m";
const std::string TermColor::GREEN = "\033[0;32m";
const std::string TermColor::YELLOW = "\033[0;33m";
const std::string TermColor::BLUE = "\033[0;34m";
const std::string TermColor::MAGENTA = "\033[0;35m";
const std::string TermColor::CYAN = "\033[0;36m";
const std::string TermColor::WHITE = "\033[0;37m";

// Bold colors
const std::string TermColor::BOLD_BLACK = "\033[1;30m";
const std::string TermColor::BOLD_RED = "\033[1;31m";
const std::string TermColor::BOLD_GREEN = "\033[1;32m";
const std::string TermColor::BOLD_YELLOW = "\033[1;33m";
const std::string TermColor::BOLD_BLUE = "\033[1;34m";
const std::string TermColor::BOLD_MAGENTA = "\033[1;35m";
const std::string TermColor::BOLD_CYAN = "\033[1;36m";
const std::string TermColor::BOLD_WHITE = "\033[1;37m";

// Underline colors
const std::string TermColor::UNDERLINE_BLACK = "\033[4;30m";
const std::string TermColor::UNDERLINE_RED = "\033[4;31m";
const std::string TermColor::UNDERLINE_GREEN = "\033[4;32m";
const std::string TermColor::UNDERLINE_YELLOW = "\033[4;33m";
const std::string TermColor::UNDERLINE_BLUE = "\033[4;34m";
const std::string TermColor::UNDERLINE_MAGENTA = "\033[4;35m";
const std::string TermColor::UNDERLINE_CYAN = "\033[4;36m";
const std::string TermColor::UNDERLINE_WHITE = "\033[4;37m";

// Background colors
const std::string TermColor::BG_BLACK = "\033[40m";
const std::string TermColor::BG_RED = "\033[41m";
const std::string TermColor::BG_GREEN = "\033[42m";
const std::string TermColor::BG_YELLOW = "\033[43m";
const std::string TermColor::BG_BLUE = "\033[44m";
const std::string TermColor::BG_MAGENTA = "\033[45m";
const std::string TermColor::BG_CYAN = "\033[46m";
const std::string TermColor::BG_WHITE = "\033[47m";

// High intensity colors
const std::string TermColor::LIGHT_BLACK = "\033[0;90m";
const std::string TermColor::LIGHT_RED = "\033[0;91m";
const std::string TermColor::LIGHT_GREEN = "\033[0;92m";
const std::string TermColor::LIGHT_YELLOW = "\033[0;93m";
const std::string TermColor::LIGHT_BLUE = "\033[0;94m";
const std::string TermColor::LIGHT_MAGENTA = "\033[0;95m";
const std::string TermColor::LIGHT_CYAN = "\033[0;96m";
const std::string TermColor::LIGHT_WHITE = "\033[0;97m";

// Bold high intensity colors
const std::string TermColor::BOLD_LIGHT_BLACK = "\033[1;90m";
const std::string TermColor::BOLD_LIGHT_RED = "\033[1;91m";
const std::string TermColor::BOLD_LIGHT_GREEN = "\033[1;92m";
const std::string TermColor::BOLD_LIGHT_YELLOW = "\033[1;93m";
const std::string TermColor::BOLD_LIGHT_BLUE = "\033[1;94m";
const std::string TermColor::BOLD_LIGHT_MAGENTA = "\033[1;95m";
const std::string TermColor::BOLD_LIGHT_CYAN = "\033[1;96m";
const std::string TermColor::BOLD_LIGHT_WHITE = "\033[1;97m";

// High intensity background colors
const std::string TermColor::BG_LIGHT_BLACK = "\033[0;100m";
const std::string TermColor::BG_LIGHT_RED = "\033[0;101m";
const std::string TermColor::BG_LIGHT_GREEN = "\033[0;102m";
const std::string TermColor::BG_LIGHT_YELLOW = "\033[0;103m";
const std::string TermColor::BG_LIGHT_BLUE = "\033[0;104m";
const std::string TermColor::BG_LIGHT_MAGENTA = "\033[0;105m";
const std::string TermColor::BG_LIGHT_CYAN = "\033[0;106m";
const std::string TermColor::BG_LIGHT_WHITE = "\033[0;107m";

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