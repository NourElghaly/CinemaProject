#include "welcomewindow.h"
#include "ui_welcomewindow.h"
#include "loginwindow.h"
#include <QPixmap>


WelcomeWindow::WelcomeWindow(QString username, int age, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::WelcomeWindow)
{
    ui->setupUi(this);

    QPixmap pix ("C:/Users/Nour/Desktop/Cinema_Booking/AUC.jpg");
    ui->theaterimage->setPixmap(pix.scaled(500,500));
    QString str=QString::number(age);
    ui->namelabel->setText(username+" "+str);

}

WelcomeWindow::~WelcomeWindow()
{
    delete ui;
}

void WelcomeWindow::on_pushButton_clicked()
{
    hide();
    Loginwindow* loginwindow=new Loginwindow(this);
    loginwindow->show();
}

