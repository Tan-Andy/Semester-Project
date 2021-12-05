#ifndef ECHO_H
#define ECHO_H

#include <vector>

/**
 * @brief The echo class provides a static function to process a vector containing sound data by applying an echo.
 * 
 */
class Echo {
    public:
        /**
         * @brief The process in the echo class takes a vector containing floating points, then takes a given value of the vector
         * multiplies it by a scalar gain, then adds it back into the vector after some delay. This creates an echo effect.
         * 
         * @param input Vector containing the sound data in floating point
         * @param gain Floating point scalar multiplier of how loud the echo should be, gain should be between 0 and 1 noninclusive
         * @param delay Integer value of how long after the initial sound should the sound be added back into the function, this 
         * value is in number of samples
         * @param numchannels Integer value of the number of channels that sound is being sampled from, should be 1 for mono and 2 for
         * stero this value is used to calculate the true delay of the sample in order to account for stereo files
         * @return std::vector<float> 
         */
        static std::vector<float> process(const std::vector<float>& input, float gain, int delay, int numchannels);

};

#endif