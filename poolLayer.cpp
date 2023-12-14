#include "poolLayer.h"

PoolLayer::PoolLayer(int psize, int stride) : poolsize(psize), stride(stride) {}
vector<vector<float>> PoolLayer::forward(const vector<vector<float>> &inp) {
    int output_size = 1 + (inp.size() - poolsize) / stride;
    vector<vector<float>> out(output_size, vector<float>(output_size, 0));
    for (int i = 0; i < output_size; i++) {
        for (int j = 0; j < output_size; j++) {
            float maxx = 0;
            for (int k = 0; k < poolsize; k++) {
                for (int l = 0; l < poolsize; l++) {
                    maxx = std::max(maxx, inp[i * stride + k][j * stride * l]);
                }
            }
            out[i][j] = maxx;
        }
    }
    return out;
}