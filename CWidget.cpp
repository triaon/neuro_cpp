#include "CWidget.h"
#include <QPainter>
#include <iostream>
using std::cout;
using std::endl;
CWidget::CWidget(QWidget *parent) : QWidget(parent) {
    dotCounter = dotCounter;
    matrix = vector<vector<int>>(32, vector<int>(32, 0));
    submitButton = new QPushButton("Submit", this);
    submitButton->setGeometry(200, 400, 100, 30);
    countLabel = new QLabel("Count: 0", this);
    countLabel->setGeometry(400, 450, 100, 30);
    connect(submitButton, &QPushButton::clicked, this, &CWidget::onSubmitClicked);
    setMouseTracking(true);
}

QSize CWidget::minimumSizeHint() const {
    return QSize(320, 320);
}

void CWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for (int i = 0; i < 32; ++i) {
        for (int j = 0; j < 32; ++j) {
            painter.setBrush(matrix[i][j] ? Qt::darkBlue : Qt::white);
            painter.drawRect(j * 10, i * 10, 10, 10);
        }
    }
}

void CWidget::mousePressEvent(QMouseEvent *event) {
    int x = event->pos().x() / 10;
    int y = event->pos().y() / 10;
    togglePixel(x, y);
    update();
}

void CWidget::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        int x = event->pos().x() / 10;
        int y = event->pos().y() / 10;
        togglePixel(x, y);
        update();
    }
}

void CWidget::togglePixel(int x, int y) { // Pixel Paint
    if (x >= 0 && x < 32 && y >= 0 && y < 32) {
        matrix[y][x] = 1;
    }
}

void CWidget::updateCountDots() { // dotCounter
    cout << endl;
    dotCounter = 0;
    for (const auto &row: matrix) {
        for (auto cell: row) {
            if (cell == 1) {
                dotCounter++;
            }
        }
    }
    cout << dotCounter << endl;
    countLabel->setText(QString("dots: %1").arg(dotCounter));
}

void CWidget::onSubmitClicked() { // debug function, matrix output to console, may be removed
    for (const auto &row: matrix) {
        for (auto cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    updateCountDots();
}

