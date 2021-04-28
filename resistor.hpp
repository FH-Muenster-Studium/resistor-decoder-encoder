//
// Created by Fabian Terhorst on 26.04.21.
//

#pragma once

#include <cstdint>

class Resistor {
public:
    enum class Type : uint8_t {
        BAND4 = 4, BAND5 = 5, BAND6 = 6
    };

    Resistor() = default;

    Resistor(Resistor::Type type, double ohm, float tolerance);

    Resistor(double ohm, float tolerance, uint8_t temperature_coefficient);

    [[nodiscard]] Type getType() const;

    [[nodiscard]] double getOhm() const;

    [[nodiscard]] uint64_t getTolerance() const;

    [[nodiscard]] uint64_t getTemperatureCoefficient() const;

private:
    Type type;
    double ohm;
    float tolerance;
    uint8_t temperature_coefficient;
};
