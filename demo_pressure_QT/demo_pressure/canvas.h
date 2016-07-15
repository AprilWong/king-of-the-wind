#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <QVector2D>
#include <QVector3D>
#include <QDebug>
#include <QPainter>
#include <QImage>
#include <QPixmap>
#include <QPainterPath>
#include <QFont>
#include <QLinearGradient>
#include <qmath.h>

#include "pressuremap.h"

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = 0);
    ~Canvas();

protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_Add_clicked();

    void on_Isobars_toggled(bool checked);

    void on_DistanceScale_clicked();

    void on_DrawDirection_clicked();

    void on_DrawWind_clicked();

    void on_Reset_clicked();

private:
    Ui::Canvas *ui;
    PressureMap *pressureMap;
    void setAddPointUiDisabled(bool flag);
    QPixmap *map;
    QPainter *paint;
    QPoint mouse;
    bool mouseShow;
    bool isValideClick(QPoint click);
    bool isPaintWind;
    bool isIsobars;
    void paintPressureMap();
    void paintDirectionMap();
    void drawWind(QPainter *paint, QVector2D pos, QVector2D direct);
};

#endif // CANVAS_H
