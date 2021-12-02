
#include "echo.h"

//We convert everything to -1 to 1 range and then we should be able to use this function for all the echo.
//Stereo needs twice the delay

std::vector<float> Echo::process(const std::vector<float>& inputData, float gain, int delay){
    std::vector<float> outputData;
    outputData.reserve(inputData.size());
    for(int j = 0; j < inputData.size(); j++){
        if(j > delay){
            outputData.push_back(inputData[j]+gain*outputData[j-delay]);
        }
        else{
            outputData.push_back(inputData[j]);
        }
    }

    return outputData;
}


