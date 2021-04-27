//
// Created by Fabian Terhorst on 26.04.21.
//

#include "decoder.h"

bool Decoder::colorToTolerance(ToleranceColor color, float &tolerance) {
    switch (color) {
        case ToleranceColor::BROWN:
            tolerance = 1;
            return true;
        case ToleranceColor::RED:
            tolerance = 2;
            return true;
        case ToleranceColor::GREEN:
            tolerance = 0.5;
            return true;
        case ToleranceColor::BLUE:
            tolerance = 0.25;
            return true;
        case ToleranceColor::VIOLET:
            tolerance = 0.1;
            return true;
        case ToleranceColor::GOLD:
            tolerance = 5;
            return true;
        case ToleranceColor::SILVER:
            tolerance = 10;
            return true;
        default:
            return false;
    }
}

bool Decoder::colorToMultiplier(MultiplierColor color, float &multiplier) {
    switch (color) {
        case MultiplierColor::BLACK:
            multiplier = 1;
            return true;
        case MultiplierColor::BROWN:
            multiplier = 10;
            return true;
        case MultiplierColor::RED:
            multiplier = 100;
            return true;
        case MultiplierColor::ORANGE:
            multiplier = 1 * 1000;
            return true;
        case MultiplierColor::YELLOW:
            multiplier = 10 * 1000;
            return true;
        case MultiplierColor::GREEN:
            multiplier = 100 * 1000;
            return true;
        case MultiplierColor::BLUE:
            multiplier = 1 * 1000 * 1000;
            return true;
        case MultiplierColor::GOLD:
            multiplier = 0.1;
            return true;
        case MultiplierColor::SILVER:
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

bool Decoder::colorToTemperatureCoefficient(TemperatureCoefficientColor color, uint8_t &temperatureCoefficient) {
    switch (color) {
        case TemperatureCoefficientColor::BLACK:
            temperatureCoefficient = 250;
            return true;
        case TemperatureCoefficientColor::BROWN:
            temperatureCoefficient = 100;
            return true;
        case TemperatureCoefficientColor::RED:
            temperatureCoefficient = 50;
            return true;
        case TemperatureCoefficientColor::ORANGE:
            temperatureCoefficient = 15;
            return true;
        case TemperatureCoefficientColor::YELLOW:
            temperatureCoefficient = 25;
            return true;
        case TemperatureCoefficientColor::GREEN:
            temperatureCoefficient = 20;
            return true;
        case TemperatureCoefficientColor::BLUE:
            temperatureCoefficient = 10;
            return true;
        case TemperatureCoefficientColor::VIOLET:
            temperatureCoefficient = 5;
            return true;
        case TemperatureCoefficientColor::GREY:
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
        case Color::BLACK:
            return "Black";
        case Color::BROWN:
            return "Brown";
        case Color::RED:
            return "Red";
        case Color::ORANGE:
            return "Orange";
        case Color::YELLOW:
            return "Yellow";
        case Color::GREEN:
            return "Green";
        case Color::BLUE:
            return "Blue";
        case Color::VIOLET:
            return "Violet";
        case Color::GREY:
            return "Grey";
        case Color::WHITE:
            return "White";
        case Color::GOLD:
            return "Gold";
        case Color::SILVER:
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

Decoder::Result
Decoder::decode4Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance, Resistor &resistor) {
    float multiplierValue;
    if (!colorToMultiplier(multiplier, multiplierValue)) return MULTIPLIER_DECODE_FAILED;
    uint64_t ohm = colorToOhm(colors) * multiplierValue;
    float toleranceValue;
    if (!colorToTolerance(tolerance, toleranceValue)) return TOLERANCE_DECODE_FAILED;
    resistor = Resistor(Resistor::Type::BAND4, ohm, toleranceValue, 0);
    return OK;
}

Decoder::Result
Decoder::decode5Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance, Resistor &resistor) {
    float multiplierValue;
    if (!colorToMultiplier(multiplier, multiplierValue)) return MULTIPLIER_DECODE_FAILED;
    uint64_t ohm = colorToOhm(colors) * multiplierValue;
    float toleranceValue;
    if (!colorToTolerance(tolerance, toleranceValue)) return TOLERANCE_DECODE_FAILED;
    resistor = Resistor(Resistor::Type::BAND5, ohm, toleranceValue, 0);
    return OK;
}

Decoder::Result Decoder::decode6Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance,
                     TemperatureCoefficientColor temperatureCoefficient, Resistor &resistor) {
    float multiplierValue;
    if (!colorToMultiplier(multiplier, multiplierValue)) return MULTIPLIER_DECODE_FAILED;
    uint64_t ohm = colorToOhm(colors) * multiplierValue;
    float toleranceValue;
    if (!colorToTolerance(tolerance, toleranceValue)) return TOLERANCE_DECODE_FAILED;
    uint8_t temperatureCoefficientValue;
    if (!colorToTemperatureCoefficient(temperatureCoefficient, temperatureCoefficientValue))
        return TEMPERATURE_COEFFICIENT_DECODE_FAILED;
    resistor = Resistor(Resistor::Type::BAND6, ohm, toleranceValue, temperatureCoefficientValue);
    return OK;
}