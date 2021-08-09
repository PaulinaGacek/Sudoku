#include <QApplication>
#include <QPushButton>
#include "sudokuDisplay.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    SudokuGenerator s;
    s.setWindowTitle("Sudoku Game");
    s.show();
    return QApplication::exec();
}
