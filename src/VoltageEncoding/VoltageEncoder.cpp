#include "VoltageEncoder.hpp"
#include <iostream>

namespace DABnetUtils::VoltageEncoding {

    int VoltageEncoder::voltageToBinary(double voltage, int busSize, int maxVolts) {

        if (voltage > maxVolts || voltage < 0) {
            throw DABnetExceptions::VoltageOutOfBoundsException();
        }

        unsigned int maxBusCapacity = pow(2, busSize) - 1;
        double scalingFactor = maxBusCapacity / maxVolts;

        int scaledVolts = round(voltage * scalingFactor);

        std::string binaryTranslation = "";
        
        unsigned short j;

        for (j = 1 << busSize; j > 0; j /= 2) {

            if ((j & scaledVolts) != 0) {
                binaryTranslation += "1";
            } else {
                binaryTranslation += "0";
            }

        }

        return stoi(binaryTranslation);
    }

    double VoltageEncoder::binaryToVoltage(int voltBinary, int busSize, int maxVolts) {
        // Algorithm for binary to decimal is from
        // https://www.programiz.com/cpp-programming/examples/binary-decimal-convert

        int dec = 0, i = 0, rem;

        while (voltBinary != 0) {
            rem = voltBinary % 10;
            voltBinary /= 10;
            dec += rem * pow(2, i);
            ++i;

        }

        unsigned int maxBusCapacity = pow(2, busSize) - 1;
        double scalingFactor = maxBusCapacity / maxVolts;

        return std::round((static_cast<double>(dec) / scalingFactor) * 1000) / 1000;
    }
}