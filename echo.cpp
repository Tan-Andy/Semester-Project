
#include "echo.h"


/**
 * Implements the Echo class
 */

std::vector<float> Echo::process(const std::vector<float>& inputData, float gain, int delay, int numChannels){
    std::vector<float> outputData;
    int trueDelay = delay * numChannels;
    outputData.reserve(inputData.size() + trueDelay);

    for(int j = 0; j < inputData.size() + trueDelay; j++){
        if(j > trueDelay && j < inputData.size()){
            outputData.push_back(inputData[j]+gain*outputData[j-trueDelay]);
        }
        else if(j >= inputData.size()){
            outputData.push_back(gain*outputData[j-trueDelay]);
        }
        else{
            outputData.push_back(inputData[j]);
        }
    }
    return outputData;
}



