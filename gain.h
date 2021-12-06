#ifndef GAIN_H
#define GAIN_H

#include <vector>

/**
 * @brief Outlines the gain class which contains a method to multiply elements of a vector by scalar value
 * 
 */
class Gain {
    public:
        /**
         * @brief The process method in the gain class takes each element of a vector of floating points and multiplies it by a 
         * specified value to modify the overall amplitude of the wav file.
         * 
         * @param input Address to a vector containing the sound data in floating point
         * @param gain Floating point scalar multiplier of how much to change the amplitude of the wav. Values of gain close to 0 or much greater than
         * 1 may lead to inaudible files. 
         * @return std::vector<float> 
         */
        static std::vector<float> process(const std::vector<float>& input, float gain);

};

#endif