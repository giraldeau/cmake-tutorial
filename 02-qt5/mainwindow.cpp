#include <QLabel>
#include <QLayout>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
   QMainWindow(parent),
   ui(new Ui::MainWindow)
{
   ui->setupUi(this);
}

MainWindow::~MainWindow()
{
   delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   ui->label->setText("42");
   QPixmap image;
   QGraphicsScene *scene = new QGraphicsScene(this);
   image.load(":/images/cat.png");
   QPixmap image2 = image.scaled(ui->graphicsView->size() * 0.9, Qt::KeepAspectRatio);


   scene->addPixmap(image2);
   scene->setSceneRect(image2.rect());
   ui->graphicsView->setScene(scene);
}
