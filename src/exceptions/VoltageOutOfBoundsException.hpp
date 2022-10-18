#include <stdexcept>

namespace DABnetUtils::DABnetExceptions {

    /**
     * @brief Exception for when the voltage is out of bounds
     * 
     * @author Jack Zautner
     * @date 18-10-2022
    */
    class VoltageOutOfBoundsException : public std::exception {

        /**
         * @brief Called when exception is thrown (I believe)
        */
        char* what() const throw();
    };
}