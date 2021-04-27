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

uint64_t Resistor::getOhm() const {
    return this->ohm;
}

Resistor::Type Resistor::getType() const {
    return this->type;
}

uint64_t Resistor::getTolerance() const {
    return this->tolerance;
}

uint64_t Resistor::getTemperatureCoefficient() const {
    return this->temperature_coefficient;
}
