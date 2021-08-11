//
// Created by Paulina Gacek on 09.08.2021.
//

#ifndef SUDOKUQT_SUDOKUDISPLAY_H
#define SUDOKUQT_SUDOKUDISPLAY_H

#include <QWidget>
#include <QKeyEvent>
#include <QDialog>
#include <QPainter>
#include <thread>
#include <ctime>
#include "SudokuGenerator.h"


QT_BEGIN_NAMESPACE
namespace Ui { class SudokuDisplayer; }
QT_END_NAMESPACE

class SudokuDisplayer : public QWidget {
Q_OBJECT

public:
    explicit SudokuDisplayer(QWidget *parent = nullptr);

    ~SudokuDisplayer() override;

protected:
    void paintEvent(QPaintEvent *) override;
    void timerEvent(QTimerEvent *) override;
private:
    int timerId = 0;
    bool button_pushed = false;
    bool display_solution = false;
    Ui::SudokuDisplayer *ui;
    QImage blank,_1,_2,_3,_4,_5,_6,_7,_8,_9,plus,minus;
    QImage images[10] = {blank,_1,_2,_3,_4,_5,_6,_7,_8,_9};
    const char* level[6] = {"Too easy", "Easy peasy", "Easy", "Medium", "Hard", "Hard as hell"};
    size_t current_level = 2;
    SudokuGenerator new_sudoku_grid;
    void load_images();
    void display_grid();
    void display_empty_grid();
private slots:
    void on_pushButton_clicked();
    void on_pushButtonSolve_clicked();
    void on_pushButtonPlus_clicked();
    void on_pushButtonMinus_clicked();
};

#endif //SUDOKUQT_SUDOKUDISPLAY_H
