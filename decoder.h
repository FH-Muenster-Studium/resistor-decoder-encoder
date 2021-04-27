//
// Created by Fabian Terhorst on 26.04.21.
//

#ifndef PRAKTIKUM_1_DECODER_H
#define PRAKTIKUM_1_DECODER_H

#include "resistor.h"
#include "color.h"
#include <vector>
#include <string>

class Decoder {

public:
    enum Result {
        OK,
        TOLERANCE_DECODE_FAILED,
        MULTIPLIER_DECODE_FAILED,
        TEMPERATURE_COEFFICIENT_DECODE_FAILED,
        OHM_DECODE_FAILED,
        INVALID_SIZE
    };

    static bool colorToTolerance(Color color, float& tolerance);
    static bool colorToMultiplier(Color color, float& multiplier);
    static uint64_t colorToOhm(const std::vector<Color>& colors);
    static bool colorToTemperatureCoefficient(Color color, uint8_t &temperatureCoefficient);
    static std::string result_to_string(Decoder::Result result);
    static std::string color_to_string(Color color);
    static std::string type_to_string(Resistor::Type type);
    static Result decode(const std::vector<Color>& colors, Resistor &resistor);
    static Result decode4Band(Color color1, Color color2, Color multiplier, Color tolerance, Resistor &resistor);
    static Result decode5Band(Color color1, Color color2, Color color3, Color multiplier, Color tolerance, Resistor &resistor);
    static Result decode6Band(Color color1, Color color2, Color color3, Color multiplier, Color tolerance, Color temperatureCoefficient, Resistor &resistor);
};

#endif //PRAKTIKUM_1_DECODER_H
