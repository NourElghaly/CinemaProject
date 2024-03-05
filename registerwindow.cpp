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

bool RegisterWindow::genere_check()
{
    if(ui->actioncheck->isChecked()||ui->comedycheck->isChecked()||ui->dramacheck->isChecked()||ui->horrorcheck->isChecked()||ui->romancecheck->isChecked()||ui->othercheck->isChecked())
              return true;
    else
        return false;

}

bool RegisterWindow::check_username()
{
    name=ui->usernameedit->text();
    if (ui->usernameedit->text().isEmpty())
       ui->alreadywarning->setVisible(false);
    else
    for (int i = 0; i < 100; i++) {
        if (name == usernames[i]) {
            ui->alreadywarning->setVisible(true);
            return false;
        }
    }
    ui->alreadywarning->setVisible(false);
    return true;

}

bool RegisterWindow::check_retype()
{
    password=ui->passwordedit->text();
    retypepass=ui->retypeedit->text();
        if (password==retypepass){
            ui->matchingwarning->setVisible(false);
            return true;}
        else
        {
    ui->matchingwarning->setVisible(true);
    return false;
        }
};

bool RegisterWindow::check_date()
{
    year=ui->yearedit->text().toInt();
    age=2024-year;
    if(age>12){
        ui->agewarning->setVisible(false);
        return true;
    }
    else
    {
        ui->agewarning->setVisible(true);
        return false;
    }
}

bool RegisterWindow::all_check()
{
    if(check_date()&&check_retype()&&check_username()&&genere_check()&&(ui->userradio->isChecked() || ui->adminradio->isChecked() )&& (ui->femaleradio->isChecked() || ui->maleradio->isChecked() ))
        return true;
    else
    {
        ui->fieldwarning->setVisible(true);
        return false;
    }
}

void RegisterWindow::on_pushButton_clicked()
{

    RegisterWindow::all_check();
    RegisterWindow::check_username();
    RegisterWindow::check_retype();
    RegisterWindow::check_date();

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



