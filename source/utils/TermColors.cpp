#include <fmt/core.h>

#include "TermColors.hpp"

// Reset
const std::string TermColor::RESET = "\033[0m";

std::string TermColor::color(Color color, Style style) {
    int baseCode = 30; // Default to black

    switch (color) {
        case Color::BLACK: baseCode = 30; break;
        case Color::RED: baseCode = 31; break;
        case Color::GREEN: baseCode = 32; break;
        case Color::YELLOW: baseCode = 33; break;
        case Color::BLUE: baseCode = 34; break;
        case Color::MAGENTA: baseCode = 35; break;
        case Color::CYAN: baseCode = 36; break;
        case Color::WHITE: baseCode = 37; break;
        case Color::GRAY: baseCode = 90; break;
        case Color::LIGHT_GRAY: baseCode = 97; break;
    }

    int styleCode = 0;

    switch (style) {
        case Style::REGULAR: styleCode = 0; break;
        case Style::BOLD: styleCode = 1; break;
        case Style::UNDERLINE: styleCode = 4; break;
        case Style::BACKGROUND: color = static_cast<Color>(baseCode + 10); styleCode = 0; break;
        case Style::HIGH_INTENSITY: color = static_cast<Color>(baseCode + 60); styleCode = 0; break;
        case Style::BOLD_HIGH_INTENSITY: color = static_cast<Color>(baseCode + 60); styleCode = 1; break;
        case Style::BACKGROUND_HIGH_INTENSITY: color = static_cast<Color>(baseCode + 70); styleCode = 0; break;
    }

    return fmt::format("\033[{};{}m", styleCode, baseCode);
}
