#ifndef GAIN_H
#define GAIN_H

#include <vector>


class Gain {
    public:
        static std::vector<float> process(const std::vector<float>& input, float gain);

};

#endif