//
// Created by Fabian Terhorst on 26.04.21.
//

#ifndef PRAKTIKUM_1_RESISTOR_H
#define PRAKTIKUM_1_RESISTOR_H

#include <cstdint>

class Resistor {
public:
    enum Type {
        BAND4, BAND5
    };

    Resistor() = default;

    Resistor(Type type, uint64_t ohm, float tolerance, uint8_t temperature_coefficient);

    getOhm();

private:
    Type type;
    uint64_t ohm;
    float tolerance;
    uint8_t temperature_coefficient;
};


#endif //PRAKTIKUM_1_RESISTOR_H
