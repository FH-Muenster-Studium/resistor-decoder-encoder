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
    enum Result {
        OK,
        TOLERANCE_DECODE_FAILED,
        MULTIPLIER_DECODE_FAILED,
        TEMPERATURE_COEFFICIENT_DECODE_FAILED,
        OHM_DECODE_FAILED
    };

    static bool colorToTolerance(Color color, float& tolerance);
    static bool colorToMultiplier(Color color, float& multiplier);
    static uint64_t colorToOhm(const std::vector<Color>& colors);
    static bool colorToTemperatureCoefficient(Color color, uint8_t &temperatureCoefficient);
    static Result decode4Band(Color color1, Color color2, Color multiplier, Color tolerance, Resistor &resistor);
    static Result decode5Band(Color color1, Color color2, Color color3, Color multiplier, Color tolerance, Resistor &resistor);
    static Result decode6Band(Color color1, Color color2, Color color3, Color multiplier, Color tolerance, Color temperatureCoefficient, Resistor &resistor);
};

#endif //PRAKTIKUM_1_DECODER_H
