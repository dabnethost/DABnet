#include "Structure.hpp"

namespace DABnetUtils {

    namespace DABformat {

        static class StructureTools {

            public:

                /**
                 * Take strings from a text file, and convert it to our structure
                 * 
                 * @param strings[] array of strings from text file
                 * @return .dab file
                 * 
                 * @author Jack Zautner
                 * @date 15-10-2022
                */
                Structure::dabFile stringArrayToDabFile(std::string strings[]);

        }

    }
}