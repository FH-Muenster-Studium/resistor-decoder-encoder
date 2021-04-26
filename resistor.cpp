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

uint64_t Resistor::getOhm() {
    return this->ohm;
}

Resistor::Type Resistor::getType() {
    return this->type;
}

uint64_t Resistor::getTolerance() {
    return this->tolerance;
}

uint64_t Resistor::getTemperatureCoefficient() {
    return this->temperature_coefficient;
}
