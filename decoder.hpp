#pragma once

#include "resistor.hpp"
#include "color.hpp"
#include "temperature_coefficient_color.hpp"
#include "multiplier_color.hpp"
#include "tolerance_color.hpp"
#include "ohm_color.hpp"
#include <vector>
#include <string>
#include <cmath>

class Decoder {

public:
    static float colorToTolerance(ToleranceColor color);

    static float colorToMultiplier(MultiplierColor color);

    static uint64_t colorToOhm(const std::vector<OhmColor> &colors);

    static uint8_t colorToTemperatureCoefficient(TemperatureCoefficientColor color);

    static std::string color_to_string(Color color);

    static std::string type_to_string(Resistor::Type type);

    static void decode4Band(const std::vector<OhmColor> &colors, MultiplierColor multiplier, ToleranceColor tolerance,
                            Resistor &resistor);

    static void decode5Band(const std::vector<OhmColor> &colors, MultiplierColor multiplier, ToleranceColor tolerance,
                            Resistor &resistor);

    static void decode6Band(const std::vector<OhmColor> &colors, MultiplierColor multiplier, ToleranceColor tolerance,
                            TemperatureCoefficientColor temperatureCoefficient, Resistor &resistor);
};
