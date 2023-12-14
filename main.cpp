#include <QApplication>
#include "CWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    CWidget widget;
    widget.show();
    return app.exec();
}
