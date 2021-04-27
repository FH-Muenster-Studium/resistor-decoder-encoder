//
// Created by Fabian Terhorst on 26.04.21.
//

#pragma once

#include <vector>

#include "resistor.h"
#include "color.h"
#include "multiplier_color.h"
#include "tolerance_color.h"
#include "temperature_coefficient_color.h"

class Encoder {

public:
    static MultiplierColor multiplierToColor(float multiplier);

    static ToleranceColor toleranceToColor(float tolerance);

    static TemperatureCoefficientColor temperatureCoefficientToColor(uint8_t temperatureCoefficient);

    static std::vector<Color> encode(const Resistor &resistor);
};
