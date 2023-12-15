#include "ConnectLayers.h"
#include <random>

ConnectLayers::ConnectLayers(int inputSize, int outputSize) : inputSize(inputSize), outputSize(outputSize) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    weights.resize(outputSize, vector<float>(inputSize));
    biases.resize(outputSize);
    for (int i = 0; i < outputSize; ++i) {
        for (int j = 0; j < inputSize; ++j) {
            weights[i][j] = d(gen);
        }
        biases[i] = d(gen);
    }
}

vector<float> ConnectLayers::apply(const vector<float>& input) {
    vector<float> output(outputSize, 0.0f);
    for (int i = 0; i < outputSize; ++i) {
        for (int j = 0; j < inputSize; ++j) {
            output[i] += input[j] * weights[i][j];
        }
        output[i] += biases[i];
    }
    return output;
}

