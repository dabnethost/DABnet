#include "Serializer.hpp"

#include <atomic>
#include <string>

#ifndef SYSTEM_BASE_H
#define SYSTEM_BASE_H

#define DABNET_WARN_THROTTLE() false // Placeholder, will eventually be used for warnings while running the system

struct DriverStatus {
    bool database;
    bool server;
    bool network;
};

class SystemBase {
    static constexpr float VERSION{1.0F};

    std::atomic<bool> databaseDriverEnabled;
    std::atomic<bool> serverDriverEnabled;
    std::atomic<bool> networkDriverEnabled;

    DriverStatus driverStatus;

    void assignDriverStatus(const bool d, const bool s, const bool n);
    auto connectToDatabase(const std::string& path) -> bool;

    public:
        Serializer serial;

        static void warn(std::string message);

        explicit SystemBase();
        SystemBase(SystemBase &other) = delete;
        SystemBase(SystemBase &&other) = delete;

        auto ensureDriverStatus() -> bool;

        [[nodiscard]] auto getVersion() const -> float;
        [[nodiscard]] auto getDriverStatus() const -> DriverStatus;
};

#endif /* SYSTEM_BASE_H */