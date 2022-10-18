#include "VoltageOutOfBoundsException.hpp"

namespace DABnetUtils::DABnetExceptions {

    char* VoltageOutOfBoundsException::what() const throw() {
        return "Voltage is out of bounds";
    }

}
