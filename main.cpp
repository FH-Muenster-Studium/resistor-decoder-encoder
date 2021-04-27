#include <iostream>
#include <iomanip>
#include "decoder.h"
#include "encoder.h"

void decode(const std::vector<Color> &colors, MultiplierColor multiplierColor, ToleranceColor toleranceColor,
            TemperatureCoefficientColor temperatureCoefficientColor) {
    Resistor resistor{};
    Decoder::decode6Band(colors, multiplierColor, toleranceColor, temperatureCoefficientColor,
                         resistor);
    std::cout << "<<---decoding--->>" << std::endl;
    std::cout << "---colors---" << std::endl;
    int i = 0;
    for (int length = colors.size(); i < length; i++) {
        std::cout << "color" << std::to_string(i) << ": " << Decoder::color_to_string(colors[i]) << std::endl;
    }
    std::cout << "color" << std::to_string(i++) << ": " << Decoder::color_to_string((Color) multiplierColor)
              << std::endl;
    std::cout << "color" << std::to_string(i++) << ": " << Decoder::color_to_string((Color) toleranceColor)
              << std::endl;
    std::cout << "color" << std::to_string(i++) << ": " << Decoder::color_to_string((Color) temperatureCoefficientColor)
              << std::endl;
    std::cout << "---result---" << std::endl;
    std::cout << "type: " << Decoder::type_to_string(resistor.getType()) << std::endl;
    std::cout << "ohm: " << std::fixed << std::setprecision(2) << resistor.getOhm() << std::endl;
    std::cout << "tolerance: " << std::to_string(resistor.getTolerance()) << std::endl;
    std::cout << "temperature coefficient: " << std::to_string(resistor.getTemperatureCoefficient()) << std::endl;
}

void encode(double ohm, float tolerance, uint8_t temperatureCoefficient) {
    std::cout << "<<---encoding--->>" << std::endl;
    Resistor resistor(ohm, tolerance, temperatureCoefficient);
    for (Color color : Encoder::encode(resistor)) {
        std::cout << Decoder::color_to_string(color) << std::endl;
    }
}

int main() {
    decode({Color::RED, Color::VIOLET, Color::YELLOW}, MultiplierColor::BLACK, ToleranceColor::BROWN,
           TemperatureCoefficientColor::GREEN);
    encode(274, 2, 0);
    return 0;
}
