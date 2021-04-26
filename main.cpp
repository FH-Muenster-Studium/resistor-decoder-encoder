#include <iostream>
#include "decoder.h"

int main() {
    Resistor resistor{};
    bool result = Decoder::decode4Band(Color::BLACK, Color::BLACK, Color::BLACK, Color::BLACK, resistor);
    if (!result) {
        std::cout << "decode failed" << std::endl;
    } else {
        std::cout << std::to_string(resistor.getOhm()) << std::endl;
    }
    return 0;
}