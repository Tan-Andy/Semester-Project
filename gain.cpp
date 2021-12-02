#include "gain.h"


std::vector<float> Gain::process(const std::vector<float>& inputData, float gain){
    std::vector<float> outputData;
    outputData.reserve(inputData.size());
    for(int j = 0; j <inputData.size();j++){
        outputData.push_back(gain*inputData[j]);
    }
    return outputData;

}