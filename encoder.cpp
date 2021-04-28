//
// Created by Fabian Terhorst on 26.04.21.
//

#include "encoder.hpp"

bool cmpf(float A, float B, float epsilon = 0.005f) {
    return (fabs(A - B) < epsilon);
}

MultiplierColor Encoder::multiplierToColor(float multiplier) {
    if (cmpf(multiplier, 1)) {
        return MultiplierColor::BLACK;
    }
    if (cmpf(multiplier, 10)) {
        return MultiplierColor::BROWN;
    }
    if (cmpf(multiplier, 100)) {
        return MultiplierColor::RED;
    }
    if (cmpf(multiplier, 1 * 1000)) {
        return MultiplierColor::ORANGE;
    }
    if (cmpf(multiplier, 10 * 1000)) {
        return MultiplierColor::YELLOW;
    }
    if (cmpf(multiplier, 100 * 1000)) {
        return MultiplierColor::GREEN;
    }
    if (cmpf(multiplier, 1 * 1000 * 1000)) {
        return MultiplierColor::BLUE;
    }
    if (cmpf(multiplier, 0.1)) {
        return MultiplierColor::GOLD;
    }
    if (cmpf(multiplier, 0.01)) {
        return MultiplierColor::SILVER;
    }
    return MultiplierColor::BLACK;
}

ToleranceColor Encoder::toleranceToColor(float tolerance) {
    if (cmpf(tolerance, 1)) {
        return ToleranceColor::BROWN;
    }
    if (cmpf(tolerance, 2)) {
        return ToleranceColor::RED;
    }
    if (cmpf(tolerance, 0.5)) {
        return ToleranceColor::GREEN;
    }
    if (cmpf(tolerance, 0.25)) {
        return ToleranceColor::BLUE;
    }
    if (cmpf(tolerance, 0.1)) {
        return ToleranceColor::VIOLET;
    }
    if (cmpf(tolerance, 5)) {
        return ToleranceColor::GOLD;
    }
    if (cmpf(tolerance, 10)) {
        return ToleranceColor::SILVER;
    }
    return ToleranceColor::BROWN;
}

TemperatureCoefficientColor Encoder::temperatureCoefficientToColor(uint8_t temperatureCoefficient) {
    switch (temperatureCoefficient) {
        case 250:
            return TemperatureCoefficientColor::BLACK;
        case 100:
            return TemperatureCoefficientColor::BROWN;
        case 50:
            return TemperatureCoefficientColor::RED;
        case 15:
            return TemperatureCoefficientColor::ORANGE;
        case 25:
            return TemperatureCoefficientColor::YELLOW;
        case 20:
            return TemperatureCoefficientColor::GREEN;
        case 10:
            return TemperatureCoefficientColor::BLUE;
        case 5:
            return TemperatureCoefficientColor::VIOLET;
        case 1:
            return TemperatureCoefficientColor::GREY;
        default:
            return TemperatureCoefficientColor::BLACK;
    }
}

std::vector<Color> Encoder::encode(const Resistor &resistor) {
    std::vector<Color> colors;
    switch (resistor.getType()) {
        case Resistor::Type::BAND4:
            colors.reserve(4);
            break;
        case Resistor::Type::BAND5:
            colors.reserve(5);
            break;
        case Resistor::Type::BAND6:
            colors.reserve(6);
            break;
        default:
            return colors;
    }

    uint64_t ohm = resistor.getOhm();

    float multiplier;

    // ignore gold, silver multiplier
    if ((ohm * 10 % 10) != 0) { // number place
        multiplier = 0.1;
    } else if ((ohm * 100 % 10) != 0) { // 2 number places
        multiplier = 0.01;
    } else if (ohm < 1000) {
        multiplier = 1;
    } else if (ohm < 10000) {
        multiplier = 10;
    } else if (ohm < 100000) {
        multiplier = 100;
    } else if (ohm < 1000000) {
        multiplier = 1000;
    } else if (ohm < 10000000) {
        multiplier = 10000;
    } else if (ohm < 100000000) {
        multiplier = 100000;
    } else if (ohm < 1000000000) {
        multiplier = 1000000;
    } else {
        // value to large
        return colors;
    }

    switch (resistor.getType()) {
        case Resistor::Type::BAND4: {
            uint64_t digitOhm = (uint64_t) ((double) ohm / multiplier);

            uint64_t secondDigit = digitOhm % 10;

            uint64_t firstDigit = ((digitOhm - secondDigit) / 10) % 10;

            colors.push_back((Color) firstDigit);
            colors.push_back((Color) secondDigit);
        }
            break;
        case Resistor::Type::BAND5:
        case Resistor::Type::BAND6: {
            uint64_t digitOhm = (uint64_t) ((double) ohm / multiplier);

            uint64_t thirdDigit = digitOhm % 10;

            uint64_t secondDigit = ((digitOhm - thirdDigit) / 10) % 10;

            uint64_t firstDigit = ((digitOhm - secondDigit - thirdDigit) / 100) % 10;

            colors.push_back((Color) firstDigit);
            colors.push_back((Color) secondDigit);
            colors.push_back((Color) thirdDigit);
        }
            break;
    }

    colors.push_back((Color) multiplierToColor(multiplier));

    colors.push_back((Color) toleranceToColor(resistor.getTolerance()));

    if (resistor.getType() == Resistor::Type::BAND6) {
        colors.push_back((Color) temperatureCoefficientToColor(resistor.getTemperatureCoefficient()));
    }

    return colors;
}
