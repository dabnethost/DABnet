/**
 * @file SerialUser.hpp
 * @author Jack Zautner
 * @date 21-04-2023
 * 
 * @brief Abstraction for a user entry in the database
*/
#include <cstdint>
#include <string>

#include "AbstractSerializable.hpp"

#ifndef USER_H
#define USER_H

enum UserType {
    USER,
    ADMIN,
    SYSTEM
};

typedef struct {
    std::uint32_t uID;
    std::string uName;
    UserType uType;
} userInfo;

class SerialUser : public AbstractSerializable<SerialUser> {
    static uint32_t userCount;
    userInfo uInfo;

    public:
        SerialUser(std::string name, UserType type);
        
        void serialize() override;
        [[nodiscard]] SerialUser deserialize() override;
};

#endif /* USER_H */