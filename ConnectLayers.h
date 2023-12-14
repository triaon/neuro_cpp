#ifndef CONNECTEDLAYER_H
#define CONNECTEDLAYER_H

#include <vector>
using std::vector;
class ConnectLayers {
public:
    ConnectLayers(int inputSize, int outputSize);
    vector<float> apply(const vector<float>& input);

private:
    vector<vector<float>> weights;
    vector<float> biases;
    int inputSize;
    int outputSize;
};

#endif
