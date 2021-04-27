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

std::string Decoder::result_to_string(Decoder::Result result) {
    switch (result) {
        case OK:
            return "ok";
        case TOLERANCE_DECODE_FAILED:
            return "tolerance decode failed";
        case MULTIPLIER_DECODE_FAILED:
            return "multiplier decode failed";
        case TEMPERATURE_COEFFICIENT_DECODE_FAILED:
            return "temperature coefficient decode failed";
        case OHM_DECODE_FAILED:
            return "ohm decode failed";
        case INVALID_SIZE:
            return "invalid band size";
    }
    return "unknown";
}

std::string Decoder::color_to_string(Color color) {
    switch (color) {
        case BLACK:
            return "Black";
        case BROWN:
            return "Brown";
        case RED:
            return "Red";
        case ORANGE:
            return "Orange";
        case YELLOW:
            return "Yellow";
        case GREEN:
            return "Green";
        case BLUE:
            return "Blue";
        case VIOLET:
            return "Violet";
        case GREY:
            return "Grey";
        case WHITE:
            return "White";
        case GOLD:
            return "Gold";
        case SILVER:
            return "Silver";
        default:
            return "Unknown";
    }
}

std::string Decoder::type_to_string(Resistor::Type type) {
    switch (type) {
        case Resistor::Type::BAND4:
            return "Band-4";
        case Resistor::Type::BAND5:
            return "Band-5";
        case Resistor::Type::BAND6:
            return "Band-6";
        default:
            return "Unknown";
    }
}

Decoder::Result Decoder::decode(const std::vector<Color> &colors, Resistor &resistor) {
    if (colors.size() == 4) {
        return decode4Band(colors[0], colors[1], colors[2], colors[3], resistor);
    }
    if (colors.size() == 5) {
        return decode5Band(colors[0], colors[1], colors[2], colors[3], colors[4], resistor);
    }
    if (colors.size() == 6) {
        return decode6Band(colors[0], colors[1], colors[2], colors[3], colors[4], colors[5], resistor);
    }
    return Decoder::INVALID_SIZE;
}

Decoder::Result
Decoder::decode4Band(Color color1, Color color2, Color multiplier, Color tolerance, Resistor &resistor) {
    float multiplierValue;
    if (!colorToMultiplier(multiplier, multiplierValue)) return MULTIPLIER_DECODE_FAILED;
    uint64_t ohm = colorToOhm({color1, color2}) * multiplierValue;
    float toleranceValue;
    if (!colorToTolerance(tolerance, toleranceValue)) return TOLERANCE_DECODE_FAILED;
    resistor = Resistor(Resistor::BAND4, ohm, toleranceValue, 0);
    return OK;
}

Decoder::Result
Decoder::decode5Band(Color color1, Color color2, Color color3, Color multiplier, Color tolerance, Resistor &resistor) {
    float multiplierValue;
    if (!colorToMultiplier(multiplier, multiplierValue)) return MULTIPLIER_DECODE_FAILED;
    uint64_t ohm = colorToOhm({color1, color2, color3}) * multiplierValue;
    float toleranceValue;
    if (!colorToTolerance(tolerance, toleranceValue)) return TOLERANCE_DECODE_FAILED;
    resistor = Resistor(Resistor::BAND5, ohm, toleranceValue, 0);
    return OK;
}

Decoder::Result
Decoder::decode6Band(Color color1, Color color2, Color color3, Color multiplier, Color tolerance,
                     Color temperatureCoefficient, Resistor &resistor) {
    float multiplierValue;
    if (!colorToMultiplier(multiplier, multiplierValue)) return MULTIPLIER_DECODE_FAILED;
    uint64_t ohm = colorToOhm({color1, color2, color3}) * multiplierValue;
    float toleranceValue;
    if (!colorToTolerance(tolerance, toleranceValue)) return TOLERANCE_DECODE_FAILED;
    uint8_t temperatureCoefficientValue;
    if (!colorToTemperatureCoefficient(temperatureCoefficient, temperatureCoefficientValue))
        return TEMPERATURE_COEFFICIENT_DECODE_FAILED;
    resistor = Resistor(Resistor::BAND6, ohm, toleranceValue, temperatureCoefficientValue);
    return OK;
}