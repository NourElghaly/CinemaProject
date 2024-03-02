#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "welcomewindow.h"
#include "registerwindow.h"
#include "Users.h"
#include <QString>

Loginwindow::Loginwindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Loginwindow)
{
    ui->setupUi(this);
    ui->errormsg->setVisible(false);

}


Loginwindow::~Loginwindow()
{
    delete ui;
}


void Loginwindow::on_pushButtonLogin_clicked()
{
    name=ui->lineEditUsername->text();
    password=ui->lineEditPassword->text();
    bool isValid=false;
    int usernumber;

    for (int i=0; i<100; i++){
        if (name == usernames[i] && password == passwords [i])
         {
            isValid = true;
            usernumber=i;
            break;
         }
    }

    if(isValid){
        hide();
        WelcomeWindow* welcomewindow = new WelcomeWindow(usernames[usernumber],ages[usernumber],this);
        welcomewindow->show();
    }

    else{
        ui->errormsg->setVisible(true);
    }

}


void Loginwindow::on_pushButtonRegister_clicked()
{
    hide();
    RegisterWindow* registerwindow=new RegisterWindow(this);
    registerwindow->show();

}


