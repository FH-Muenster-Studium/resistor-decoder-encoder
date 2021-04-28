#include "resistor.hpp"

Resistor::Resistor(Resistor::Type type, double ohm, float tolerance) {
    this->type = type;
    this->ohm = ohm;
    this->tolerance = tolerance;
    this->temperature_coefficient = 0;
}

Resistor::Resistor(double ohm, float tolerance, uint8_t temperature_coefficient) {
    this->type = Type::BAND6;
    this->ohm = ohm;
    this->tolerance = tolerance;
    this->temperature_coefficient = temperature_coefficient;
}

double Resistor::getOhm() const {
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
