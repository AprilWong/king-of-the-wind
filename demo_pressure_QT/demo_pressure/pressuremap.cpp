#include "pressuremap.h"

float distance(QPoint p, QPoint q){
    return qSqrt( qPow(p.x() - q.x(), 2) + qPow(p.y() - q.y(), 2));
}

PressureMap::PressureMap()
{
    //init pressure map
    for(int i = 0; i < this->width; i ++) {
        QVector<float> line;
        QVector<QVector2D> lin;
        for(int j = 0; j < this->height; j ++) {
            line.append(basePressure);
            QVector2D di = QVector2D(0, 0);
            lin.append(di);
         }
        point.append(line);
        direction.append(lin);
    }
}

void PressureMap::update(){
    for(int i = 0; i < this->width; i ++) {
        for(int j = 0; j < this->height; j ++) {
            point[i][j] = basePressure;
            for (int k = 0; k < specialPoint.size(); k ++) {
                QPoint this_pos = QPoint(i, j);
                QPoint special_pos = QPoint(specialPoint[k].x(), specialPoint[k].y());
                point[i][j] = point[i][j] + (specialPoint[k].z() - basePressure) / (distance(this_pos, special_pos) * distanceScale + 1);
            }
        }
    }
}

void PressureMap::addSpecialPoint(QPoint pos, int value){
    QVector3D spoint = QVector3D(pos.x(), pos.y(), value);
    specialPoint.append(spoint);
    update();
}

void PressureMap::getDirection(){
    for(int i = 0; i < this->width; i ++) {
        for(int j = 0; j < this->height; j ++) {
            QVector2D di;
            if(i == 0) {
                di.setX(2 * (point[i + 1][j] -point[i][j]));
            }
            else{
                if(i == this->width - 1) {
                    di.setX(2 * (point[i][j] - point[i - 1][j]));
                }
                else {
                    di.setX(point[i + 1][j] - point[i -1][j]);
                }
            }

            if(j == 0) {
                di.setY(2 * (point[i][j + 1] - point[i][j]));
            }
            else{
                if(j == this->height - 1) {
                    di.setY(2 * (point[i][j] - point[i][j - 1]));
                }
                else{
                    di.setY(point[i][j + 1] - point[i][j - 1]);
                }
            }

            di.normalize();
            direction[i][j].setX(di.x());
            direction[i][j].setY(di.y());
        }
    }
}

void PressureMap::reset(){
    for(int i = 0; i < this->width; i ++) {
        for(int j = 0; j < this->height; j ++) {
            this->point[i][j] = basePressure;
            this->direction[i][j].setX(0);
            this->direction[i][j].setY(0);
         }
    }
}
