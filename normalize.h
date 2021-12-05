
#ifndef NORMALIZE
#define NORMALIZE

#include <vector>

/**
 * @brief Outlines the Normalize class which contains a single process to normalize a vector of floating points
 * 
 */
class Normalize {
    public:
        /**
         * @brief The process method in the normalize class takes a vector of floating point values, find the maximum absolute value 
         * contained in that vector, then divides every element of the vector by that value, thus normalizing it to between -1 and 1
         * 
         * @param input Vector containing the sound data in floating point
         * @return std::vector<float> 
         */
        static std::vector<float> process(const std::vector<float>& input);
};


#endif