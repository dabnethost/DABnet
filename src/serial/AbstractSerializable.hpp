/**
 * @file AbstractSerializable.hpp
 * @author Jack Zautner
 * @date 21-04-2023
 * 
 * @brief This is an abstract base class and template for all serializable objects within the DABnet system. All
 * serializable objects will inherit from this.
 * 
 * NOTE: Any class that inherits from this must override all methods marked FORCE_OVERRIDE
*/
#include <iostream>

#ifndef ABSTRACT_SERIALIZABLE_H
#define ABSTRACT_SERIALIZABLE_H

#define FORCE_OVERRIDE virtual
#define NODISCARD [[nodiscard]]

template <typename T>
class AbstractSerializable {
    static float VERSION{0.1F};

    // I/O streams
    std::istream* serialInput;
    std::ostream* serialOutput;

    // Methods for serializing and deserializing the object
    FORCE_OVERRIDE void serialize();
    NODISCARD FORCE_OVERRIDE T deserialize();

    NODISCARD auto getVersion() const noexcept -> float;
};

#endif /* ABSTRACT_SERIALIZABLE_H */