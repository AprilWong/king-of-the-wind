#ifndef PRESSUREMAP_H
#define PRESSUREMAP_H

#include <QVector>
#include <QDebug>
#include <QVector3D>

class PressureMap
{
public:
    PressureMap();
    const int left = 50;
    const int up = 50;
    const int height = 256;
    const int width = 256;
    QVector<QVector<float> > point;
    QVector<QVector3D> specialPoint;
    float basePressure = 100;

    void addSpecialPoint(QPoint pos, int value);
private:

};

#endif // PRESSUREMAP_H
