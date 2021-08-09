//
// Created by Paulina Gacek on 09.08.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_SudokuGenerator.h" resolved

#include "sudokuDisplay.h"
#include "ui_SudokuGenerator.h"

SudokuGenerator::SudokuGenerator(QWidget *parent) :
        QDialog(parent), ui(new Ui::SudokuGenerator) {
    ui->setupUi(this);
}

SudokuGenerator::~SudokuGenerator() {
    delete ui;
}
void SudokuGenerator::on_pushButton_clicked()
{
    //this->close();

}
