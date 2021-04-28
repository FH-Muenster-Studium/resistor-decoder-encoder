//
// Created by Fabian Terhorst on 26.04.21.
//

#pragma once

#include <vector>

#include "resistor.hpp"
#include "color.hpp"
#include "multiplier_color.hpp"
#include "tolerance_color.hpp"
#include "temperature_coefficient_color.hpp"

class Encoder {

public:
    static MultiplierColor multiplierToColor(float multiplier);

    static ToleranceColor toleranceToColor(float tolerance);

    static TemperatureCoefficientColor temperatureCoefficientToColor(uint8_t temperatureCoefficient);

    static std::vector<Color> encode(const Resistor &resistor);
};
