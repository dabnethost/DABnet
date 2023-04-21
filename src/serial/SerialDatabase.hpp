/**
 * @file SerialDatabase.hpp
 * @author Jack Zautner
 * @date 21-04-2023
 * 
 * @brief Represents an abstraction for a database. Will contain methods to serialize and deserialize, and
 * additionally edit the database.
*/
#include "AbstractSerializable.hpp"
#include "SerialUser.hpp"

#ifndef DATABASE_H
#define DATABASE_H

template <class T>
class SerialDatabase : public AbstractSerializable<SerialDatabase> {
    constexpr char magic[] = {'D', 'A', 'B', 'D', 'B'};
    std::string dbName;
    std::string associatedPath;
    std::uint16_t entryCount;
    AbstractSerializable<T>* entries[];

    public:
        // Constructor
        SerialDatabase(std::string name, std::string path);

        // Serialization
        void serialize(bool encrypt=false) override; // NOTE: implement encryption later, leave false for now
        [[nodiscard]] SerialDatabase deserialize(bool isEncrypted=false) override;

        // Database editing
        void append(T entry);
        void insert(T entry, int index);
        T get(int index) const;
        [[nodiscard]] T remove();

        // Database sorting
        void sort(sortMode mode);
        void sortById();
        void sortByAlphabetical();
        void sortByTypeId();
        void sortByTypeAlphabetical();

        // Database generating
        [[nodiscard]] static SerialDatabase<T>& generate(std::string name, std::string path);
};

enum sortMode {
    BY_ID,
    BY_UNAME_ALPHABETICAL,
    BY_TYPE_ID,
    BY_TYPE_ALPHABETICAL
};

#endif /* DATABASE_H */