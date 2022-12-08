/**
 * @file StructureTools.hpp
 * @author Jack Zautner
 * @date 30 Nov 2022
 * 
 * @brief Contains methods to generate a .dab file
 */
#ifndef STRUCTURE_TOOLS_GUARD
#define STRUCTURE_TOOLS_GUARD
#endif

#ifndef STRUCTURE_GUARD
#include "Structure.hpp"
#endif

#include "..\util\util.hpp"
#include <fstream>
#include <iostream>

namespace DABnetUtils {

    namespace DABformat {

        using std::ios;

        class StructureTools {

            public:

                /**
                 * @brief temporary function to read from a file and convert its contents to a
                 * vector of strings.
                 * 
                 * NOTE: Only to be used for testing as of 1 Dec 2022
                 */
                static auto fileToStrings(const std::string fileName) -> std::vector<std::string> {

                    std::fstream file; 
                    std::vector<std::string> data;

                    file.open(fileName, ios::in);

                    if (file.is_open()) {
                        std::string line;
                        while (std::getline(file, line)) {
                            data.push_back(line);
                        }

                        file.close();
                    }

                    return data;
                }

                /**
                 * @brief Converts an array of strings into a dabFile structure for later parsing
                 * into bytes
                 * 
                 * @todo Change to read directly from the cartcontroller or pi rather than having
                 * the string array intermediary. 
                 */
                static auto encodeToDabFile(std::vector<std::string> data) -> Structure::dabFile {

                    Structure::dabFile d;
            
                    d.version = 1; // 1 byte
                    d.author = data[0];          
                    d.name = data[1];
                    d.numPorts = std::stoi(data[2]); // 1 byte
                    
                    std::string delimiter = ",";
                    std::size_t pos = 0;
                    std::string token;
                    while ((pos = data[3].find(delimiter)) != std::string::npos) {
                        token = data[3].substr(0, pos);
                        d.voltages.push_back(std::stof(token));
                        data[3].erase(0, pos + delimiter.length());
                    }

                    std::uint8_t vsize = vectorsizeof(d.voltages); // 1 Byte

                    d.fileSize = (1 + 1 + d.author.size() + d.name.size() + vsize + 1 + sizeof(d.magic)); //not finished

                    return d;

                }

                /**
                 * @brief Convert a dabFile structure into binary.
                 * 
                 * @return 0 if successful, 1 if failed
                 */
                static int exportDAB(const Structure::dabFile& d, const std::string& name) {
                    
                    std::string fileName = name + ".dab";
                    std::ofstream wf(fileName, ios::out | ios::binary);

                    if (!wf) {
                        std::cout << "Cannot open file" << std::endl;
                        return 1;
                    }

                    // Write to file
                    wf.write((char*)&d, d.fileSize);

                    wf.close();
                    if (!wf.good()) {
                        std::cout << "Error occured while writing" << std::endl;
                        return 1;
                    }

                    return 0;
                }
        };
    }
}