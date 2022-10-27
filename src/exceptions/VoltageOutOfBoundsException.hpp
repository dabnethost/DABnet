#pragma once

#include <stdexcept>

namespace DABnetUtils::DABnetExceptions {

    /**
     * @brief Exception for when the voltage is out of bounds
     * 
     * @author Jack Zautner
     * @date 18-10-2022
    */
    class VoltageOutOfBoundsException : public std::runtime_error {

        public:

            VoltageOutOfBoundsException(char const* const message = "Voltage out of bounds");
    };
}