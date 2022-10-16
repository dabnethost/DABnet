#include "StructureTools.hpp"

namespace DABnetUtils {

    namespace DABformat {

        Structure::dabFile StructureTools::stringArrayToDabFile(std::string strings[]) {
            
            Structure::dabFile d;

            d.version = 1;

            return d;
        }
    }
}