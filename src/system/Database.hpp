#include "Serializer.hpp"

#include <vector>
#include <string>

#ifndef DATABASE_H
#define DATABASE_H

class Database {
    static constexpr float VERSION{1.0F};
    // static const std::vector<std::string> allowedTypes{"DAB", "DABMETA", "TXT"};
    uint16_t entryCount;
    Serializer serial{};

    public:
        void iterate(std::string& directory, void (*foo)(volatile std::string&));
        Database(std::string& path);
};

#endif /* DATABASE_H */