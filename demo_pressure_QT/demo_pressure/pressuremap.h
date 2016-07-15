#ifndef PRESSUREMAP_H
#define PRESSUREMAP_H

#include <QVector>
#include <QDebug>
#include <QVector3D>
#include <QVector2D>
#include <qmath.h>

class PressureMap
{
public:
    PressureMap();
    const int left = 50;
    const int up = 50;
    const int height = 256;
    const int width = 256;
    QVector<QVector<float> > point;
    QVector<QVector<QVector2D> > direction;
    QVector<QVector3D> specialPoint;
    float basePressure = 150;
    float distanceScale = 0.05;

    void addSpecialPoint(QPoint pos, int value);
    void update();
    void getDirection();
    void reset();
private:

};

#endif // PRESSUREMAP_H
