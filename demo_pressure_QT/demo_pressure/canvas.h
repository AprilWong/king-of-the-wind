#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QMouseEvent>
#include <QVector2D>
#include <QVector3D>
#include <QDebug>
#include <QPainter>
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
    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

private slots:
    void on_Add_clicked();

private:
    Ui::Canvas *ui;
    PressureMap *pressureMap;
    void setAddPointUiDisabled(bool flag);
    QPainter *paint;
    QPoint mouse;
    bool mouseShow;
    void paintEvent(QPaintEvent *);
    bool isValideClick(QPoint click);
};

#endif // CANVAS_H
