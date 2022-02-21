#include <QApplication>
#include <QPushButton>
#include "include/sudokuDisplay.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SudokuDisplayer s;
    s.setWindowTitle("Sudoku Game");
    s.show();
    return QApplication::exec();
}
