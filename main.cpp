#include <iostream>
#include "decoder.h"

void decode(const std::vector<Color>& colors) {
    Resistor resistor{};
    Decoder::Result result = Decoder::decode(colors, resistor);
    if (result != Decoder::Result::OK) {
        std::cout << "decode failed " << Decoder::result_to_string(result) << std::endl;
    } else {
        std::cout << "---colors---" << std::endl;
        for (int i = 0, length = colors.size();i < length;i++) {
            std::cout << "color" << std::to_string(i) << ": " << Decoder::color_to_string(colors[i]) << std::endl;
        }
        std::cout << "---result---" << std::endl;
        std::cout << "type: " << Decoder::type_to_string(resistor.getType()) << std::endl;
        std::cout << "ohm: " << std::to_string(resistor.getOhm()) << std::endl;
        std::cout << "tolerance: " << std::to_string(resistor.getTolerance()) << std::endl;
        std::cout << "temperature coefficient: " << std::to_string(resistor.getTemperatureCoefficient()) << std::endl;
    }
}

int main() {
    decode({Color::BROWN, Color::BLACK, Color::BLACK, Color::BROWN});
    return 0;
}
