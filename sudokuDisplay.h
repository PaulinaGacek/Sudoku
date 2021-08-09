//
// Created by pauli on 09.08.2021.
//

#ifndef SUDOKUQT_SUDOKUDISPLAY_H
#define SUDOKUQT_SUDOKUDISPLAY_H

#include <QWidget>
#include <QKeyEvent>
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class SudokuGenerator; }
QT_END_NAMESPACE

class SudokuGenerator : public QDialog {
Q_OBJECT

public:
    explicit SudokuGenerator(QWidget *parent = nullptr);

    ~SudokuGenerator() override;

private:
    Ui::SudokuGenerator *ui;
private slots:
    void on_pushButton_clicked();
};

#endif //SUDOKUQT_SUDOKUDISPLAY_H
