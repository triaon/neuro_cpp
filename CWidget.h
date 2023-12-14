#ifndef CWIDGET_H
#define CWIDGET_H

#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include <QLabel>
#include <vector>

using std::vector;

class CWidget : public QWidget {
Q_OBJECT
public:
     CWidget(QWidget *parent = nullptr); // Node for widget
     QSize minimumSizeHint() const override;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;

private slots:
    void onSubmitClicked();

private:
    QLabel *countLabel;
    QPushButton *submitButton;
    vector<vector<int>> matrix; // input matrix for neuro
    int dotCounter; // counter of 1's dots
    void updateCountDots();
    void togglePixel(int x, int y);
};

#endif
