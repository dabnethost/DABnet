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
                    unsigned short portID;
                    strainType type;
                    std::string strainName;
                    float voltage;
                };
            
                struct dabFile {
                    unsigned int fileSize;
                    unsigned short version;
                    std::string name;
                    std::string author;
                    std::vector<portConfig> portConfigs;
                    char magic[];
                };

        };
    }

}