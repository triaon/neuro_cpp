#include "CWidget.h"
#include <QPainter>
#include <iostream>
using std::cout;
using std::endl;
CWidget::CWidget(QWidget *parent) : QWidget(parent) {
    matrix = vector<vector<int>>(28, vector<int>(28, 0));
    submitButton = new QPushButton("Submit", this);
    submitButton->setGeometry(200, 400, 120, 30);
    countLabel = new QLabel("Count: 0", this);
    countLabel->setGeometry(400, 450, 200, 50);
    connect(submitButton, &QPushButton::clicked, this, &CWidget::onSubmitClicked);
    setMouseTracking(true);
}

QSize CWidget::minimumSizeHint() const {
    return QSize(500, 500);
}

void CWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for (int i = 0; i < 28; ++i) {
        for (int j = 0; j < 28; ++j) {
            painter.setBrush(matrix[i][j] ? Qt::darkBlue : Qt::white);
            painter.drawRect(j * 12, i * 12, 12, 12);
        }
    }
}

void CWidget::mousePressEvent(QMouseEvent *event) {
    int x = event->pos().x() / 12;
    int y = event->pos().y() / 12;
    togglePixel(x, y);
    update();
}

void CWidget::mouseMoveEvent(QMouseEvent *event) {
    if (event->buttons() & Qt::LeftButton) {
        int x = event->pos().x() / 12;
        int y = event->pos().y() / 12;
        togglePixel(x, y);
        update();
    }
}

void CWidget::togglePixel(int x, int y) { // Pixel Paint
    if (x >= 0 && x < 28 && y >= 0 && y < 28) {
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

void CWidget::onSubmitClicked() { // debug function, matrix output to console + update dots counter, may be removed
    for (const auto &row: matrix) {
        for (auto cell: row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    updateCountDots();
}

