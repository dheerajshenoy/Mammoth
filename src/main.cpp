#include "mammoth.hpp"

int main (int argc, char *argv[]) {
    QApplication app(argc, argv);
    Mammoth m;
    m.show();
    app.exec();
}
