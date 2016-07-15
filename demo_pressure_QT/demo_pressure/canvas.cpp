#include "canvas.h"
#include "ui_canvas.h"

float hue2rgb(float p, float q, float t) {
    if (t < 0)
        t = t + 1;
    if (t > 1)
        t = t - 1;
    if (t < 1.0/6)
        return p + (q - p) * 6 * t;
    if (t < 1.0/2)
        return q;
    if (t < 2.0/3)
        return p + (q - p) * (2.0/3 - t) * 6;
    return p;
}

QVector3D hsl2rgb(float h, float s, float l) {
    h = h / 360;
    s = s / 100;
    l = l / 100;
    float r,g,b,p,q;
    r = g = b = l;
    if (s == 0)
        r = g = b = l;
    else{
        q = l < 0.5?l * (1 + s):l + s - l * s;
        p = 2 * l - q;
        r = hue2rgb(p, q, h + 1.0/3);
        g = hue2rgb(p, q, h);
        b = hue2rgb(p, q, h - 1.0/3);
    }
    QVector3D result;
    result.setX(r);
    result.setY(g);
    result.setZ(b);
    return result;
}

Canvas::Canvas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Canvas) {
    ui->setupUi(this);

    this->isIsobars = false;

    this->setAddPointUiDisabled(true);
    this->ui->PressureValue->setMaximum(300);
    this->ui->PressureValue->setMinimum(0);
    this->ui->PressureValue->setValue(150);

    this->ui->DrawWind->setDisabled(true);
    this->ui->ScaleValue->setMaximum(100);
    this->ui->ScaleValue->setMinimum(0);
    this->ui->ScaleValue->setValue(50);

    qDebug("here is the log message");

    pressureMap = new PressureMap;
    mouseShow = false;
    paintPressureMap();

}

void Canvas::paintPressureMap(){
    map = new QPixmap(this->pressureMap->width, this->pressureMap->height);
    QPainter paint(map);

    for (int i = 0; i < this->pressureMap->width; i ++) {
        for (int j = 0; j < this->pressureMap->height; j ++) {
            float value = int(this->pressureMap->point[i][j]);
            if(this->isIsobars) value = (ceil(value / 10)) * 10;
            QVector3D color = hsl2rgb(value, 100, 50);
            paint.setPen(QPen(QColor(color.x() * 255, color.y() * 255, color.z() * 255), 2));
            paint.drawEllipse(QPoint(i, j), 1, 1);
        }
    }

    if(this->mouseShow){
        paint.setPen(QPen(QColor(255,0,0),2));
        paint.drawEllipse(this->mouse,3,3);
    }

    if(isPaintWind){
        for(int i = 10; i < this->pressureMap->width; i = i + 10){
            for(int j = 10; j < this->pressureMap->height; j = j + 10 ) {
                drawWind(&paint, QVector2D(i, j), this->pressureMap->direction[i][j]);
            }
        }
    }

    this->ui->PressureMap->setPixmap(*map);
    this->ui->PressureMap->show();
}

void Canvas::paintDirectionMap(){
    map = new QPixmap(this->pressureMap->width, this->pressureMap->height);
    QPainter paint(map);


    for (int i = 0; i < this->pressureMap->width; i ++) {
        for (int j = 0; j < this->pressureMap->height; j ++) {
            QVector2D value = this->pressureMap->direction[i][j];
            QVector3D color;
            color.setX(value.x() / 2 + 0.5);
            color.setY(value.y() / 2 + 0.5);
            paint.setPen(QPen(QColor(color.x() * 255, color.y() * 255, 255), 2));
            paint.drawEllipse(QPoint(i, j), 1, 1);
        }
    }

    this->ui->DirectionMap->setPixmap(*map);
    this->ui->DirectionMap->show();
}

void Canvas::drawWind(QPainter *paint, QVector2D pos, QVector2D dirct){
    paint->setPen(QPen(QColor(255, 255, 255), 2));

    float angle = qAtan2(dirct.y(), dirct.x());

    paint->translate(pos.x(), pos.y());
    paint->rotate(angle / 3.14 * 180);

    QPainterPath textPath;
    QFont timesFont("Times", 5);
    timesFont.setStyleStrategy(QFont::ForceOutline);
    textPath.addText(0, 0, timesFont, tr("-->"));

    paint->drawPath(textPath);
    paint->resetTransform();
}


Canvas::~Canvas() {
    delete ui;
}

void Canvas::setAddPointUiDisabled(bool flag) {
    this->ui->Add->setDisabled(flag);
    this->ui->PressureValue->setDisabled(flag);
}

bool Canvas::isValideClick(QPoint click) {
    if((click.x() > this->pressureMap->left) &&
       (click.x() < (this->pressureMap->left + this->pressureMap->width)) &&
       (click.y() > this->pressureMap->up) &&
       (click.y() < (this->pressureMap->up + this->pressureMap->height)))
        return true;
    else
        return false;
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if(event->button() == Qt::LeftButton && this->isValideClick(event->pos())) {
        this->setAddPointUiDisabled(false);
        this->mouse.setX(event->pos().x() - this->pressureMap->left);
        this->mouse.setY(event->pos().y() - this->pressureMap->up);
        this->mouseShow = true;
        this->ui->DrawWind->setDisabled(true);
        this->isPaintWind = false;
        paintPressureMap();
    }
}


void Canvas::on_Add_clicked()
{
    this->pressureMap->addSpecialPoint(this->mouse, this->ui->PressureValue->value());
    this->mouseShow = false;
    this->setAddPointUiDisabled(true);
    this->ui->DrawWind->setDisabled(true);
    this->isPaintWind = false;
    paintPressureMap();
}

void Canvas::on_Isobars_toggled(bool checked)
{
    this->isIsobars = checked;
    paintPressureMap();
}


void Canvas::on_DistanceScale_clicked()
{
    this->pressureMap->distanceScale = float(this->ui->ScaleValue->value()) / 1000;
    this->pressureMap->update();
    paintPressureMap();
    this->ui->DrawWind->setDisabled(true);
    this->isPaintWind = false;
}

void Canvas::on_DrawDirection_clicked()
{
    this->pressureMap->getDirection();
    paintDirectionMap();
    this->ui->DrawWind->setDisabled(false);
}

void Canvas::on_DrawWind_clicked()
{
    isPaintWind = true;
    paintPressureMap();
}

void Canvas::on_Reset_clicked()
{
    this->pressureMap->reset();
    this->ui->DrawWind->setDisabled(true);
    this->isPaintWind = false;
    this->setAddPointUiDisabled(true);
    paintPressureMap();
}
