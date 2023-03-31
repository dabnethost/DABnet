#include <atomic>
#include <optional>

#ifndef SERIALIZER_H
#define SERIALIZER_H

#define DTP_ENABLE_SERIAL_DEFAULT() SerializeBase::enableSerial() // Used for enabling serialization in the default way

#define _THREADSAFE_OPT_SERIAL std::atomic<std::optional<SerializeMode>>

enum class SerializeMode {
    READ,
    WRITE
};

class SerializeBase {
    static constexpr float VERSION{1.0F};
    static std::atomic<bool> serializeEnabled;

    public:
        virtual ~SerializeBase() = 0;

        static void enableSerial();

        [[nodiscard]] auto getVersion() const noexcept -> float;
};

class Serializer : public SerializeBase {
    _THREADSAFE_OPT_SERIAL mode{std::nullopt};

    public:
        explicit Serializer();

        void setSerializeMode(SerializeMode m);

        auto read(std::string& fileName) -> bool; // This should probably have parameters
        auto write(std::string& fileName) -> bool; // This should probably have parameters
};

#endif /* SERIALIZER_H */