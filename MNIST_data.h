#ifndef MNIST_DATA_H
#define MNIST_DATA_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
class MnistData {
public:
    void loadData(std::string fileName);
    std::vector<std::vector<float>> getTrainData();
    std::vector<std::vector<float>> getTestData();

private:
    std::vector<std::vector<float>> trainData;
    std::vector<std::vector<float>> testData;
};
#endif
