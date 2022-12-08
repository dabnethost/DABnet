/**
 * @file util.cpp
 * @author Jack Zautner
 * @brief Utility functions for DABnet
 * @date 2022-12-08
*/
#include <vector>

namespace DABnetUtils {

    template <typename T> std::size_t vectorsizeof(const typename std::vector<T>& vec) {
        return sizeof(T) * vec.size();
    }
    
}