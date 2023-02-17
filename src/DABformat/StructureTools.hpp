/**
 * @file StructureTools.cpp
 * @author Jack Zautner
 * @date 2023-2-16
 * 
 * @brief Contains methods to geneerate a .dab file
 */
#ifndef STRUCTURE_GUARD
#include "Structure.hpp"
#endif

#include "..\util\util.hpp"
#include <fstream>
#include <iostream>

#ifndef STRUCTURE_TOOLS_GUARD
#define STRUCTURE_TOOLS_GUARD
namespace DABnetUtils {

    namespace DABformat {

        class StructureTools {

            public:

                /**
                 * @brief temporary function to read from a file and convert its contents to a
                 * vector of strings.
                 * 
                 * NOTE: Only to be used for testing as of 1 Dec 2022
                 */
                static auto fileToStrings(const std::string fileName) -> std::vector<std::string>;

                /**
                 * @brief Converts an array of strings into a dabFile structure for later parsing
                 * into bytes
                 * 
                 * @todo Change to read directly from the cartcontroller or pi rather than having
                 * the string array intermediary. 
                 */
                static auto encodeToDabFile(std::vector<std::string> data) -> Structure::dabFile;

                /**
                 * @brief Convert a dabFile structure into binary.
                 * 
                 * @return 0 if successful, 1 if failed
                 */
                static int exportDAB(const Structure::dabFile& d, const std::string& name);
        };
    }
}

#endif