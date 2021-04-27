//
// Created by Fabian Terhorst on 26.04.21.
//

#ifndef PRAKTIKUM_1_RESISTOR_H
#define PRAKTIKUM_1_RESISTOR_H

#include <cstdint>

class Resistor {
public:
    enum class Type: uint8_t {
        BAND4 = 4, BAND5 = 5, BAND6 = 6
    };

    Resistor() = default;

    Resistor(Type type, uint64_t ohm, float tolerance, uint8_t temperature_coefficient);

    [[nodiscard]] Type getType() const;

    [[nodiscard]] uint64_t getOhm() const;

    [[nodiscard]] uint64_t getTolerance() const;

    [[nodiscard]] uint64_t getTemperatureCoefficient() const;

private:
    Type type;
    uint64_t ohm;
    float tolerance;
    uint8_t temperature_coefficient;
};


#endif //PRAKTIKUM_1_RESISTOR_H
