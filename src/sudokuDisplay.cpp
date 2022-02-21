#include <iostream>
#include "../include/sudokuDisplay.h"
#include "../include/ui_SudokuGenerator.h"

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
    images[0].load("../photos/Blank.jpg");
    images[1].load("../photos/1.png");
    images[2].load("../photos/2.png");
    images[3].load("../photos/3.png");
    images[4].load("../photos/4.png");
    images[5].load("../photos/5.png");
    images[6].load("../photos/6.png");
    images[7].load("../photos/7.png");
    images[8].load("../photos/8.png");
    images[9].load("../photos/9.png");
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
                    qp.drawImage(74 + j*30 + gap_x,130 + i*30 + gap_y,images[new_sudoku_grid.board[i][j]]);
                else
                    qp.drawImage(74 + j*30 + gap_x,130 + i*30 + gap_y,images[new_sudoku_grid.solved_board[i][j]]);
            }
        }
    QString hs = level[current_level];
    QColor color;
    qp.setPen(color.fromRgb(190,222,222));
    QFont font("Courier", 11, QFont::DemiBold);
    QFontMetrics fm(font);
    qp.setFont(font);
    size_t v = 0;
    if(current_level==0)
        v = 20;
    else if(current_level==1){
        font.setPointSize(9);
        v = 29;
    }
    else if(current_level==3)
        v = 5;
    qp.drawText(size_t(387 - v), 275, hs);
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
            qp.drawImage(65 + j*30 + gap_x,130 + i*30 + gap_y,blank);
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

void SudokuDisplayer::on_pushButtonPlus_clicked() {
    if(current_level==5)
        return;
    else{
        current_level++;
        new_sudoku_grid.set_new_missing_fields(current_level);
        new_sudoku_grid.generate_board();
        std::cout << "Current level: " << current_level << std::endl;
    }
}

void SudokuDisplayer::on_pushButtonMinus_clicked() {
    if(current_level==0)
        return;
    else{
        current_level--;
        new_sudoku_grid.set_new_missing_fields(current_level);
        new_sudoku_grid.generate_board();
        std::cout << "Current level: " << current_level << std::endl;
    }
}
