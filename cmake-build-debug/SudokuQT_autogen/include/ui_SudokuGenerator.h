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

class Ui_SudokuDisplayer
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButtonSolve;
    QPushButton *pushButtonPlus;
    QPushButton *pushButtonMinus;

    void setupUi(QWidget *SudokuDisplayer)
    {
        if (SudokuDisplayer->objectName().isEmpty())
            SudokuDisplayer->setObjectName(QString::fromUtf8("SudokuDisplayer"));
        SudokuDisplayer->resize(475, 520);
        centralwidget = new QWidget(SudokuDisplayer);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(115, 50, 200, 30));
        QFont font;
        font.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font.setPointSize(11);
        font.setBold(true);
        pushButton->setFont(font);
        pushButton->setIconSize(QSize(25, 25));
        pushButton->setAutoDefault(true);
        pushButtonSolve = new QPushButton(SudokuDisplayer);
        pushButtonSolve->setObjectName(QString::fromUtf8("pushButtonSolve"));
        pushButtonSolve->setGeometry(QRect(130, 450, 170, 30));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font1.setPointSize(12);
        font1.setBold(true);
        pushButtonSolve->setFont(font1);
        pushButtonSolve->setIconSize(QSize(25, 25));
        pushButtonSolve->setAutoDefault(true);
        pushButtonPlus = new QPushButton(SudokuDisplayer);
        pushButtonPlus->setObjectName(QString::fromUtf8("pushButtonPlus"));
        pushButtonPlus->setGeometry(QRect(395, 222, 30, 30));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font2.setPointSize(20);
        font2.setBold(true);
        pushButtonPlus->setFont(font2);
        pushButtonPlus->setIconSize(QSize(35, 35));
        pushButtonPlus->setAutoDefault(true);
        pushButtonMinus = new QPushButton(SudokuDisplayer);
        pushButtonMinus->setObjectName(QString::fromUtf8("pushButtonMinus"));
        pushButtonMinus->setGeometry(QRect(395, 288, 30, 30));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Bookman Old Style")});
        font3.setPointSize(25);
        font3.setBold(true);
        pushButtonMinus->setFont(font3);
        pushButtonMinus->setIconSize(QSize(35, 35));
        pushButtonMinus->setAutoDefault(true);

        retranslateUi(SudokuDisplayer);

        QMetaObject::connectSlotsByName(SudokuDisplayer);
    } // setupUi

    void retranslateUi(QWidget *SudokuDisplayer)
    {
        SudokuDisplayer->setWindowTitle(QCoreApplication::translate("SudokuDisplayer", "SudokuDisplayer", nullptr));
        pushButton->setText(QCoreApplication::translate("SudokuDisplayer", "Generate new sudoku", nullptr));
        pushButtonSolve->setText(QCoreApplication::translate("SudokuDisplayer", "Show solution", nullptr));
        pushButtonPlus->setText(QCoreApplication::translate("SudokuDisplayer", "+", nullptr));
        pushButtonMinus->setText(QCoreApplication::translate("SudokuDisplayer", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SudokuDisplayer: public Ui_SudokuDisplayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDOKUGENERATOR_H
