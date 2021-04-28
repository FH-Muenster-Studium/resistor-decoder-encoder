#pragma once

#include <cstdint>

#include "color.hpp"

enum class OhmColor : uint8_t {
    BLACK = (uint8_t) Color::BLACK,
    BROWN = (uint8_t) Color::BROWN,
    RED = (uint8_t) Color::RED,
    ORANGE = (uint8_t) Color::ORANGE,
    YELLOW = (uint8_t) Color::YELLOW,
    GREEN = (uint8_t) Color::GREEN,
    BLUE = (uint8_t) Color::BLUE,
    VIOLET = (uint8_t) Color::VIOLET,
    GREY = (uint8_t) Color::GREY,
    WHITE = (uint8_t) Color::WHITE,
};
