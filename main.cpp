#include <QApplication>
#include "CWidget.h"
#include "ConvolutionalLayer.h"
#include "poolLayer.h"
#include "ConnectLayers.h"
#include <vector>
#include <iostream>
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CWidget widget;
    widget.show();
    ConvolutionalLayer convLayer(28, 8, 3);
    PoolLayer poolingLayer(2, 2);
    ConnectLayers fcLayer(20*20*8, 10);
    std::vector<std::vector<float>> inputData = MNIST_data("/home/ilya/Загрузки/mnist_train.csv");
    auto convOutput = convLayer.apply(inputData);
    auto poolOutput = poolingLayer.forward(convOutput);
    std::vector<float> flatInput(poolOutput.size() * poolOutput[0].size());
    std::copy(poolOutput.begin(), poolOutput.end(), flatInput.begin());
    auto fcOutput = fcLayer.apply(flatInput);
    for (float value : fcOutput) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    return app.exec();
}
