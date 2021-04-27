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
#include <cmath>

class Decoder {

public:
    static float colorToTolerance(ToleranceColor color);

    static float colorToMultiplier(MultiplierColor color);

    static uint64_t colorToOhm(const std::vector<Color> &colors);

    static uint8_t colorToTemperatureCoefficient(TemperatureCoefficientColor color);

    static std::string color_to_string(Color color);

    static std::string type_to_string(Resistor::Type type);

    static void decode4Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance,
                            Resistor &resistor);

    static void decode5Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance,
                            Resistor &resistor);

    static void decode6Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance,
                            TemperatureCoefficientColor temperatureCoefficient, Resistor &resistor);
};

#endif //PRAKTIKUM_1_DECODER_H
