//
// Created by Fabian Terhorst on 26.04.21.
//

#include "decoder.h"

float Decoder::colorToTolerance(ToleranceColor color) {
    switch (color) {
        case ToleranceColor::BROWN:
            return 1;
        case ToleranceColor::RED:
            return 2;
        case ToleranceColor::GREEN:
            return 0.5;
        case ToleranceColor::BLUE:
            return 0.25;
        case ToleranceColor::VIOLET:
            return 0.1;
        case ToleranceColor::GOLD:
            return 5;
        case ToleranceColor::SILVER:
            return 10;
    }
}

float Decoder::colorToMultiplier(MultiplierColor color) {
    switch (color) {
        case MultiplierColor::BLACK:
            return 1;
        case MultiplierColor::BROWN:
            return 10;
        case MultiplierColor::RED:
            return 100;
        case MultiplierColor::ORANGE:
            return 1 * 1000;
        case MultiplierColor::YELLOW:
            return 10 * 1000;
        case MultiplierColor::GREEN:
            return 100 * 1000;
        case MultiplierColor::BLUE:
            return 1 * 1000 * 1000;
        case MultiplierColor::GOLD:
            return 0.1;
        case MultiplierColor::SILVER:
            return 0.01;
    }
}

uint64_t Decoder::colorToOhm(const std::vector<Color> &colors) {
    uint64_t ohm = 0;
    for (int i = 0, length = colors.size();i < length;i++) {
        ohm += ((uint8_t) colors[i]) * std::pow(10, length - i - 1);
    }
    return ohm;
}

uint8_t Decoder::colorToTemperatureCoefficient(TemperatureCoefficientColor color) {
    switch (color) {
        case TemperatureCoefficientColor::BLACK:
            return 250;
        case TemperatureCoefficientColor::BROWN:
            return 100;
        case TemperatureCoefficientColor::RED:
            return 50;
        case TemperatureCoefficientColor::ORANGE:
            return 15;
        case TemperatureCoefficientColor::YELLOW:
            return 25;
        case TemperatureCoefficientColor::GREEN:
            return 20;
        case TemperatureCoefficientColor::BLUE:
            return 10;
        case TemperatureCoefficientColor::VIOLET:
            return 5;
        case TemperatureCoefficientColor::GREY:
            return 1;
    }
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

void Decoder::decode4Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance, Resistor &resistor) {
    double ohm = colorToOhm(colors) * colorToMultiplier(multiplier);
    resistor = Resistor(Resistor::Type::BAND4, ohm, colorToTolerance(tolerance));
}

void Decoder::decode5Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance, Resistor &resistor) {
    double ohm = colorToOhm(colors) * colorToMultiplier(multiplier);
    resistor = Resistor(Resistor::Type::BAND5, ohm, colorToTolerance(tolerance));
}

void Decoder::decode6Band(const std::vector<Color> &colors, MultiplierColor multiplier, ToleranceColor tolerance,
                     TemperatureCoefficientColor temperatureCoefficient, Resistor &resistor) {
    double ohm = colorToOhm(colors) * colorToMultiplier(multiplier);
    resistor = Resistor(ohm, colorToTolerance(tolerance), colorToTemperatureCoefficient(temperatureCoefficient));
}