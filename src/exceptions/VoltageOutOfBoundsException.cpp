#include "VoltageOutOfBoundsException.hpp"

namespace DABnetUtils::DABnetExceptions {

    VoltageOutOfBoundsException::VoltageOutOfBoundsException(char const* const message) : std::runtime_error(message) {
        
    }

}
