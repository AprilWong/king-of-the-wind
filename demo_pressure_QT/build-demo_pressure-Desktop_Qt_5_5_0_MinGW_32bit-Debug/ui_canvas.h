/********************************************************************************
** Form generated from reading UI file 'canvas.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CANVAS_H
#define UI_CANVAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Canvas
{
public:
    QWidget *TextureMap;
    QLineEdit *PressureValue;
    QPushButton *Add;
    QLabel *label;
    QLabel *PressureShow;

    void setupUi(QWidget *Canvas)
    {
        if (Canvas->objectName().isEmpty())
            Canvas->setObjectName(QStringLiteral("Canvas"));
        Canvas->resize(653, 400);
        TextureMap = new QWidget(Canvas);
        TextureMap->setObjectName(QStringLiteral("TextureMap"));
        TextureMap->setGeometry(QRect(50, 50, 256, 256));
        TextureMap->setMouseTracking(false);
        PressureValue = new QLineEdit(Canvas);
        PressureValue->setObjectName(QStringLiteral("PressureValue"));
        PressureValue->setGeometry(QRect(410, 50, 113, 20));
        Add = new QPushButton(Canvas);
        Add->setObjectName(QStringLiteral("Add"));
        Add->setGeometry(QRect(540, 50, 75, 23));
        label = new QLabel(Canvas);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(410, 290, 91, 16));
        PressureShow = new QLabel(Canvas);
        PressureShow->setObjectName(QStringLiteral("PressureShow"));
        PressureShow->setGeometry(QRect(420, 290, 54, 12));

        retranslateUi(Canvas);

        QMetaObject::connectSlotsByName(Canvas);
    } // setupUi

    void retranslateUi(QWidget *Canvas)
    {
        Canvas->setWindowTitle(QApplication::translate("Canvas", "Canvas", 0));
        Add->setText(QApplication::translate("Canvas", "Add", 0));
        label->setText(QApplication::translate("Canvas", "\351\200\211\344\270\255\347\202\271\347\232\204\346\260\224\345\216\213\345\200\274", 0));
        PressureShow->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Canvas: public Ui_Canvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
