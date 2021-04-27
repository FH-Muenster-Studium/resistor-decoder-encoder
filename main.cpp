#include <iostream>
#include "decoder.h"

void decode(const std::vector<Color> &colors, MultiplierColor multiplierColor, ToleranceColor toleranceColor,
            TemperatureCoefficientColor temperatureCoefficientColor) {
    Resistor resistor{};
    Decoder::decode6Band(colors, multiplierColor, toleranceColor, temperatureCoefficientColor,
                         resistor);
    std::cout << "---colors---" << std::endl;
    int i = 0;
    for (int length = colors.size(); i < length; i++) {
        std::cout << "color" << std::to_string(i) << ": " << Decoder::color_to_string(colors[i]) << std::endl;
    }
    std::cout << "color" << std::to_string(i++) << ": " << Decoder::color_to_string((Color)multiplierColor) << std::endl;
    std::cout << "color" << std::to_string(i++) << ": " << Decoder::color_to_string((Color)toleranceColor) << std::endl;
    std::cout << "color" << std::to_string(i++) << ": " << Decoder::color_to_string((Color)temperatureCoefficientColor) << std::endl;
    std::cout << "---result---" << std::endl;
    std::cout << "type: " << Decoder::type_to_string(resistor.getType()) << std::endl;
    std::cout << "ohm: " << std::to_string(resistor.getOhm()) << std::endl;
    std::cout << "tolerance: " << std::to_string(resistor.getTolerance()) << std::endl;
    std::cout << "temperature coefficient: " << std::to_string(resistor.getTemperatureCoefficient()) << std::endl;
}

int main() {
    decode({Color::BROWN, Color::BLACK, Color::BLACK}, MultiplierColor::BROWN, ToleranceColor::BROWN,
           TemperatureCoefficientColor::GREEN);
    return 0;
}
