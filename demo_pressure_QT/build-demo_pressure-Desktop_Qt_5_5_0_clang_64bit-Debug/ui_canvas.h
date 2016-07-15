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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Canvas
{
public:
    QPushButton *Add;
    QSlider *PressureValue;
    QLabel *PressureMap;
    QRadioButton *Isobars;
    QSlider *ScaleValue;
    QPushButton *DistanceScale;
    QLabel *DirectionMap;
    QPushButton *DrawDirection;
    QPushButton *DrawWind;
    QPushButton *Reset;
    QPushButton *Save;

    void setupUi(QWidget *Canvas)
    {
        if (Canvas->objectName().isEmpty())
            Canvas->setObjectName(QStringLiteral("Canvas"));
        Canvas->resize(662, 500);
        Add = new QPushButton(Canvas);
        Add->setObjectName(QStringLiteral("Add"));
        Add->setGeometry(QRect(230, 400, 75, 21));
        PressureValue = new QSlider(Canvas);
        PressureValue->setObjectName(QStringLiteral("PressureValue"));
        PressureValue->setGeometry(QRect(50, 400, 160, 19));
        PressureValue->setOrientation(Qt::Horizontal);
        PressureMap = new QLabel(Canvas);
        PressureMap->setObjectName(QStringLiteral("PressureMap"));
        PressureMap->setGeometry(QRect(50, 50, 256, 256));
        PressureMap->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        Isobars = new QRadioButton(Canvas);
        Isobars->setObjectName(QStringLiteral("Isobars"));
        Isobars->setGeometry(QRect(50, 460, 89, 16));
        ScaleValue = new QSlider(Canvas);
        ScaleValue->setObjectName(QStringLiteral("ScaleValue"));
        ScaleValue->setGeometry(QRect(50, 430, 160, 19));
        ScaleValue->setOrientation(Qt::Horizontal);
        DistanceScale = new QPushButton(Canvas);
        DistanceScale->setObjectName(QStringLiteral("DistanceScale"));
        DistanceScale->setGeometry(QRect(230, 430, 75, 21));
        DirectionMap = new QLabel(Canvas);
        DirectionMap->setObjectName(QStringLiteral("DirectionMap"));
        DirectionMap->setGeometry(QRect(356, 50, 256, 256));
        DirectionMap->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        DrawDirection = new QPushButton(Canvas);
        DrawDirection->setObjectName(QStringLiteral("DrawDirection"));
        DrawDirection->setGeometry(QRect(380, 410, 221, 21));
        DrawWind = new QPushButton(Canvas);
        DrawWind->setObjectName(QStringLiteral("DrawWind"));
        DrawWind->setGeometry(QRect(380, 450, 221, 21));
        Reset = new QPushButton(Canvas);
        Reset->setObjectName(QStringLiteral("Reset"));
        Reset->setGeometry(QRect(140, 460, 75, 21));
        Save = new QPushButton(Canvas);
        Save->setObjectName(QStringLiteral("Save"));
        Save->setGeometry(QRect(230, 460, 75, 21));

        retranslateUi(Canvas);

        QMetaObject::connectSlotsByName(Canvas);
    } // setupUi

    void retranslateUi(QWidget *Canvas)
    {
        Canvas->setWindowTitle(QApplication::translate("Canvas", "Canvas", 0));
        Add->setText(QApplication::translate("Canvas", "Add", 0));
        PressureMap->setText(QString());
        Isobars->setText(QApplication::translate("Canvas", "Isobars", 0));
        DistanceScale->setText(QApplication::translate("Canvas", "Scale", 0));
        DirectionMap->setText(QString());
        DrawDirection->setText(QApplication::translate("Canvas", "Generate Direction Map", 0));
        DrawWind->setText(QApplication::translate("Canvas", "Draw Wind", 0));
        Reset->setText(QApplication::translate("Canvas", "Reset", 0));
        Save->setText(QApplication::translate("Canvas", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class Canvas: public Ui_Canvas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CANVAS_H
