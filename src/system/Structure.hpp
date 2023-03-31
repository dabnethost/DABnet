/**
 * @file Structure.hpp
 * @author Jack Zautner
 * @date 1 Dec 2022
 * 
 * @brief Structure for the .dab binary
 */
#ifndef STRUCTURE_GUARD
#define STRUCTURE_GUARD
#endif

#include <string>
#include <vector>

namespace DABnetUtils {

    namespace DABformat {

        /**
         * @brief defines types of strains for advanced port configurations.
         * 
         * @deprecated no support as of now. Will possibly change this in the future
         */
        enum class strainType {
            INDICA,
            SATIVA,
            HYBRID
        };

        class Structure {

            public:

                /**
                 * @brief structure to hold configurations for specific ports
                 * 
                 * @deprecated no support as of now. Will possibly change this in the future
                 */
                struct portConfig {
                    unsigned short portID;  // ID of this port
                    strainType type;        // Type of strain for this port
                    std::string strainName; // Name of strain for this port
                    float voltage;          // Voltage given to this port
                };
            
                /**
                 * @brief structure that will be converted to a .dab binary 
                 * 
                 * @bug it doesn't fucking run
                 */
                struct dabFile {
                    std::uint32_t fileSize;            // Size of file
                    std::uint8_t version;              // Version of config
                    std::string author;                // Name of user who made this config
                    std::string name;                  // Name of config 
                    std::uint8_t numPorts;             // Number of ports occupied by cartriges
                    std::vector<float> voltages;       // Array containing a voltage for each port
                    char magic[3] = { 'D', 'A', 'B' }; // Magic array for identifying the .dab binary
                };

        };
    }

}