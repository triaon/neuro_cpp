#include "ConvolutionalLayer.h"
#include <random>
#include <algorithm>

ConvolutionalLayer::ConvolutionalLayer(int inputSize, int numFilters, int filterSize) : inputSize(inputSize), numFilters(numFilters), filterSize(filterSize) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<> d(0, 1);
    filters.resize(numFilters, vector<vector<float>>(filterSize, vector<float>(filterSize)));
    for (auto &filter : filters) {
        for (auto &row : filter) {
            for (float &val : row) {
                val = d(gen);
            }
        }
    }
}

vector<vector<float>> ConvolutionalLayer::apply(const vector<vector<float>>& input) {
    int outputSize = inputSize - filterSize + 1;
    vector<vector<float>> output(outputSize, vector<float>(outputSize, 0));
    for (int filterIndex = 0; filterIndex < numFilters; ++filterIndex) {
        for (int i = 0; i < outputSize; ++i) {
            for (int j = 0; j < outputSize; ++j) {
                float sum = 0.0f;
                for (int fi = 0; fi < filterSize; ++fi) {
                    for (int fj = 0; fj < filterSize; ++fj) {
                        sum += input[i + fi][j + fj] * filters[filterIndex][fi][fj];
                    }
                }
                output[i][j] = std::max(0.0f, sum); // ReLU activation
            }
        }
    }
    return output;
}

