#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
<<<<<<< HEAD
=======
#include "registerwindow.h"
>>>>>>> origin/CinemaProject

Loginwindow::Loginwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Loginwindow)
{
    ui->setupUi(this);
}

Loginwindow::~Loginwindow()
{
    delete ui;
}



void Loginwindow::on_pushButtonLogin_clicked()
{
    hide();
<<<<<<< HEAD
    WelcomeWindow* welcomewindow = new WelcomeWindow(this);
    welcomewindow->show();
}

=======
    WelcomeWindow* welcomewindow=new WelcomeWindow(this);
    welcomewindow->show();
}


void Loginwindow::on_pushButtonRegister_clicked()
{
    hide();
    RegisterWindow* registerwindow=new RegisterWindow(this);
    registerwindow->show();

}

>>>>>>> origin/CinemaProject
