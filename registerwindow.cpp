#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "welcomewindow.h"
#include "Users.h"

RegisterWindow::RegisterWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
    ui->alreadywarning->setVisible(false);
    ui->fieldwarning->setVisible(false);
    ui->matchingwarning->setVisible(false);
    ui->agewarning->setVisible(false);
}

void RegisterWindow::reg()
{
    name=ui->usernameedit->text();
    password=ui->passwordedit->text();
    retypepass=ui->retypeedit->text();
    month=ui->monthcombo->currentText();
    day=ui->dayedit->text().toInt();
    year=ui->yearedit->text().toInt();
}

bool RegisterWindow::check_username()
{
    for (int i = 0; i < 100; i++) {
        if (name == usernames[i]) {
            return true;
        }
    }
    return false;
}

bool RegisterWindow::check_retype()
{
    for (int i=0; i<100; i++) {
        if (password==passwords[i]){
            return true;
        }
    }
    return false;
}

bool RegisterWindow::check_date()
{
    age=2024-year;
    if(age>12)
        return true;
    else
    {
        return false;
    }
}

bool RegisterWindow::all_check()
{
    if(check_date()&&check_retype()&&check_username()&&( ui->userradio->isChecked() || ui->adminradio->isChecked() )&& (ui->femaleradio->isChecked() || ui->maleradio->isChecked() ))
        return true;
    else
    {
        ui->alreadywarning->setVisible(true);
        ui->fieldwarning->setVisible(true);
        ui->matchingwarning->setVisible(true);
        ui->agewarning->setVisible(true);
        return false;
    }
}

void RegisterWindow::on_pushButton_clicked()
{
    if(all_check())
    {
        hide();
        userCount++;
        usernames[userCount]=name;
        passwords[userCount]=password;
        ages[userCount]=age;
        WelcomeWindow* welcomewindow = new WelcomeWindow(usernames[userCount],ages[userCount],this);
        welcomewindow->show();
    }

}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}



