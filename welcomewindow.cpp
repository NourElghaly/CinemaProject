#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include <QPixmap>

WelcomeWindow::WelcomeWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

<<<<<<< HEAD
    QPixmap pix ("C:/Users/Nour/Desktop/Cinema_Booking/image.jpeg");
    if (pix.isNull()) {
        qDebug() << "Failed to load image";
    } else {
        ui->theaterimage->setPixmap(pix.scaled(200,200));
    }

=======
    QPixmap pix ("C:/Users/Nour/Desktop/Cinema_Booking/AUC.jpg");
    ui->theaterimage->setPixmap(pix.scaled(500,500));
>>>>>>> origin/CinemaProject
}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}


<<<<<<< HEAD
=======

>>>>>>> origin/CinemaProject
