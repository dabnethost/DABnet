#pragma once

#include "..\exceptions\VoltageOutOfBoundsException.hpp"
#include <stdexcept>
#include <iostream>
#include <cmath>
#include <string>

#define BUS_SIZE 8
#define MAX_VOLTAGE 5

namespace DABnetUtils::VoltageEncoding {

    /**
     * @file VoltageEncoder.hpp
     * @author Jack Zautner
     * @date N/A
     * 
     * @brief This class will be able to convert the voltages for various ports
     * into binary and vice versa. it should allow support for different DAC sizes.
    */
    class VoltageEncoder {

        public:

            unsigned int bits; // Number of bits accepted by the DAC
            
            /**
             * @brief Convert a voltage into binary by scaling. Uses 8 and 5 as the default
             * bus size and maximum voltage, respectively
             * 
             * @throws VoltageOutOfBoundsException for voltages !(0 <= V <= MAX_VOLTAGE)
            */
            static int voltageToBinary(double voltage, int busSize = BUS_SIZE, int maxVolts = MAX_VOLTAGE);

            /**
             * @brief Convert a binary int into a floating point voltage
            */
            static double binaryToVoltage(int voltBinary, int busSize = BUS_SIZE, int maxVolts = MAX_VOLTAGE);

    };
}