#include "normalize.h"
#include <cmath>
#include <iostream>





std::vector<float> Normalize::process(const std::vector<float>& inputData){
    std::vector<float> outputData;
    outputData.reserve(inputData.size());

    float maxValue = abs(inputData[0]);
    for(int i = 0; i  < inputData.size();i++){
        if(abs(inputData[i]) > maxValue){
            maxValue = abs(inputData[i]);
        }
    }
    for(int i = 0; i <inputData.size(); i++){
        outputData.push_back(inputData[i] / maxValue);
    }
    return outputData;
}