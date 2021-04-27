//
// Created by Fabian Terhorst on 26.04.21.
//

#ifndef PRAKTIKUM_1_DECODER_H
#define PRAKTIKUM_1_DECODER_H

#include "resistor.h"
#include "color.h"
#include "temperature_coefficient_color.h"
#include "multiplier_color.h"
#include "tolerance_color.h"
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

    static bool colorToTolerance(ToleranceColor color, float& tolerance);
    static bool colorToMultiplier(MultiplierColor color, float& multiplier);
    static uint64_t colorToOhm(const std::vector<Color>& colors);
    static bool colorToTemperatureCoefficient(TemperatureCoefficientColor color, uint8_t &temperatureCoefficient);
    static std::string result_to_string(Decoder::Result result);
    static std::string color_to_string(Color color);
    static std::string type_to_string(Resistor::Type type);
    static Result decode4Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance, Resistor &resistor);
    static Result decode5Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance, Resistor &resistor);
    static Decoder::Result decode6Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance,
                                         TemperatureCoefficientColor temperatureCoefficient, Resistor &resistor);
};

#endif //PRAKTIKUM_1_DECODER_H
