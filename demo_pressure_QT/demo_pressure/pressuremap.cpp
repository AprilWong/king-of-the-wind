#include "pressuremap.h"

PressureMap::PressureMap()
{
    //init pressure map
    for(int i = 0; i < this->width; i ++) {
        QVector<float> line;
        for(int j = 0; j < this->height; j ++) {
            line.append(basePressure);
         }
        point.append(line);
    }
}

void PressureMap::addSpecialPoint(QPoint pos, int value){
    for(int i = 0; i < this->width; i ++) {
        for(int j = 0; j < this->height; j ++) {

        }
    }
}
