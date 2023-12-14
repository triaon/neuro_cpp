#ifndef POOLLAYER_H
#define POOLLAYER_H

#include <vector>
using std::vector;
class PoolLayer {
    public:
    PoolLayer(int psize, int stride);
    vector<vector<float>> forward(const vector<vector<float>> &inp);
private:
    int poolsize;
    int stride;
};

#endif
