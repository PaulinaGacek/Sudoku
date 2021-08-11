#include <iostream>
#include "sudokuDisplay.h"
#include "ui_SudokuGenerator.h"

SudokuDisplayer::SudokuDisplayer(QWidget *parent) :
        QWidget(parent), ui(new Ui::SudokuDisplayer) {
    ui->setupUi(this);
    setStyleSheet("background-color: rgb(0, 45, 45)");
    ui->pushButton->setStyleSheet("QPushButton { background-color: grey; }\n"
                                  "QPushButton:enabled { background-color: rgb(190,222,222); }\n");
    ui->pushButtonSolve->setStyleSheet("QPushButton { background-color: grey; }\n"
                                  "QPushButton:enabled { background-color: rgb(190,222,222); }\n");
    ui->pushButtonPlus->setStyleSheet("QPushButton { background-color: grey; }\n"
                                       "QPushButton:enabled { background-color: rgb(190,222,222); }\n");
    ui->pushButtonMinus->setStyleSheet("QPushButton { background-color: grey; }\n"
                                       "QPushButton:enabled { background-color: rgb(190,222,222); }\n");
    load_images();
    timerId = startTimer(500);
    display_empty_grid();
}

SudokuDisplayer::~SudokuDisplayer() {
    delete ui;
}
void SudokuDisplayer::on_pushButton_clicked()
{
    button_pushed = true;
    display_solution = false;
    new_sudoku_grid.generate_board();
}

void SudokuDisplayer::load_images() {
    images[0].load("Blank.jpg");
    images[1].load("1.png");
    images[2].load("2.png");
    images[3].load("3.png");
    images[4].load("4.png");
    images[5].load("5.png");
    images[6].load("6.png");
    images[7].load("7.png");
    images[8].load("8.png");
    images[9].load("9.png");
}

void SudokuDisplayer::display_grid() {
    QPainter qp(this);
        int gap_y = 0;
        for(int i = 0; i < 9; ++i){
            int gap_x = 0;
            if(i%3==0)
                gap_y += 3;
            for(int j = 0; j < 9; ++j){
                if(j%3==0)
                    gap_x += 3;
                if(!display_solution)
                    qp.drawImage(80 + j*30 + gap_x,130 + i*30 + gap_y,images[new_sudoku_grid.board[i][j]]);
                else
                    qp.drawImage(80 + j*30 + gap_x,130 + i*30 + gap_y,images[new_sudoku_grid.solved_board[i][j]]);
            }
        }
}

void SudokuDisplayer::paintEvent(QPaintEvent *e) {
    Q_UNUSED(e);
    display_grid();
}

void SudokuDisplayer::display_empty_grid() {
    QPainter qp(this);
    int gap_y = 0;
    for(int i = 0; i < 9; ++i){
        int gap_x = 0;
        if(i%3==0)
            gap_y += 3;
        for(int j = 0; j < 9; ++j){
            if(j%3==0)
                gap_x += 3;
            qp.drawImage(80 + j*30 + gap_x,130 + i*30 + gap_y,blank);
        }
    }
    repaint();
}

void SudokuDisplayer::timerEvent(QTimerEvent *e) {
    Q_UNUSED(e);
    repaint();
}

void SudokuDisplayer::on_pushButtonSolve_clicked() {
    display_solution = true;
}
