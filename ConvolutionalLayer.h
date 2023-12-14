#ifndef CONVOLUTIONALLAYER_H
#define CONVOLUTIONALLAYER_H

#include <vector>
using std::vector;
class ConvolutionalLayer {
public:
    ConvolutionalLayer(int inputSize, int numFilters, int filterSize);
    vector<vector<float>> apply(const vector<vector<float>>& input);

private:
    int inputSize;
    int numFilters;
    int filterSize;
    vector<vector<vector<float>>> filters; // 3D vector for filters
};

#endif // CONVOLUTIONALLAYER_H
