//
// Created by Fabian Terhorst on 26.04.21.
//

#include "decoder.h"

bool Decoder::colorToTolerance(Color color, float &tolerance) {
    switch (color) {
        case BROWN:
            tolerance = 1;
            return true;
        case RED:
            tolerance = 2;
            return true;
        case GREEN:
            tolerance = 0.5;
            return true;
        case BLUE:
            tolerance = 0.25;
            return true;
        case VIOLET:
            tolerance = 0.1;
            return true;
        case GOLD:
            tolerance = 5;
            return true;
        case SILVER:
            tolerance = 10;
            return true;
        default:
            return false;
    }
}

bool Decoder::colorToMultiplier(Color color, float &multiplier) {
    switch (color) {
        case BLACK:
            multiplier = 1;
            return true;
        case BROWN:
            multiplier = 10;
            return true;
        case RED:
            multiplier = 100;
            return true;
        case ORANGE:
            multiplier = 1 * 1000;
            return true;
        case YELLOW:
            multiplier = 10 * 1000;
            return true;
        case GREEN:
            multiplier = 100 * 1000;
            return true;
        case BLUE:
            multiplier = 1 * 1000 * 1000;
            return true;
        case GOLD:
            multiplier = 0.1;
            return true;
        case SILVER:
            multiplier = 0.01;
            return true;
        default:
            return false;
    }
}

uint64_t Decoder::colorToOhm(const std::vector<Color> &colors) {
    uint8_t decimal = 1;
    uint64_t ohm = 0;
    for (Color color : colors) {
        ohm += (uint8_t) color * decimal;
        decimal *= 10;
    }
    return ohm;
}

bool Decoder::colorToTemperatureCoefficient(Color color, uint8_t &temperatureCoefficient) {
    switch (color) {
        case BLACK:
            temperatureCoefficient = 250;
            return true;
        case BROWN:
            temperatureCoefficient = 100;
            return true;
        case RED:
            temperatureCoefficient = 50;
            return true;
        case ORANGE:
            temperatureCoefficient = 15;
            return true;
        case YELLOW:
            temperatureCoefficient = 25;
            return true;
        case GREEN:
            temperatureCoefficient = 20;
            return true;
        case BLUE:
            temperatureCoefficient = 10;
            return true;
        case VIOLET:
            temperatureCoefficient = 5;
            return true;
        case GREY:
            temperatureCoefficient = 1;
            return true;
        default:
            return false;
    }
}

Decoder::Result Decoder::decode4Band(Color color1, Color color2, Color multiplier, Color tolerance, Resistor &resistor) {
    float multiplierValue;
    if (!colorToMultiplier(multiplier, multiplierValue)) return MULTIPLIER_DECODE_FAILED;
    uint64_t ohm = colorToOhm({color1, color2}) * (uint8_t) multiplier;
    float toleranceValue;
    if (!colorToTolerance(tolerance, toleranceValue)) return TOLERANCE_DECODE_FAILED;
    resistor = Resistor(Resistor::BAND4, ohm, toleranceValue, 0);
    return OK;
}

Decoder::Result
Decoder::decode5Band(Color color1, Color color2, Color color3, Color multiplier, Color tolerance, Resistor &resistor) {
    float multiplierValue;
    if (!colorToMultiplier(multiplier, multiplierValue)) return MULTIPLIER_DECODE_FAILED;
    uint64_t ohm = colorToOhm({color1, color2, color3}) * (uint8_t) multiplier;
    float toleranceValue;
    if (!colorToTolerance(tolerance, toleranceValue)) return TOLERANCE_DECODE_FAILED;
    resistor = Resistor(Resistor::BAND5, ohm, toleranceValue, 0);
    return OK;
}

Decoder::Result
Decoder::decode6Band(Color color1, Color color2, Color color3, Color multiplier, Color tolerance, Color temperatureCoefficient, Resistor &resistor) {
    float multiplierValue;
    if (!colorToMultiplier(multiplier, multiplierValue)) return MULTIPLIER_DECODE_FAILED;
    uint64_t ohm = colorToOhm({color1, color2, color3}) * (uint8_t) multiplier;
    float toleranceValue;
    if (!colorToTolerance(tolerance, toleranceValue)) return TOLERANCE_DECODE_FAILED;
    uint8_t temperatureCoefficientValue;
    if(!colorToTemperatureCoefficient(temperatureCoefficient, temperatureCoefficientValue)) return TEMPERATURE_COEFFICIENT_DECODE_FAILED;
    resistor = Resistor(Resistor::BAND5, ohm, toleranceValue, temperatureCoefficientValue);
    return OK;
}
