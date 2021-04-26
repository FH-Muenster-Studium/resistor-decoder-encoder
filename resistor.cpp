//
// Created by Fabian Terhorst on 26.04.21.
//

#include "resistor.h"

Resistor::Resistor(Resistor::Type type, uint64_t ohm, float tolerance, uint8_t temperature_coefficient) {
    this->type = type;
    this->ohm = ohm;
    this->tolerance = tolerance;
    this->temperature_coefficient = temperature_coefficient;
}

int Resistor::getOhm() {
    return this->ohm;
}
