#include "widget.h"
#include "ui_widget.h"
#include <QLCDNumber>
#include <cstdlib>
#include <ctime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString filename = "/home/ruben_pinto/Documents/Projects/EuroMilhoes/euromilhoes-logo.png";
    QImage image(filename);
    ui->label->setPixmap(QPixmap::fromImage(image));

}

Widget::~Widget()
{
    delete ui;
}



void Widget::displayLCD(int num[5], int est[2]){
    ui->lcdNumber->display(num[0]);
    ui->lcdNumber_2->display(num[1]);
    ui->lcdNumber_3->display(num[2]);
    ui->lcdNumber_4->display(num[3]);
    ui->lcdNumber_5->display(num[4]);
    ui->lcdNumber_6->display(est[0]);
    ui->lcdNumber_7->display(est[1]);
}


void Widget::on_pushButton_clicked()
{
    int num[5];
    int est[2];
    for(int i=0; i<5; i++){
        num[i] = 1 + rand() % 50;
    }

    for(int i=0; i<2; i++){
        est[i] = 1+ rand() % 12;
    }

    displayLCD(num, est);
}

