/**
 * @file StructureTools.cpp
 * @author Jack Zautner
 * @date 2023-2-16
 *
 * @brief Implementation of structure tools
 */
#ifndef STRUCTURE_GUARD
#include "Structure.hpp"
#endif

#ifndef STRUCTURE_TOOLS_GUARD
#include "StructureTools.hpp"
#endif

using std::ios;
using namespace DABnetUtils::DABformat;

auto StructureTools::fileToStrings(const std::string fileName) -> std::vector<std::string> {

    std::fstream file;
    std::vector<std::string> data;

    file.open(fileName, ios::in);

    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line))
        {
            data.push_back(line);
        }

        file.close();
    }

    return data;
}
 
auto StructureTools::encodeToDabFile(std::vector<std::string> data) -> Structure::dabFile {

    Structure::dabFile d;

    d.version = 1; // 1 byte
    d.author = data[0];
    d.name = data[1];
    d.numPorts = std::stoi(data[2]); // 1 byte

    std::string delimiter = ",";
    std::size_t pos = 0;
    std::string token;
    while ((pos = data[3].find(delimiter)) != std::string::npos)
    {
        token = data[3].substr(0, pos);
        d.voltages.push_back(std::stof(token));
        data[3].erase(0, pos + delimiter.length());
    }

    std::uint8_t vsize = vectorsizeof(d.voltages); // 1 Byte

    std::size_t dataSize = 4 + 1 + d.author.size() + d.name.size() + 1 + vsize + sizeof(d.magic);

    d.fileSize = sizeof(Structure::dabFile) + dataSize; // not finished

    return d;
}

int StructureTools::exportDAB(const Structure::dabFile &d, const std::string &name) {

    std::string fileName = name + ".dab";
    std::ofstream wf(fileName, ios::out | ios::binary);

    if (!wf)
    {
        std::cout << "Cannot open file" << std::endl;
        return 1;
    }

    // Write to file
    wf.write((char *)&d, d.fileSize);

    wf.close();
    if (!wf.good())
    {
        std::cout << "Error occured while writing" << std::endl;
        return 1;
    }

    return 0;
}