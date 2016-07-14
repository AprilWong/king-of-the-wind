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

    this->ui->Add->setDisabled(true);
    this->ui->PressureValue->setDisabled(true);
    this->ui->PressureValue->setValidator(new QIntValidator(0, 100, this));
    qDebug("here is the log message");

    pressureMap = new PressureMap;
    mouseShow = false;
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
        this->mouse = event->pos();
        this->mouseShow = true;
        repaint();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    //=============
    //=============
    //=============
    if (this->isValideClick(event->pos())){
        qDebug("%.2f, %.2f", event->pos().x(), event->pos().y());
    }
}

void Canvas::paintEvent(QPaintEvent *) {
    paint = new QPainter;

    //draw texture outsider
    paint->begin(this);

    //draw texture
    for (int i = 0; i < this->pressureMap->width; i ++) {
        for (int j = 0; j < this->pressureMap->height; j ++) {
            QVector3D color = hsl2rgb(this->pressureMap->point[i][j], 100, 50);
            paint->setPen(QPen(QColor(color.x() * 255, color.y() * 255, color.z() * 255), 2));
            paint->drawEllipse(QPoint(this->pressureMap->left + i, this->pressureMap->up + j), 1, 1);
        }
    }

    if(this->mouseShow){
        paint->setPen(QPen(QColor(255,0,0),2));
        paint->drawEllipse(mouse,3,3);
    }

    paint->~QPainter();
}


void Canvas::on_Add_clicked()
{
    this->pressureMap->addSpecialPoint(this->mouse, this->ui->PressureValue->text().toInt());
    this->mouseShow = false;
    this->setAddPointUiDisabled(true);
    repaint();
}
