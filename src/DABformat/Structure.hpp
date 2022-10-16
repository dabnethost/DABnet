#include <string>
#include <vector>

namespace DABnetUtils {

    namespace DABformat {

        enum class strainType {
            INDICA,
            SATIVA,
            HYBRID
        };

        class Structure {

            public:

                struct portConfig {
                    unsigned short portID;  // ID of this port
                    strainType type;        // Type of strain for this port
                    std::string strainName; // Name of strain for this port
                    float voltage;          // Voltage given to this port
                };
            
                struct dabFile {
                    unsigned int fileSize;               // Size of file
                    unsigned short version;              // Version of config
                    std::string name;                    // Name of config
                    std::string author;                  // Name of user who made this config
                    std::vector<portConfig> portConfigs; // Configurations for each individual port
                    char magic[3] = { 'D', 'A', 'B' };   // Magic array for identifying the .dab binary
                };

        };
    }

}