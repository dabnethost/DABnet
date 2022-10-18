#include <stdexcept>

namespace DABnetUtils::DABnetExceptions {

    /**
     * @brief Doesn't work because I don't understand namespaces lol
    */
    class VoltageOutOfBoundsException : public std::exception {

        char* what() const throw();
    };
}