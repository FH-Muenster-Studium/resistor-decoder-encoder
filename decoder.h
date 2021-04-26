//
// Created by Fabian Terhorst on 26.04.21.
//

#ifndef PRAKTIKUM_1_DECODER_H
#define PRAKTIKUM_1_DECODER_H

#include "resistor.h"
#include "color.h"
#include <vector>

class Decoder {

public:
    static bool colorToTolerance(Color color, float& tolerance);
    static bool colorToMultiplier(Color color, float& multiplier);
    static uint64_t colorToOhm(const std::vector<Color>& colors);
    static bool decode4Band(Color color1, Color color2, Color multiplier, Color tolerance, Resistor &resistor);
    static bool decode5Band(Color color1, Color color2, Color color3, Color multiplier, Color tolerance, Resistor &resistor);
};

#endif //PRAKTIKUM_1_DECODER_H
