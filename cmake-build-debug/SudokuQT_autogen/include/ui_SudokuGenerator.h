/********************************************************************************
** Form generated from reading UI file 'sudokugenerator.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDOKUGENERATOR_H
#define UI_SUDOKUGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SudokuGenerator
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;

    void setupUi(QWidget *SudokuGenerator)
    {
        if (SudokuGenerator->objectName().isEmpty())
            SudokuGenerator->setObjectName(QString::fromUtf8("SudokuGenerator"));
        SudokuGenerator->resize(400, 400);
        centralwidget = new QWidget(SudokuGenerator);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 50, 170, 51));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(10);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setIconSize(QSize(25, 25));
        pushButton->setAutoDefault(true);

        retranslateUi(SudokuGenerator);

        QMetaObject::connectSlotsByName(SudokuGenerator);
    } // setupUi

    void retranslateUi(QWidget *SudokuGenerator)
    {
        SudokuGenerator->setWindowTitle(QCoreApplication::translate("SudokuGenerator", "SudokuGenerator", nullptr));
        pushButton->setText(QCoreApplication::translate("SudokuGenerator", "Generate new sudoku", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SudokuGenerator: public Ui_SudokuGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUGENERATOR_H
